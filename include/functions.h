#ifndef FUNCTION_H
#define FUNCTION_H

#include "esp8266.h"
#include "pin_mux_register.h"
#include "gpio.h"
#include <stdint.h>

static inline void gpio2_mode(void)
{
	uint32_t v = REG32(PERIPHS_IO_MUX_GPIO2_U);

	v &= ~(PERIPHS_IO_MUX_FUNC << PERIPHS_IO_MUX_FUNC_S); 
	v |= (FUNC_GPIO2 << PERIPHS_IO_MUX_FUNC_S);

	REG32(PERIPHS_IO_MUX_GPIO2_U) = v;
}

#define PIN_FUNC_SELECT(PIN_REG_ADDR, FUNC) do { \
    REG32(PIN_REG_ADDR) = (REG32(PIN_REG_ADDR) & ~(PERIPHS_IO_MUX_FUNC << PERIPHS_IO_MUX_FUNC_S)) \
                        | (((FUNC) & PERIPHS_IO_MUX_FUNC) << PERIPHS_IO_MUX_FUNC_S); \
} while (0)

#define PIN_PULLUP_EN(PIN_REG_ADDR) do { \
    REG32(PIN_REG_ADDR) |= (1 << 7); \
} while (0)

#define PIN_PULLUP_DIS(PIN_REG_ADDR) do { \
    REG32(PIN_REG_ADDR) &= ~(1 << 7); \
} while (0)

static inline uint8_t GPIO_INPUT_GET(unsigned gpio) {
    return (uint8_t)((REG32(GPIO_IN) >> gpio) & 0x1)  ;
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

static void init_gpio_interrupt(unsigned gpio){
    // clear interrupt
    uint16_t gpio_status=0;
    gpio_status = GPIO_REG_READ(GPIO_STATUS_ADDRESS);
    GPIO_REG_WRITE(GPIO_STATUS_W1TC_ADDRESS, gpio_status);

    // clear interrupt
	REG32(GPIO_STATUS_W1TC) = BIT(gpio);

}

#endif