// SPI Communication protocol header

#ifndef _SPI_ROUTINES_H_
#define _SPI_ROUTINES_H_

#define SPI_SD             SPCR = 0x52
#define SPI_HIGH_SPEED     SPCR = 0x50; SPSR |= (1<<SPI2X)

void spi_init(void);
unsigned char SPI_transmit(unsigned char);
unsigned char SPI_receive(void);

#endif