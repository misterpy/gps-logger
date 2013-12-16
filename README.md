gps-logger
==========

Notes
==========
There are three registers for each pin that we will generally be concerned with: Data Direction Register (DDR), Port register (PORT) and Pin register (PIN). 

Setting a bit on DDRD to 1 will make the corresponding pin an output. Setting it to zero would make it an input.

// Set Fuse low byte 0xCD

CKOPT	1
CKSEL3	1
CKSEL2	1
CKSEL1	0
CKSEL0	1
SUT1	0
SUT0	0


// Setting fusebits
// http://www.pocketmagic.net/2013/03/how-to-set-the-avr-fusebits/#.UqDd4bbUMhc
// http://treehouseprojects.ca/fusebits/

// Serial and UART Tutorial http://www.freebsd.org/doc/en_US.ISO8859-1/articles/serial-uart/
// http://extremeelectronics.co.in/avr-tutorials/using-the-usart-of-avr-microcontrollers/
// http://maxembedded.com/2013/09/30/the-usart-of-the-avr/

// Storing data in Program Space http://www.nongnu.org/avr-libc/user-manual/pgmspace.html

#define portlcd PORTA
#define portgps PORTC
#define portcd PORTD

/***** Prototype *****/

/**** LCD *****/
void writelcd();	// Write data to LCD

/***** SD Card *****/
void readsd();		// Read data to SD Card
void writesd();		// Write data to SD Card
void distcalculate();	// Calculate and display distance from GPS in LCD

//Pseudocode for distcalculate
// Check for the destination data from SD Card
//if available
//calculate the distance from from position to destination
//display distance in LCD
//else
	//display error in LCD

/***** GPS Module *****/
void readgps();	// Read data from GPS-Module
void translate();	// Translate NMEA Format to readable format

// We will be reading NMEA Message $GPGLL

main(void){
	

}

/***** End of prototype *****/
