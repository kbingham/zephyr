/*
 * Copyright (c) 2020 Kieran Bingham <kbingham@kernel.org>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <drivers/pinmux.h>
#include <sys/sys_io.h>

#include <pinmux/stm32/pinmux_stm32.h>

/* pin assignments for Wio LTE Cat.1 board */
static const struct pin_config pinconf[] = {
#ifdef CONFIG_UART_1
	{ STM32_PIN_PB6, STM32F4_PINMUX_FUNC_PB6_USART1_TX },
	{ STM32_PIN_PB7, STM32F4_PINMUX_FUNC_PB7_USART1_RX },
#endif  /* CONFIG_UART_1 */
#ifdef CONFIG_UART_2
	{ STM32_PIN_PA2, STM32F4_PINMUX_FUNC_PA2_USART2_TX },
	{ STM32_PIN_PA3, STM32F4_PINMUX_FUNC_PA3_USART2_RX },
#endif  /* CONFIG_UART_2 */
#ifdef CONFIG_UART_6
	{ STM32_PIN_PC6, STM32F4_PINMUX_FUNC_PC6_USART6_TX },
	{ STM32_PIN_PC7, STM32F4_PINMUX_FUNC_PC7_USART6_RX },
#endif  /* CONFIG_UART_6 */
#ifdef CONFIG_I2C_1
	{ STM32_PIN_PB8, STM32F4_PINMUX_FUNC_PB8_I2C1_SCL },
	{ STM32_PIN_PB9, STM32F4_PINMUX_FUNC_PB9_I2C1_SDA },
#endif /* CONFIG_I2C_1 */
#ifdef CONFIG_ADC1_CHAN8
	{ STM32_PIN_PB0, STM32F4_PINMUX_FUNC_PB0_ADC12_IN8 },     /* BAT_C */
#endif
};

static int pinmux_stm32_init(struct device *port)
{
	ARG_UNUSED(port);

	stm32_setup_pins(pinconf, ARRAY_SIZE(pinconf));

	return 0;
}

SYS_INIT(pinmux_stm32_init, PRE_KERNEL_1,
	 CONFIG_PINMUX_STM32_DEVICE_INITIALIZATION_PRIORITY);
