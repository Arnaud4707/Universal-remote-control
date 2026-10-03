#ifndef GPIO_H
#define GPIO_H

#include "esp8266.h"

#define GPIO_BASE 0x60000300

#define PERIPHS_IO_MUX 0x60000800
#define PERIPHS_IO_MUX_GPIO2_U (PERIPHS_IO_MUX + 0x38)

#define PERIPHS_IO_MUX_FUNC 0x13
#define PERIPHS_IO_MUX_FUNC_S 4

#define FUNC_GPIO2 0

#define GPIO_OUT (GPIO_BASE + 0x00)
#define GPIO_OUT_W1TS (GPIO_BASE + 0x04)
#define GPIO_OUT_W1TC (GPIO_BASE + 0x08)

#define GPIO_ENABLE (GPIO_BASE + 0x0C)
#define GPIO_ENABLE_W1TS (GPIO_BASE + 0x10)
#define GPIO_ENABLE_W1TC (GPIO_BASE + 0x14)

static inline void gpio_mode(void)
{
	uint32_t v = REG32(PERIPHS_IO_MUX_GPIO2_U);

	v &= ~(PERIPHS_IO_MUX_FUNC << PERIPHS_IO_MUX_FUNC_S);
	v |= (FUNC_GPIO2 << PERIPHS_IO_MUX_FUNC_S);

	REG32(PERIPHS_IO_MUX_GPIO2_U) = v;
}

static inline void gpio_output_enable(unsigned gpio)
{
	REG32(GPIO_ENABLE_W1TS) = BIT(gpio);
}

static inline void gpio_set(unsigned gpio)
{
	REG32(GPIO_OUT_W1TS) = BIT(gpio);
}

static inline void gpio_clear(unsigned gpio) {
	REG32(GPIO_OUT_W1TC) = BIT(gpio);
}

#endif
