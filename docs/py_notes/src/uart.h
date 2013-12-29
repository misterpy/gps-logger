#ifndef UART_H
	#define UART_H

	#include "global.h"

	#define UART_BAUD_RATE 11

	// Initialising the USART
	void USART_Init(unsigned int baud);

	// Transmitting data using USART
	void USART_Transmit(unsigned char data);

	// Receiving data using USART
	unsigned char USART_Receive(void);

#endif
