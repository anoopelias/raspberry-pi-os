#ifndef	_P_UART_H
#define	_P_UART_H

#include "peripherals/base.h"

#define UBASE       (PBASE+0x00201000)

#define UART_DR     (UBASE+0x00)
#define UART_FR     (UBASE+0x18)
#define UART_IBRD   (UBASE+0x24)
#define UART_FBRD   (UBASE+0x28)
#define UART_LCRH   (UBASE+0x2C)
#define UART_CR     (UBASE+0x30)

#endif  /*_P_UART_H */
