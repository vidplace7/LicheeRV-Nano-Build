// SPDX-License-Identifier: GPL-2.0
/*
 * ION Memory Allocator generic heap helpers
 *
 * Copyright (C) 2011 Google, Inc.
 */

#include <linux/err.h>
#include <linux/freezer.h>
#include <linux/kthread.h>
#include <linux/mm.h>
#include <linux/rtmutex.h>
#include <linux/sched.h>
#include <uapi/linux/sched/types.h>
#include <linux/scatterlist.h>
#include <linux/vmalloc.h>
#include "ion.h"
#include <linux/io.h>

void *ion_heap_map_kernel(struct ion_heap *heap,
			  struct ion_buffer *buffer)
{
	void *vaddr;

#if defined(CONFIG_ARM) || defined(__arm__) || defined(__aarch64__)
	struct sg_page_iter piter;
	pgprot_t pgprot;
	struct sg_table *table = buffer->sg_table;
	int npages = PAGE_ALIGN(buffer->size) / PAGE_SIZE;
	struct page **pages = vmalloc(array_size(npages,
						 sizeof(struct page *)));
	struct page **tmp = pages;

	if (!pages)
		return ERR_PTR(-ENOMEM);

	if (buffer->flags & ION_FLAG_CACHED)
		pgprot = PAGE_KERNEL;
	else
		pgprot = pgprot_writecombine(PAGE_KERNEL);

	for_each_sgtable_page(table, &piter, 0) {
		BUG_ON(tmp - pages >= npages);
		*tmp++ = sg_page_iter_page(&piter);
	}

	vaddr = vmap(pages, npages, VM_MAP, pgprot);
	vfree(pages);

	if (!vaddr)
		return ERR_PTR(-ENOMEM);

#else

	pr_debug("ion_heap_map_kernel addr=0x%llx, size=%lu\n", buffer->paddr, PAGE_ALIGN(buffer->size));

	if (buffer->flags & ION_FLAG_CACHED)
		vaddr = memremap(buffer->paddr, PAGE_ALIGN(buffer->size), MEMREMAP_WB);
	else
		vaddr = ioremap(buffer->paddr, PAGE_ALIGN(buffer->size));

	if (!vaddr) {
		pr_err("ion_heap_map_kernel map failed\n");
		return ERR_PTR(-ENOMEM);
	}

#endif
	return vaddr;
}

void ion_heap_unmap_kernel(struct ion_heap *heap,
			   struct ion_buffer *buffer)
{
	if (buffer->flags & ION_FLAG_CACHED)
		memunmap(buffer->vaddr);
	else
		iounmap(buffer->vaddr);
}

int ion_heap_map_user(struct ion_heap *heap, struct ion_buffer *buffer,
		      struct vm_area_struct *vma)
{
	struct sg_page_iter piter;
	struct sg_table *table = buffer->sg_table;
	unsigned long addr = vma->vm_start;
	int ret;

	for_each_sgtable_page(table, &piter, vma->vm_pgoff) {
		struct page *page = sg_page_iter_page(&piter);

		ret = remap_pfn_range(vma, addr, page_to_pfn(page), PAGE_SIZE,
				      vma->vm_page_prot);
		if (ret)
			return ret;
		addr += PAGE_SIZE;
		if (addr >= vma->vm_end)
			return 0;
	}

	return 0;
}

static int ion_heap_clear_pages(struct page **pages, int num, pgprot_t pgprot)
{
	void *addr = vmap(pages, num, VM_MAP, pgprot);

	if (!addr)
		return -ENOMEM;
	memset(addr, 0, PAGE_SIZE * num);
	vunmap(addr);

	return 0;
}

static int ion_heap_sglist_zero(struct sg_table *sgt, pgprot_t pgprot)
{
	int p = 0;
	int ret = 0;
	struct sg_page_iter piter;
	struct page *pages[32];

	for_each_sgtable_page(sgt, &piter, 0) {
		pages[p++] = sg_page_iter_page(&piter);
		if (p == ARRAY_SIZE(pages)) {
			ret = ion_heap_clear_pages(pages, p, pgprot);
			if (ret)
				return ret;
			p = 0;
		}
	}
	if (p)
		ret = ion_heap_clear_pages(pages, p, pgprot);

	return ret;
}

int ion_heap_buffer_zero(struct ion_buffer *buffer)
{
	struct sg_table *table = buffer->sg_table;
	pgprot_t pgprot;

	if (buffer->flags & ION_FLAG_CACHED)
		pgprot = PAGE_KERNEL;
	else
		pgprot = pgprot_writecombine(PAGE_KERNEL);

	return ion_heap_sglist_zero(table, pgprot);
}

int ion_heap_pages_zero(struct page *page, size_t size, pgprot_t pgprot)
{
	struct scatterlist sg;
	struct sg_table sgt;

	sg_init_table(&sg, 1);
	sg_set_page(&sg, page, size, 0);

	sgt.sgl = &sg;
	sgt.nents = 1;
	sgt.orig_nents = 1;

	return ion_heap_sglist_zero(&sgt, pgprot);
}

void ion_heap_freelist_add(struct ion_heap *heap, struct ion_buffer *buffer)
{
	spin_lock(&heap->free_lock);
	list_add(&buffer->list, &heap->free_list);
	heap->free_list_size += buffer->size;
	spin_unlock(&heap->free_lock);
	wake_up(&heap->waitqueue);
}

size_t ion_heap_freelist_size(struct ion_heap *heap)
{
	size_t size;

	spin_lock(&heap->free_lock);
	size = heap->free_list_size;
	spin_unlock(&heap->free_lock);

	return size;
}

static size_t _ion_heap_freelist_drain(struct ion_heap *heap, size_t size,
				       bool skip_pools)
{
	struct ion_buffer *buffer;
	size_t total_drained = 0;

	if (ion_heap_freelist_size(heap) == 0)
		return 0;

	spin_lock(&heap->free_lock);
	if (size == 0)
		size = heap->free_list_size;

	while (!list_empty(&heap->free_list)) {
		if (total_drained >= size)
			break;
		buffer = list_first_entry(&heap->free_list, struct ion_buffer,
					  list);
		list_del(&buffer->list);
		heap->free_list_size -= buffer->size;
		if (skip_pools)
			buffer->private_flags |= ION_PRIV_FLAG_SHRINKER_FREE;
		total_drained += buffer->size;
		spin_unlock(&heap->free_lock);
		ion_buffer_destroy(buffer);
		spin_lock(&heap->free_lock);
	}
	spin_unlock(&heap->free_lock);

	return total_drained;
}

size_t ion_heap_freelist_drain(struct ion_heap *heap, size_t size)
{
	return _ion_heap_freelist_drain(heap, size, false);
}

size_t ion_heap_freelist_shrink(struct ion_heap *heap, size_t size)
{
	return _ion_heap_freelist_drain(heap, size, true);
}

static int ion_heap_deferred_free(void *data)
{
	struct ion_heap *heap = data;

	while (true) {
		struct ion_buffer *buffer;

		wait_event_freezable(heap->waitqueue,
				     ion_heap_freelist_size(heap) > 0);

		spin_lock(&heap->free_lock);
		if (list_empty(&heap->free_list)) {
			spin_unlock(&heap->free_lock);
			continue;
		}
		buffer = list_first_entry(&heap->free_list, struct ion_buffer,
					  list);
		list_del(&buffer->list);
		heap->free_list_size -= buffer->size;
		spin_unlock(&heap->free_lock);
		ion_buffer_destroy(buffer);
	}

	return 0;
}

int ion_heap_init_deferred_free(struct ion_heap *heap)
{
	INIT_LIST_HEAD(&heap->free_list);
	init_waitqueue_head(&heap->waitqueue);
	heap->task = kthread_run(ion_heap_deferred_free, heap,
				 "%s", heap->name);
	if (IS_ERR(heap->task)) {
		pr_err("%s: creating thread for deferred free failed\n",
		       __func__);
		return PTR_ERR_OR_ZERO(heap->task);
	}
	sched_set_normal(heap->task, 19);

	return 0;
}

static unsigned long ion_heap_shrink_count(struct shrinker *shrinker,
					   struct shrink_control *sc)
{
	struct ion_heap *heap = container_of(shrinker, struct ion_heap,
					     shrinker);
	int total = 0;

	total = ion_heap_freelist_size(heap) / PAGE_SIZE;

	if (heap->ops->shrink)
		total += heap->ops->shrink(heap, sc->gfp_mask, 0);

	return total;
}

static unsigned long ion_heap_shrink_scan(struct shrinker *shrinker,
					  struct shrink_control *sc)
{
	struct ion_heap *heap = container_of(shrinker, struct ion_heap,
					     shrinker);
	int freed = 0;
	int to_scan = sc->nr_to_scan;

	if (to_scan == 0)
		return 0;

	/*
	 * shrink the free list first, no point in zeroing the memory if we're
	 * just going to reclaim it. Also, skip any possible page pooling.
	 */
	if (heap->flags & ION_HEAP_FLAG_DEFER_FREE)
		freed = ion_heap_freelist_shrink(heap, to_scan * PAGE_SIZE) /
				PAGE_SIZE;

	to_scan -= freed;
	if (to_scan <= 0)
		return freed;

	if (heap->ops->shrink)
		freed += heap->ops->shrink(heap, sc->gfp_mask, to_scan);

	return freed;
}

int ion_heap_init_shrinker(struct ion_heap *heap)
{
	heap->shrinker.count_objects = ion_heap_shrink_count;
	heap->shrinker.scan_objects = ion_heap_shrink_scan;
	heap->shrinker.seeks = DEFAULT_SEEKS;
	heap->shrinker.batch = 0;

	return register_shrinker(&heap->shrinker);
}
