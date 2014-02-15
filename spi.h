// SPI Communication protocol header

#ifndef SPI_H
#define SPI_H

#define SPI_SD             SPCR0 = 0x52
#define SPI_HIGH_SPEED     SPCR0 = 0x50; SPSR0 |= (1<<SPI2X0)

void spi_init(void);
unsigned char SPI_transmit(unsigned char);
unsigned char SPI_receive(void);

#endif
