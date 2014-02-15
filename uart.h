// Most of the code is from https://github.com/marmat/gps-logger/ and edited to suite my purpose

#ifndef UART_H
#define UART_H

#define UART_ASYNC 0x00
#define UART_SYNC 0x40
#define UART_SPI 0xC0

#define UART_8BIT 0x06

// Use 1 stop bits
#define UART_1STOP 0x00

#define UART_NOPAR 0x00
#define UART_EVEN 0x20
#define UART_ODD 0x30

#define UART_0 0
#define UART_1 1

// Size of the input buffer in bytes
#define UART_RECEIVE_BUFFER_SIZE 128
    
// Size of the output buffer in bytes
#define UART_TRANSMIT_BUFFER_SIZE 32

/// Macro which generates a configuration byte for the UART register
#define UART_CONFIGURE(pMode, pBits, pStop, pParity) pMode | pBits | pStop | pParity

/// Macro which calculates the correct value for the baudrate register
#define UART_CALCULATE_BAUD(pFrequency, pBaudrate) (pFrequency / (16 * pBaudrate)) - 1

/// Macro for sending a "new line"-sequence
#define UART_NEWLINE() uart_setChar(CR); uart_setChar(LF);

/*
Initializes the UART-port.
Parameter pConfig is the UART configuration byte
Parameter pUbr is a 16-bit integer containing the baudrate configuration value
*/
    void uart_init(unsigned int pUbr);

/*
Takes a character from the input buffer and returns it (FIFO).
Return the first not yet processed byte
*/
    unsigned char uart_receiveChar();

/*
Takes a string from the input buffer and writes it into pResult.
The string has at most pResultSize - 1 characters. It may have less if a NULL-byte is encountered before. Then the string will be terminated at this point.
Parameter pResult is a pointer to the output array.
Parameter pResultSize is an integer containing the size of the output array.
Return the count of actually returned characters.
*/
    unsigned char uart_receiveString(char* pResult, unsigned char pResultSize);

/*
Checks if there is unprocessed data in the input buffer.
This method can be used in order to prevent a blockage of the cpu when trying to read from an empty input buffer.
Return TRUE if data is available, otherwise FALSE
*/
    unsigned char uart_hasData();

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
