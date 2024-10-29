################################################################################
#
# meshtasticd
#
################################################################################
# See https://bootlin.com/~thomas/site/buildroot/adding-packages.html#generic-package-tutorial

MESHTASTICD_VERSION = 2.5.8.6485f03
MESHTASTICD_SITE = $(call github,meshtastic,firmware,v$(MESHTASTICD_VERSION))
MESHTASTICD_LICENSE = GPL-3.0
MESHTASTICD_LICENSE_FILES = LICENSE
# MESHTASTICD_DEPENDENCIES = 

$(eval $(generic-package))
