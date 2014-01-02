// Most of the code is from https://github.com/marmat/gps-logger/ and edited to suite my purpose

#ifndef UART_H
#define UART_H

#include "global.h"

#define UART_ASYNC 0x00
#define UART_SYNC 0x40
#define UART_SPI 0xC0

#define UART_8BIT 0x06

// Use 2 stop bits
#define UART_2STOP 0x08

#define UART_NOPAR 0x00
#define UART_EVEN 0x20
#define UART_ODD 0x30

#define UART_0 0
#define UART_1 1

// Size of the input buffer in bytes
#define UART_RECIEVE_BUFFER_SIZE 128
    
// Size of the output buffer in bytes
#define UART_TRANSMIT_BUFFER_SIZE 32

/*
Initializes the UART-port.
Parameter pConfig is the UART configuration byte
Parameter pUbr is a 16-bit integer containing the baudrate configuration value
*/
    void uart_init(uint8_t pConfig, uint16_t pUbr);

/*
Takes a character from the input buffer and returns it (FIFO).
Return the first not yet processed byte
*/
    unsigned char uart_recieveChar();

/*
Takes a string from the input buffer and writes it into pResult.
The string has at most pResultSize - 1 characters. It may have less if a NULL-byte is encountered before. Then the string will be terminated at this point.
Parameter pResult is a pointer to the output array.
Parameter pResultSize is an integer containing the size of the output array.
Return the count of actually returned characters.
*/
    uint8_t uart_recieveString(char* pResult, uint8_t pResultSize);

/*
Checks if there is unprocessed data in the input buffer.
This method can be used in order to prevent a blockage of the cpu when trying to read from an empty input buffer.
Return TRUE if data is available, otherwise FALSE
*/
    uint8_t uart_hasData();

/*
Sends a character.
Parameter pData is the character which will be sent
*/
    void uart_transmitChar(char pData);

/*
Sends a string.
Parameter pData is a pointer to a NULL-terminated character-array with data which will be send.
*/
    void uart_transmitString(const char* pData);

/**
Empties the input buffer, discarding everything inside.
*/
    void uart_clearBuf();
#endif