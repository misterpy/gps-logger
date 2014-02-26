// SD Card Interfacing - data transfer header

#ifndef SD_H
#define SD_H

//Use following macro if you don't want to activate the multiple block access functions
//those functions are not required for FAT32

#define FAT_TESTING_ONLY

//use following macros if PB1 pin is used for Chip Select of SD
//#define SD_CS_ASSERT     PORTB &= ~0x02
//#define SD_CS_DEASSERT   PORTB |= 0x02

//use following macros if SS (PB4) pin is used for Chip Select of SD
#define SD_CS_ASSERT     PORTB &= ~(1<<PORTB4)
#define SD_CS_DEASSERT   PORTB |= (1<<PORTB4)

//SD commands, not all of which will be used
#define GO_IDLE_STATE            0
#define SEND_OP_COND             1
#define SEND_IF_COND			 8
#define SEND_CSD                 9
#define STOP_TRANSMISSION        12
#define SEND_STATUS              13
#define SET_BLOCK_LEN            16
#define READ_SINGLE_BLOCK        17
#define WRITE_SINGLE_BLOCK       24
#define ERASE_BLOCK_START_ADDR   32
#define ERASE_BLOCK_END_ADDR     33
#define ERASE_SELECTED_BLOCKS    38
#define SD_SEND_OP_COND			 41   //ACMD
#define APP_CMD					 55
#define READ_OCR				 58
#define CRC_ON_OFF               59

#define ON     1
#define OFF    0

#define TX_NEWLINE {uart_transmitChar(0x0d); uart_transmitChar(0x0a);} /*transferred from UART_sd.h*/


volatile unsigned long startBlock, totalBlocks; 
volatile unsigned char SDHC_flag, cardType, buffer[512];

unsigned char SD_init(void);
unsigned char SD_sendCommand(unsigned char cmd, unsigned long arg);
unsigned char SD_readSingleBlock(unsigned long startBlock);
unsigned char SD_writeSingleBlock(unsigned long startBlock);
unsigned char SD_erase (unsigned long startBlock, unsigned long totalBlocks);

#endif
