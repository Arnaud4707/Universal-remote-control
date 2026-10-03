#ifndef PIN_MUX_REGISTER_H
#define PIN_MUX_REGISTER_H

#define PERIPHS_IO_MUX 0x60000800

#define PERIPHS_IO_MUX_FUNC 0x13
#define PERIPHS_IO_MUX_FUNC_S 4

#define PERIPHS_IO_MUX_MTMS_U   (PERIPHS_IO_MUX + 0x0C)
#define FUNC_GPIO14                         3

#define PERIPHS_IO_MUX_GPIO2_U (PERIPHS_IO_MUX + 0x38)
#define FUNC_GPIO2 0

#define PERIPHS_IO_MUX_GPIO5_U          (PERIPHS_IO_MUX + 0x40)
#define FUNC_GPIO5                          0

#endif