// Most of the code is from https://github.com/marmat/gps-logger/ and edited to suite my purpose

#include "uart.h"
#include <avr/interrupt.h>
#include "global.h"


/// FIFO input buffer
static volatile char uart_receiveBuf[UART_RECEIVE_BUFFER_SIZE];
/// Index of the last character that has been read in the input buffer
static volatile uint8_t uart_receiveBufRead = 0;
/// Index of the last charachter that has been written in the input buffer
static volatile uint8_t uart_receiveBufWrite = 0;

/// FIFO output buffer
static volatile char uart_transmitBuf[UART_TRANSMIT_BUFFER_SIZE];
/// Index of the last character that has been read in the output buffer
static volatile uint8_t uart_transmitBufRead = 0;
/// Index of the last character that has been written in the output buffer
static volatile uint8_t uart_transmitBufWrite = 0;

void uart_init(uint16_t pUbr) {
    // write baudrate config (high-byte has to be written first!)
    UBRR1H = (unsigned char)(pUbr>>8);
    UBRR1L = (unsigned char)pUbr;

    // configure port and activate interrupts
    UCSR1B |= (1 << RXCIE1) | (1 << RXEN1) | (1 << TXEN1);

    // the frame configuration is not changed since the default setting is needed
}

unsigned char uart_receiveChar() {
    if (uart_receiveBufRead != uart_receiveBufWrite) {
        // increment reading pointer while catching a possible array overflow
        if (++uart_receiveBufRead >= UART_RECEIVE_BUFFER_SIZE) {
            uart_receiveBufRead = 0;
        }

        return uart_receiveBuf[uart_receiveBufRead];
    }

    return '\0';
}

uint8_t uart_hasData() {
    return uart_receiveBufRead != uart_receiveBufWrite;
}

uint8_t uart_receiveString(char* pResult, uint8_t pResultSize) {
    uint8_t currentChar = 0;
    while(currentChar < pResultSize) {
        pResult[currentChar++] = uart_receiveChar();
        if ((!uart_hasData()) || (pResult[currentChar - 1] == LF)) {
            break;
        }
    }

    pResult[currentChar-1] = '\0';
    if((currentChar > 1) && (pResult[currentChar-2] == CR)) {
        pResult[currentChar-2] = '\0';
    }

    return currentChar;
}

void uart_transmitChar(char pData) {
    // write byte into the output buffer, wait if the buffer is currently full
    if (uart_transmitBufWrite+1 >= UART_TRANSMIT_BUFFER_SIZE) {
        // writing pointer is at the end of the buffer array, next index will be 0
        while (uart_transmitBufRead == 0) {
            // wait, buffer is full
        }

        uart_transmitBufWrite = 0;
    } else {
        while (uart_transmitBufWrite+1 == uart_transmitBufRead) {
            // wait, buffer is full
        }

        uart_transmitBufWrite++;
    }

    // write character into buffer
    uart_transmitBuf[uart_transmitBufWrite] = pData;

    // activate interrupt
    UCSR1B |= (1 << UDRIE1);
}

void uart_transmitString(const char* pData) {
    // simply call transmitChar for each character in the string
    uint8_t i = 0;
    while(pData[i]) {
        uart_transmitChar(pData[i++]);
    }
}

void uart_clearBuf() {
    uart_receiveBufRead = uart_receiveBufWrite;
}

/*
Interrupt handling for incoming UART-data.
The method will write the incoming character directly into the input buffer.
If the buffer is full, characters may be discarded.
*/

ISR(USART1_RX_vect) {
    if(uart_receiveBufWrite+1 >= UART_RECEIVE_BUFFER_SIZE) {
            // writing pointer is at the end of the buffer array, next index will be 0
            if(uart_receiveBufRead != 0) {
                uart_receiveBufWrite = 0;
                uart_receiveBuf[uart_receiveBufWrite] = UDR1;
                return;
            }
    } else {
        if(uart_receiveBufWrite+1 != uart_receiveBufRead) {
            uart_receiveBuf[++uart_receiveBufWrite] = UDR1;
            return;
        }
    }

    // if the method didn't return, it means that the buffer is full
    // discard the byte in order to prevent a blocked UDR register
    char garbage;
    garbage = UDR1;
}

/*
Interrupt handling for outgoing UART-data.
As long as there is data in the output buffer, the method will write the data into the specific UART register. When the buffer is empty, the interrupt will deactivate itself.
*/

ISR(USART1_UDRE_vect) {
    // write next byte until reading index == writing index
    if (uart_transmitBufRead != uart_transmitBufWrite) {
        if (++uart_transmitBufRead >= UART_TRANSMIT_BUFFER_SIZE) {
            uart_transmitBufRead = 0;
        }

        UDR1 = uart_transmitBuf[uart_transmitBufRead];
    } else {
        // buffer empty, deactivate interrupt
        UCSR1B &= ~(1 << UDRIE1);
    }
}
