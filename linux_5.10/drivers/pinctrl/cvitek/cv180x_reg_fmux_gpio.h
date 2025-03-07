/* SPDX-License-Identifier: GPL-2.0-only */
// $Module: fmux_gpio $
// $RegisterBank Version: V 1.0.00 $
// $Author: ghost $
// $Date: Thu, 17 Mar 2022 04:53:31 PM $
//

//GEN REG ADDR/OFFSET/MASK

#ifndef __CV180X_REG_FMUX_GPIO_H__
#define __CV180X_REG_FMUX_GPIO_H__

#define  FMUX_GPIO_REG_IOCTRL_SD0_CLK  0x0
#define  FMUX_GPIO_REG_IOCTRL_SD0_CMD  0x4
#define  FMUX_GPIO_REG_IOCTRL_SD0_D0  0x8
#define  FMUX_GPIO_REG_IOCTRL_SD0_D1  0xc
#define  FMUX_GPIO_REG_IOCTRL_SD0_D2  0x10
#define  FMUX_GPIO_REG_IOCTRL_SD0_D3  0x14
#define  FMUX_GPIO_REG_IOCTRL_SD0_CD  0x18
#define  FMUX_GPIO_REG_IOCTRL_SD0_PWR_EN  0x1c
#define  FMUX_GPIO_REG_IOCTRL_SPK_EN  0x20
#define  FMUX_GPIO_REG_IOCTRL_UART0_TX  0x24
#define  FMUX_GPIO_REG_IOCTRL_UART0_RX  0x28
#define  FMUX_GPIO_REG_IOCTRL_SPINOR_HOLD_X  0x2c
#define  FMUX_GPIO_REG_IOCTRL_SPINOR_SCK  0x30
#define  FMUX_GPIO_REG_IOCTRL_SPINOR_MOSI  0x34
#define  FMUX_GPIO_REG_IOCTRL_SPINOR_WP_X  0x38
#define  FMUX_GPIO_REG_IOCTRL_SPINOR_MISO  0x3c
#define  FMUX_GPIO_REG_IOCTRL_SPINOR_CS_X  0x40
#define  FMUX_GPIO_REG_IOCTRL_JTAG_CPU_TMS  0x44
#define  FMUX_GPIO_REG_IOCTRL_JTAG_CPU_TCK  0x48
#define  FMUX_GPIO_REG_IOCTRL_IIC0_SCL  0x4c
#define  FMUX_GPIO_REG_IOCTRL_IIC0_SDA  0x50
#define  FMUX_GPIO_REG_IOCTRL_AUX0  0x54
#define  FMUX_GPIO_REG_IOCTRL_GPIO_ZQ  0x58
#define  FMUX_GPIO_REG_IOCTRL_PWR_VBAT_DET  0x5c
#define  FMUX_GPIO_REG_IOCTRL_PWR_RSTN  0x60
#define  FMUX_GPIO_REG_IOCTRL_PWR_SEQ1  0x64
#define  FMUX_GPIO_REG_IOCTRL_PWR_SEQ2  0x68
#define  FMUX_GPIO_REG_IOCTRL_PWR_WAKEUP0  0x6c
#define  FMUX_GPIO_REG_IOCTRL_PWR_BUTTON1  0x70
#define  FMUX_GPIO_REG_IOCTRL_XTAL_XIN  0x74
#define  FMUX_GPIO_REG_IOCTRL_PWR_GPIO0  0x78
#define  FMUX_GPIO_REG_IOCTRL_PWR_GPIO1  0x7c
#define  FMUX_GPIO_REG_IOCTRL_PWR_GPIO2  0x80
#define  FMUX_GPIO_REG_IOCTRL_SD1_GPIO1  0x84
#define  FMUX_GPIO_REG_IOCTRL_SD1_GPIO0  0x88
#define  FMUX_GPIO_REG_IOCTRL_SD1_D3  0x8c
#define  FMUX_GPIO_REG_IOCTRL_SD1_D2  0x90
#define  FMUX_GPIO_REG_IOCTRL_SD1_D1  0x94
#define  FMUX_GPIO_REG_IOCTRL_SD1_D0  0x98
#define  FMUX_GPIO_REG_IOCTRL_SD1_CMD  0x9c
#define  FMUX_GPIO_REG_IOCTRL_SD1_CLK  0xa0
#define  FMUX_GPIO_REG_IOCTRL_PWM0_BUCK  0xa4
#define  FMUX_GPIO_REG_IOCTRL_ADC1  0xa8
#define  FMUX_GPIO_REG_IOCTRL_USB_VBUS_DET  0xac
#define  FMUX_GPIO_REG_IOCTRL_MUX_SPI1_MISO  0xb0
#define  FMUX_GPIO_REG_IOCTRL_MUX_SPI1_MOSI  0xb4
#define  FMUX_GPIO_REG_IOCTRL_MUX_SPI1_CS  0xb8
#define  FMUX_GPIO_REG_IOCTRL_MUX_SPI1_SCK  0xbc
#define  FMUX_GPIO_REG_IOCTRL_PAD_ETH_TXP  0xc0
#define  FMUX_GPIO_REG_IOCTRL_PAD_ETH_TXM  0xc4
#define  FMUX_GPIO_REG_IOCTRL_PAD_ETH_RXP  0xc8
#define  FMUX_GPIO_REG_IOCTRL_PAD_ETH_RXM  0xcc
#define  FMUX_GPIO_REG_IOCTRL_GPIO_RTX  0xd0
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPIRX4N  0xd4
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPIRX4P  0xd8
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPIRX3N  0xdc
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPIRX3P  0xe0
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPIRX2N  0xe4
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPIRX2P  0xe8
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPIRX1N  0xec
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPIRX1P  0xf0
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPIRX0N  0xf4
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPIRX0P  0xf8
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPI_TXM2  0xfc
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPI_TXP2  0x100
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPI_TXM1  0x104
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPI_TXP1  0x108
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPI_TXM0  0x10c
#define  FMUX_GPIO_REG_IOCTRL_PAD_MIPI_TXP0  0x110
#define  FMUX_GPIO_REG_IOCTRL_PKG_TYPE0  0x114
#define  FMUX_GPIO_REG_IOCTRL_PKG_TYPE1  0x118
#define  FMUX_GPIO_REG_IOCTRL_PKG_TYPE2  0x11c
#define  FMUX_GPIO_REG_IOCTRL_PAD_AUD_AINL_MIC  0x120
#define  FMUX_GPIO_REG_IOCTRL_PAD_AUD_AINR_MIC  0x124
#define  FMUX_GPIO_REG_IOCTRL_PAD_AUD_AOUTL  0x128
#define  FMUX_GPIO_REG_IOCTRL_PAD_AUD_AOUTR  0x12c
#define  FMUX_GPIO_REG_DEVMATRIX_UART0_IP_SEL  0x1d4
#define  FMUX_GPIO_REG_DEVMATRIX_UART1_IP_SEL  0x1d8
#define  FMUX_GPIO_REG_DEVMATRIX_UART2_IP_SEL  0x1dc
#define  FMUX_GPIO_REG_DEVMATRIX_UART3_IP_SEL  0x1e0
#define  FMUX_GPIO_REG_DEVMATRIX_UART4_IP_SEL  0x1e4
#define  FMUX_GPIO_FUNCSEL_SD0_CLK   0x0
#define  FMUX_GPIO_FUNCSEL_SD0_CLK_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD0_CLK_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD0_CMD   0x4
#define  FMUX_GPIO_FUNCSEL_SD0_CMD_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD0_CMD_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD0_D0   0x8
#define  FMUX_GPIO_FUNCSEL_SD0_D0_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD0_D0_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD0_D1   0xc
#define  FMUX_GPIO_FUNCSEL_SD0_D1_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD0_D1_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD0_D2   0x10
#define  FMUX_GPIO_FUNCSEL_SD0_D2_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD0_D2_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD0_D3   0x14
#define  FMUX_GPIO_FUNCSEL_SD0_D3_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD0_D3_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD0_CD   0x18
#define  FMUX_GPIO_FUNCSEL_SD0_CD_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD0_CD_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD0_PWR_EN   0x1c
#define  FMUX_GPIO_FUNCSEL_SD0_PWR_EN_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD0_PWR_EN_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SPK_EN   0x20
#define  FMUX_GPIO_FUNCSEL_SPK_EN_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SPK_EN_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_UART0_TX   0x24
#define  FMUX_GPIO_FUNCSEL_UART0_TX_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_UART0_TX_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_UART0_RX   0x28
#define  FMUX_GPIO_FUNCSEL_UART0_RX_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_UART0_RX_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SPINOR_HOLD_X   0x2c
#define  FMUX_GPIO_FUNCSEL_SPINOR_HOLD_X_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SPINOR_HOLD_X_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SPINOR_SCK   0x30
#define  FMUX_GPIO_FUNCSEL_SPINOR_SCK_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SPINOR_SCK_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SPINOR_MOSI   0x34
#define  FMUX_GPIO_FUNCSEL_SPINOR_MOSI_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SPINOR_MOSI_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SPINOR_WP_X   0x38
#define  FMUX_GPIO_FUNCSEL_SPINOR_WP_X_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SPINOR_WP_X_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SPINOR_MISO   0x3c
#define  FMUX_GPIO_FUNCSEL_SPINOR_MISO_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SPINOR_MISO_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SPINOR_CS_X   0x40
#define  FMUX_GPIO_FUNCSEL_SPINOR_CS_X_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SPINOR_CS_X_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_JTAG_CPU_TMS   0x44
#define  FMUX_GPIO_FUNCSEL_JTAG_CPU_TMS_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_JTAG_CPU_TMS_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_JTAG_CPU_TCK   0x48
#define  FMUX_GPIO_FUNCSEL_JTAG_CPU_TCK_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_JTAG_CPU_TCK_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_IIC0_SCL   0x4c
#define  FMUX_GPIO_FUNCSEL_IIC0_SCL_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_IIC0_SCL_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_IIC0_SDA   0x50
#define  FMUX_GPIO_FUNCSEL_IIC0_SDA_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_IIC0_SDA_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_AUX0   0x54
#define  FMUX_GPIO_FUNCSEL_AUX0_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_AUX0_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_GPIO_ZQ   0x58
#define  FMUX_GPIO_FUNCSEL_GPIO_ZQ_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_GPIO_ZQ_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PWR_VBAT_DET   0x5c
#define  FMUX_GPIO_FUNCSEL_PWR_VBAT_DET_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PWR_VBAT_DET_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PWR_RSTN   0x60
#define  FMUX_GPIO_FUNCSEL_PWR_RSTN_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PWR_RSTN_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PWR_SEQ1   0x64
#define  FMUX_GPIO_FUNCSEL_PWR_SEQ1_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PWR_SEQ1_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PWR_SEQ2   0x68
#define  FMUX_GPIO_FUNCSEL_PWR_SEQ2_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PWR_SEQ2_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PWR_WAKEUP0   0x6c
#define  FMUX_GPIO_FUNCSEL_PWR_WAKEUP0_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PWR_WAKEUP0_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PWR_BUTTON1   0x70
#define  FMUX_GPIO_FUNCSEL_PWR_BUTTON1_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PWR_BUTTON1_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_XTAL_XIN   0x74
#define  FMUX_GPIO_FUNCSEL_XTAL_XIN_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_XTAL_XIN_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PWR_GPIO0   0x78
#define  FMUX_GPIO_FUNCSEL_PWR_GPIO0_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PWR_GPIO0_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PWR_GPIO1   0x7c
#define  FMUX_GPIO_FUNCSEL_PWR_GPIO1_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PWR_GPIO1_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PWR_GPIO2   0x80
#define  FMUX_GPIO_FUNCSEL_PWR_GPIO2_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PWR_GPIO2_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD1_GPIO1   0x84
#define  FMUX_GPIO_FUNCSEL_SD1_GPIO1_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD1_GPIO1_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD1_GPIO0   0x88
#define  FMUX_GPIO_FUNCSEL_SD1_GPIO0_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD1_GPIO0_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD1_D3   0x8c
#define  FMUX_GPIO_FUNCSEL_SD1_D3_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD1_D3_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD1_D2   0x90
#define  FMUX_GPIO_FUNCSEL_SD1_D2_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD1_D2_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD1_D1   0x94
#define  FMUX_GPIO_FUNCSEL_SD1_D1_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD1_D1_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD1_D0   0x98
#define  FMUX_GPIO_FUNCSEL_SD1_D0_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD1_D0_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD1_CMD   0x9c
#define  FMUX_GPIO_FUNCSEL_SD1_CMD_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD1_CMD_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_SD1_CLK   0xa0
#define  FMUX_GPIO_FUNCSEL_SD1_CLK_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_SD1_CLK_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PWM0_BUCK   0xa4
#define  FMUX_GPIO_FUNCSEL_PWM0_BUCK_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PWM0_BUCK_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_ADC1   0xa8
#define  FMUX_GPIO_FUNCSEL_ADC1_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_ADC1_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_USB_VBUS_DET   0xac
#define  FMUX_GPIO_FUNCSEL_USB_VBUS_DET_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_USB_VBUS_DET_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_MISO   0xb0
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_MISO_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_MISO_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_MOSI   0xb4
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_MOSI_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_MOSI_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_CS   0xb8
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_CS_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_CS_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_SCK   0xbc
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_SCK_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_MUX_SPI1_SCK_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_TXP   0xc0
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_TXP_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_TXP_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_TXM   0xc4
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_TXM_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_TXM_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_RXP   0xc8
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_RXP_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_RXP_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_RXM   0xcc
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_RXM_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_ETH_RXM_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_GPIO_RTX   0xd0
#define  FMUX_GPIO_FUNCSEL_GPIO_RTX_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_GPIO_RTX_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX4N   0xd4
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX4N_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX4N_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX4P   0xd8
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX4P_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX4P_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX3N   0xdc
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX3N_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX3N_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX3P   0xe0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX3P_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX3P_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX2N   0xe4
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX2N_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX2N_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX2P   0xe8
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX2P_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX2P_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX1N   0xec
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX1N_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX1N_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX1P   0xf0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX1P_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX1P_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX0N   0xf4
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX0N_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX0N_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX0P   0xf8
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX0P_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPIRX0P_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXM2   0xfc
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXM2_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXM2_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXP2   0x100
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXP2_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXP2_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXM1   0x104
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXM1_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXM1_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXP1   0x108
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXP1_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXP1_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXM0   0x10c
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXM0_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXM0_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXP0   0x110
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXP0_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_MIPI_TXP0_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PKG_TYPE0   0x114
#define  FMUX_GPIO_FUNCSEL_PKG_TYPE0_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PKG_TYPE0_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PKG_TYPE1   0x118
#define  FMUX_GPIO_FUNCSEL_PKG_TYPE1_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PKG_TYPE1_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PKG_TYPE2   0x11c
#define  FMUX_GPIO_FUNCSEL_PKG_TYPE2_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PKG_TYPE2_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AINL_MIC   0x120
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AINL_MIC_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AINL_MIC_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AINR_MIC   0x124
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AINR_MIC_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AINR_MIC_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AOUTL   0x128
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AOUTL_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AOUTL_MASK   0x7
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AOUTR   0x12c
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AOUTR_OFFSET 0
#define  FMUX_GPIO_FUNCSEL_PAD_AUD_AOUTR_MASK   0x7
#define  FMUX_GPIO_MUX_UART0_IP_SEL   0x1d4
#define  FMUX_GPIO_MUX_UART0_IP_SEL_OFFSET 0
#define  FMUX_GPIO_MUX_UART0_IP_SEL_MASK   0x7
#define  FMUX_GPIO_MUX_UART1_IP_SEL   0x1d8
#define  FMUX_GPIO_MUX_UART1_IP_SEL_OFFSET 0
#define  FMUX_GPIO_MUX_UART1_IP_SEL_MASK   0x7
#define  FMUX_GPIO_MUX_UART2_IP_SEL   0x1dc
#define  FMUX_GPIO_MUX_UART2_IP_SEL_OFFSET 0
#define  FMUX_GPIO_MUX_UART2_IP_SEL_MASK   0x7
#define  FMUX_GPIO_MUX_UART3_IP_SEL   0x1e0
#define  FMUX_GPIO_MUX_UART3_IP_SEL_OFFSET 0
#define  FMUX_GPIO_MUX_UART3_IP_SEL_MASK   0x7
#define  FMUX_GPIO_MUX_UART4_IP_SEL   0x1e4
#define  FMUX_GPIO_MUX_UART4_IP_SEL_OFFSET 0
#define  FMUX_GPIO_MUX_UART4_IP_SEL_MASK   0x7

#endif /* __CV180X_REG_FMUX_GPIO_H__ */
