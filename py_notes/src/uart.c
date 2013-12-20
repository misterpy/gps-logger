#include <gps.h>

void USART_Init(unsigned int baud)
{
	// Setting baud rate
	UBRRHn = (unsigned char)(baud>>8);
	UBRRLn = (unsigned char)baud;

	// Enable reciever and transmitter
	UCSRnB |= (1<<RXENn)|(1<<TXENn);

	// Set frame format: 8 bits data, 2 stop bits
	UCSRnC = (1<<USBSn)|(3<<UCSZn0);
}

void USART_Transmit(unsigned char data)
{
	/* Wait for empty transmit buffer, wait for the transmit buffer to be ready */
	while (!( UCSRnA & (1<<UDREn)));

	/* Put data into buffer, sends the data */
	UDRn = data;
}

unsigned char USART_Receive(void)
{
	/* Wait for data to be received */
	while(!(UCSRnA & (1<<RXCn)));
	
	/* Get and return received data from buffer */
	return UDRn;
}