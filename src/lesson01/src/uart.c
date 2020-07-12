#include "utils.h"
#include "peripherals/uart.h"
#include "peripherals/gpio.h"

void puart_send ( char c )
{
	while(1) {
		if(get32(UART_FR)&0x80)
			break;
	}
	put32(UART_DR,c);
}

char puart_recv ( void )
{
	while(1) {
		if(get32(UART_FR)&0x40)
			break;
	}
	return(get32(UART_DR)&0xFF);
}

void puart_send_string(char* str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		puart_send((char)str[i]);
	}
}

void puart_init ( void )
{
	unsigned int selector;

	selector = get32(GPFSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 4<<12;                      // set alt0 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 4<<15;                      // set alt0 for gpio15
	put32(GPFSEL1,selector);

	put32(GPPUD,0);
	delay(150);
	put32(GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	put32(GPPUDCLK0,0);

	put32(UART_IBRD,26);                 // Set integer baud rate 115200 divisor
	put32(UART_FBRD,3);                  // Set fractional baud rate 115200 divisor
	put32(UART_LCRH,(3<<5));             // Set word length to 8 bits

	put32(UART_CR,(1<<9)|(1<<8)|1);      // Enable transmit, receive and uart

}
