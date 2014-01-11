// SPI Communication protocol header

<<<<<<< HEAD
#ifndef SPI_H
#define SPI_H

#include "global.h"
=======
#ifndef _SPI_H_
#define _SPI_H_
>>>>>>> af97042b507ae4b67adee6171f6223403292c78e

#define SPI_SD             SPCR = 0x52
#define SPI_HIGH_SPEED     SPCR = 0x50; SPSR |= (1<<SPI2X)

void spi_init(void);
unsigned char SPI_transmit(unsigned char);
unsigned char SPI_receive(void);

#endif