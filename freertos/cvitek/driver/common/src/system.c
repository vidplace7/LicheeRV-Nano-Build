#ifdef __riscv
#include <stdio.h>
#include <string.h>
#include "uart.h"
#include "top_reg.h"
#include "FreeRTOS.h"
#include "intr_conf.h"
#include "irq.h"
#include "csr.h"
#include "mmio.h"
#include "fast_image.h"
#include "rtos_cmdqu.h"
#include "cvi_mailbox.h"
#include "memmap.h"
#else
//#include <stdint.h>
#include <string.h>
#include "pinmux.h"
#include "uart.h"
#include "i2c.h"
#include "top_reg.h"
#include "FreeRTOS.h"
#include "xscugic.h"
#include "intr_conf.h"
#include "linux/platform_device.h"
#include "linux/kernel.h"
#include "vcodec_source.h"
#include "vip_source.h"

struct platform_device *cvitek_devices[] __initdata = {
	&cif_platform_device,
	&vip_platform_device,
	&vcodec_platform_device,
};

struct device_node *cvitek_device_node[] __initdata = {
	&cif_device_node,
	&vip_device_node,
	&vcode_device_node,
};

struct reserved_mem *cvitek_reserved_mem[] __initdata = {
	&vip_reserved_mem,
	&vcode_reserved_mem,
};
#endif

void GetCommInfo(void);
struct transfer_config_t transfer_config;

void pre_system_init(void)
{
	pinmux_init();
	uart_init();
	irq_init();
	printf("Pre system init done\n");
}

void post_system_init(void)
{
#ifdef __riscv

#else
	i2c_init(I2C3);
	/* init platform device */
	rtos_init_platform_device(cvitek_devices, ARRAY_SIZE(cvitek_devices));
	/* init device node */
	rtos_init_device_node(cvitek_devices, ARRAY_SIZE(cvitek_devices),
			      cvitek_device_node);
	/* add resources for each devices */
	platform_device_add_resources(&cif_platform_device, cvitek_cif_resource,
				      ARRAY_SIZE(cvitek_cif_resource));
	platform_device_add_resources(&vip_platform_device, cvitek_vip_resource,
				      ARRAY_SIZE(cvitek_vip_resource));
	platform_device_add_resources(&vcodec_platform_device,
				      cvitek_vcodec_resource,
				      ARRAY_SIZE(cvitek_vcodec_resource));
	/* init reserved memory */
	rtos_init_reserved_mem(cvitek_reserved_mem,
			       ARRAY_SIZE(cvitek_reserved_mem));

	misc_init();
#endif
	printf("Post system init done\n");
	GetCommInfo();
}

//#define __DEBUG__

#ifdef __DEBUG__
#define debug_printf printf
#else
#define debug_printf(...)
#endif

void GetCommInfo(void)
{
	cmdqu_t rtos_cmdq;
	unsigned short checksum = 0;
	unsigned char *ptr = &transfer_config;
	/* get communication information from mailbox 0x1900400 */
	memcpy((char *) &transfer_config, (char *) MAILBOX_REG_BUFF, sizeof(struct transfer_config_t));
	/* clear communication information from mailbox 0x1900400 */
	memset((char *) MAILBOX_REG_BUFF, 0 ,  sizeof(cmdqu_t) * MAILBOX_MAX_NUM);
	debug_printf("transfer_config addr = %x\n", &transfer_config);
	debug_printf("transfer_config magic = %x\n", transfer_config.conf_magic);
	debug_printf("transfer_config status = %x\n", transfer_config.mcu_status);
	debug_printf("transfer_config image_type = %x\n", transfer_config.image_type);
	debug_printf("transfer_config dump_print_enable = %x\n", transfer_config.dump_print_enable);
	debug_printf("transfer_config dump_print_size = %x\n", 1 << transfer_config.dump_print_size_idx);
	debug_printf("transfer_config checksum = %x\n", transfer_config.checksum);

	/* check configuration from fsbl */
	for (int i = 0; i < transfer_config.conf_size; i++, ptr++) {
		checksum += *ptr;
	}
	if (checksum != transfer_config.checksum) {
		printf("checksum fail (%x, %x)\n", transfer_config.checksum, checksum);
		/* use the default setting */
		printf("use default confi setting\n");
		transfer_config.conf_magic = RTOS_MAGIC_HEADER;
		transfer_config.conf_size = ((u64) &transfer_config.checksum - (u64) &transfer_config.conf_magic);
		transfer_config.isp_buffer_addr = ISP_MEM_BASE_ADDR;
		transfer_config.isp_buffer_size = ISP_MEM_BASE_SIZE;
		transfer_config.encode_img_addr = H26X_BITSTREAM_ADDR;
		transfer_config.encode_img_size = H26X_BITSTREAM_SIZE;
		transfer_config.encode_buf_addr = H26X_ENC_BUFF_ADDR;
		transfer_config.encode_buf_size = H26X_ENC_BUFF_SIZE;
		transfer_config.image_type = E_FAST_NONE;
		transfer_config.dump_print_enable = 0;
		transfer_config.dump_print_size_idx = DUMP_PRINT_SZ_IDX_4K;
		for (int i = 0, checksum = 0; i < transfer_config.conf_size; i++, ptr++) {
			checksum += *ptr;
		}
		transfer_config.checksum = checksum;
	}

	/* init uart dump feature*/
	dump_uart_init();

	transfer_config.mcu_status = MCU_STATUS_RTOS_T1_INIT;
	transfer_config.linux_status = MCU_STATUS_LINUX_INIT ;
	flush_dcache_range(&transfer_config, sizeof (struct transfer_config_t));
}


#ifdef __riscv

struct irq_chip {
	const char  *name;
	void (*irq_mask)(int irq_num);
	void (*irq_unmask)(int irq_num);
	int  (*irq_ack)(void);
	void (*irq_set_priority)(int irq_num, int priority);
	void (*irq_eoi)(int irq_num);
	void (*irq_set_threshold)(uint32_t threshold);
};

struct irq_action {
	irq_handler_t handler;
	unsigned int flags;
	unsigned int irqn;
	void *priv;
	char name[16];
};

#define IRQ_NUM_MAX   128
static struct irq_action g_irq_action[IRQ_NUM_MAX];
static struct irq_chip sirq_chip;

void disable_irq(unsigned int irqn)
{
	sirq_chip.irq_mask(irqn);
}

void enable_irq(unsigned int irqn)
{
	sirq_chip.irq_unmask(irqn);
}

static void plic_mask_irq( int irq_num)
{
	uint32_t mask = (irq_num);
	uint32_t value = 0;

	if(irq_num < 16) {
		printf("mask irq_num is %d\n", irq_num);
		return;
	}
	value = mmio_read_32(PLIC_ENABLE1 + 4 * (mask / 32));
	value &= ~(0x1 << (mask % 32));
	mmio_write_32((PLIC_ENABLE1 + (mask / 32) * 4), value);

}
static void plic_unmask_irq( int irq_num)
{
	uint32_t mask = (irq_num);
	uint32_t value = 0;

	if(irq_num < 16) {
		printf("unmask irq_num is %d\n",irq_num);
		return;
	}
	//printf("irq_num unmask=%d\n",mask);
	value = mmio_read_32(PLIC_ENABLE1 + 4 * (mask / 32));
	value |= (0x1 << (mask % 32));
	//printf("value=%x\n",value);
	mmio_write_32((PLIC_ENABLE1 + (mask / 32) * 4), value);
}
static int plic_ack_irq()
{
	return mmio_read_32(PLIC_CLAIM);
}
static void plic_eoi_irq(int irq_num)
{
//	printf("plic_eoi_irq %d irq=%d mip = %x\n", __LINE__, irq_num, read_csr(mip));
	mmio_write_32(PLIC_CLAIM, irq_num);
}

static void plic_set_priority_irq(int irq_num, int priority)
{
	//printf("plic_set_priority_irq addr(%x)=%d\n",PLIC_PRIORITY0 + irq_num*4,priority);
	mmio_write_32((PLIC_PRIORITY0 + irq_num*4), priority);
}

static void plic_set_threshold(uint32_t threshold)
{
	mmio_write_32((PLIC_THRESHOLD), threshold);
}

static struct irq_chip sirq_chip = {
	.name           = "RISCV PLIC",
	.irq_mask       = plic_mask_irq,
	.irq_unmask     = plic_unmask_irq,
	.irq_ack        = plic_ack_irq,
	.irq_set_priority = plic_set_priority_irq,
	.irq_eoi        = plic_eoi_irq,
	.irq_set_threshold = plic_set_threshold,
};

void irq_init(void)
{
	int i;
	// clear interrupt enable
	write_csr(mie, 0);
	// clear interrupt pending
	write_csr(mip, 0);

	// Clean the setting of all IRQ
	for (i = 0; i < IRQ_NUM_MAX / 4; i = i + 4) {
		mmio_write_32(((uintptr_t) PLIC_PRIORITY0 + i), 0);
	}

	for (i = 0; i <= IRQ_NUM_MAX / 32; i++) {
		mmio_write_32((PLIC_PENDING1  + i * 4), 0);
		mmio_write_32((PLIC_ENABLE1  + i * 4), 0);
	}

	memset(g_irq_action, 0, sizeof(struct irq_action) * IRQ_NUM_MAX);
	sirq_chip.irq_set_threshold(0);

    set_csr(mstatus, MSTATUS_MIE);

	// MIP_MTIE & MIP_MTIE will be enabled in port.c
    //set_csr(mie, MIP_MEIE);
    //set_csr(mie, MIP_MTIE);
}

int request_irq(int irqn, irq_handler_t handler, unsigned long flags,
        const char *name, void *priv)
{
	//printf("request_irq irqn=%d\n handler=%lx  name = %s\n",irqn,(long) handler,name);
	g_irq_action[irqn].handler = handler;
	if (name) {
		memcpy(g_irq_action[irqn].name, name, sizeof(g_irq_action[irqn].name));
		g_irq_action[irqn].name[sizeof(g_irq_action[irqn].name) - 1] = 0;
	}
	g_irq_action[irqn].irqn = irqn ; //- gic_data.hwirq_base;
	g_irq_action[irqn].flags = flags;
	g_irq_action[irqn].priv = priv;
	// set highest priority
	sirq_chip.irq_set_priority( irqn, 7);
	// unmask irq
	sirq_chip.irq_unmask( irqn);

	return 0;
}

void do_irq(void)
{
	int irqn;

	do{
		irqn = sirq_chip.irq_ack();
		if(g_irq_action[irqn].handler && irqn) {
			//printf("do_irq irqn=%d\n",irqn);
			g_irq_action[irqn].handler(g_irq_action[irqn].irqn, g_irq_action[irqn].priv);
		} else if(irqn)
			printf("g_irq_action[%i] NULL",irqn);
		else //plic_claim =0
			break;
		// clear plic pending
		sirq_chip.irq_eoi(irqn);
	}while(1);
	// clear external interrupt pending
	clear_csr(mip, MIP_MEIE);
}

#else
extern XScuGic xInterruptController;
#define GIC_SPI 0
#define GIC_PPI 1

int request_irq(int irqn, Xil_ExceptionHandler handler,
		unsigned long flags, const char *name, void *priv)
{
	return request_irq_mode(irqn, handler, flags, name, priv, GIC_SPI);
}
int request_sgirq(int irqn, Xil_ExceptionHandler handler,
		  unsigned long flags, const char *name, void *priv)
{
	return request_irq_mode(irqn, handler, flags, name, priv, GIC_PPI);
}
int request_irq_mode(int irqn, Xil_ExceptionHandler handler,
		     unsigned long flags, const char *name, void *priv,
		     int mode)
{
	BaseType_t xStatus;

	if ((irqn < 0) || (irqn >= NUM_IRQ))
		return -1;

	if (mode == GIC_SPI)
		irqn += hwirq_base;

	/* Sets the interrupt priority and trigger type. */
	if (flags & (IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING))
		XScuGic_SetPriorityTriggerType(
			&xInterruptController, irqn,
			portLOWEST_USABLE_INTERRUPT_PRIORITY
				<< portPRIORITY_SHIFT,
			IRQ_EDGE);
	else
		XScuGic_SetPriorityTriggerType(
			&xInterruptController, irqn,
			portLOWEST_USABLE_INTERRUPT_PRIORITY
				<< portPRIORITY_SHIFT,
			IRQ_LEVEL);

	/* Connect to the interrupt handler. */
	xStatus = XScuGic_Connect(&xInterruptController, irqn,
				  (Xil_ExceptionHandler)handler, priv);
	configASSERT(xStatus == XST_SUCCESS);

	/* Enable the interrupt in the GICD. */
	XScuGic_Enable(&xInterruptController, irqn);
	return 0;
}
#endif
