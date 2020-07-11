#ifndef	_UART_H
#define	_UART_H

void puart_init ( void );
char puart_recv ( void );
void puart_send ( char c );
void puart_send_string(char* str);

#endif  /*_UART_H */
