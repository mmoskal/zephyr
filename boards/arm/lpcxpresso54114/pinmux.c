/*
 * Copyright (c) 2017,  NXP
 * SPDX-License-Identifier: Apache-2.0
 */

#include <init.h>
#include <pinmux.h>
#include <fsl_common.h>
#include <fsl_iocon.h>

#define IOCON_PIO_DIGITAL_EN	0x80u
#define IOCON_PIO_FUNC0		0x00u
#define IOCON_PIO_FUNC1		0x01u
#define IOCON_PIO_FUNC2		0x02u
#define IOCON_PIO_INPFILT_OFF	0x0100u
#define IOCON_PIO_INV_DI	0x00u
#define IOCON_PIO_MODE_INACT	0x00u
#define IOCON_PIO_OPENDRAIN_DI	0x00u
#define IOCON_PIO_SLEW_STANDARD	0x00u
#define IOCON_PIO_MODE_PULLUP	0x10u

static int lpcxpresso_54114_pinmux_init(struct device *dev)
{
	ARG_UNUSED(dev);

#ifdef CONFIG_PINMUX_MCUX_LPC_PORT0
	struct device *port0 =
		device_get_binding(CONFIG_PINMUX_MCUX_LPC_PORT0_NAME);
#endif

#ifdef	CONFIG_PINMUX_MCUX_LPC_PORT1
	struct device *port1 =
		device_get_binding(CONFIG_PINMUX_MCUX_LPC_PORT1_NAME);
#endif

#ifdef CONFIG_USART_MCUX_LPC_0
	/* USART0 RX,  TX */
	const u32_t port0_pin0_config = (
			IOCON_PIO_FUNC1 |
			IOCON_PIO_MODE_INACT |
			IOCON_PIO_INV_DI |
			IOCON_PIO_DIGITAL_EN |
			IOCON_PIO_INPFILT_OFF |
			IOCON_PIO_SLEW_STANDARD |
			IOCON_PIO_OPENDRAIN_DI
			);

	const u32_t port0_pin1_config = (
			IOCON_PIO_FUNC1 |
			IOCON_PIO_MODE_INACT |
			IOCON_PIO_INV_DI |
			IOCON_PIO_DIGITAL_EN |
			IOCON_PIO_INPFILT_OFF |
			IOCON_PIO_SLEW_STANDARD |
			IOCON_PIO_OPENDRAIN_DI
			);

	pinmux_pin_set(port0, 0, port0_pin0_config);
	pinmux_pin_set(port0, 1, port0_pin1_config);

#endif

#ifdef CONFIG_GPIO_MCUX_LPC_PORT0
	const u32_t port0_pin29_config = (
			IOCON_PIO_FUNC0 |
			IOCON_PIO_MODE_PULLUP |
			IOCON_PIO_INV_DI |
			IOCON_PIO_DIGITAL_EN |
			IOCON_PIO_INPFILT_OFF |
			IOCON_PIO_OPENDRAIN_DI
			);

	pinmux_pin_set(port0, 29, port0_pin29_config);
#endif

#ifdef CONFIG_GPIO_MCUX_LPC_PORT1
	const u32_t port1_pin10_config = (
			IOCON_PIO_FUNC0 |
			IOCON_PIO_MODE_PULLUP |
			IOCON_PIO_INV_DI |
			IOCON_PIO_DIGITAL_EN |
			IOCON_PIO_INPFILT_OFF |
			IOCON_PIO_SLEW_STANDARD |
			IOCON_PIO_OPENDRAIN_DI
			);

	pinmux_pin_set(port1, 10, port1_pin10_config);
#endif

	return 0;
}

SYS_INIT(lpcxpresso_54114_pinmux_init,  PRE_KERNEL_1,
	 CONFIG_PINMUX_INIT_PRIORITY);
