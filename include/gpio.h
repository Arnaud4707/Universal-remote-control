#ifndef GPIO_H
#define GPIO_H

#include "ets.h"

#define GPIO_BASE 0x60000300

#define GPIO_OUT (GPIO_BASE + 0x00)
#define GPIO_OUT_W1TS (GPIO_BASE + 0x04)
#define GPIO_OUT_W1TC (GPIO_BASE + 0x08)
#define GPIO_ENABLE (GPIO_BASE + 0x0C)
#define GPIO_ENABLE_W1TS (GPIO_BASE + 0x10)
#define GPIO_ENABLE_W1TC (GPIO_BASE + 0x14)
#define GPIO_IN	(GPIO_BASE + 0x18)
#define GPIO_STATUS (GPIO_BASE + 0x1C)
#define GPIO_STATUS_W1TS (GPIO_BASE + 0x20)
#define GPIO_STATUS_W1TC (GPIO_BASE + 0x24)
#define GPIO_PIN0 (GPIO_BASE + 0x28)


#define GPIO_STATUS_ADDRESS                 0x1c
#define GPIO_STATUS_INTERRUPT                   0x0000ffff
#define GPIO_STATUS_INTERRUPT_S                 0

#define GPIO_STATUS_W1TS_ADDRESS            0x20
#define GPIO_STATUS_INTERRUPT_W1TS              0x0000ffff
#define GPIO_STATUS_INTERRUPT_W1TS_S            0

#define GPIO_STATUS_W1TC_ADDRESS            0x24
#define GPIO_STATUS_INTERRUPT_W1TC              0x0000ffff
#define GPIO_STATUS_INTERRUPT_W1TC_S            0
#define GPIO_STATUS_INTERRUPT_DATA_MASK         0x0000ffff

#define GPIO_REG_READ(reg)                  READ_PERI_REG(GPIO_BASE + reg)
#define GPIO_REG_WRITE(reg, val)            WRITE_PERI_REG(GPIO_BASE + reg, val)
#endif
