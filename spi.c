// SPI Communication protocol

#include "spi.h"
#include "global.h"

//Initialize SPI for SD card
//clock rate: i.e. 125Khz
void spi_init(void){
	SPCR0 = 0x52; //setup SPI: Master mode, MSB first, SCK phase low, SCK idle low
	SPSR0 = 0x00;
}

unsigned char SPI_transmit(unsigned char data){
	// Start transmission
	SPDR0 = data;

	// Wait for transmission complete
	while(!(SPSR0 & (1<<SPIF0)));
	data = SPDR0;

	return(data);
}

unsigned char SPI_receive(void){
	unsigned char data;
	// Wait for reception complete

	SPDR0 = 0xff;
	while(!(SPSR0 & (1<<SPIF0)));
	data = SPDR0;

	// Return data register
	return data;
}
