#ifndef ESP8266_H
#define ESP8266_H

#include <stdint.h>

#define REG32(addr) (*(volatile uint32_t *)(addr))

#define BIT(n) (1U << (n))

#endif