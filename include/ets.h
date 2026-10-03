#ifndef ETS_H
#define ETS_H

#define ETS_SLC_INUM        1
#define ETS_SPI_INUM        2
#define ETS_GPIO_INUM       4
#define ETS_UART_INUM       5
#define ETS_MAX_INUM        6
#define ETS_SOFT_INUM       7
#define ETS_WDT_INUM        8
#define ETS_FRC_TIMER1_INUM 9
#define ETS_INT_MAX         14

typedef enum {
    GPIO_PIN_INTR_DISABLE = 0,
    GPIO_PIN_INTR_POSEDGE = 1,
    GPIO_PIN_INTR_NEGEDGE = 2,
    GPIO_PIN_INTR_ANYEGDE = 3,
    GPIO_PIN_INTR_LOLEVEL = 4,
    GPIO_PIN_INTR_HILEVEL = 5
} GPIO_INT_TYPE;


#define READ_PERI_REG(addr)                             (*((volatile uint32_t *)(addr)))
#define WRITE_PERI_REG(addr, val)                       (*((volatile uint32_t *)(addr))) = (uint32_t)(val)
#define CLEAR_PERI_REG_MASK(reg, mask)                  WRITE_PERI_REG((reg), (READ_PERI_REG(reg) & (~(mask))))
#define SET_PERI_REG_MASK(reg, mask)                    WRITE_PERI_REG((reg), (READ_PERI_REG(reg) | (mask)))

#endif