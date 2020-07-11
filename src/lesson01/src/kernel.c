#include "uart.h"

void kernel_main(void)
{
	puart_init();
	puart_send_string("Hello, world!\r\n");

	while (1) {
		puart_send(puart_recv());
	}
}
