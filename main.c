// Most of the code is from https://github.com/marmat/gps-logger/ and edited to suite my purpose


#include <avr/sleep.h>
#include "global.h"
#include "gps.h"
#include "calc.h"
#include "fat32.h"
#include "sd.h"
#include "spi.h"
#include "lcd.h"

// Set GPS Message update rate to 1 HZ using 9600 as Baudrate
#define FREQUENCY 1

// Define MESSAGES as GPS_NMEA_GGL since only this message is valid for displaying on LCD, logging into SD Card and also calculating the distance
#define MESSAGES GPS_NMEA_GLL

// This array will store the actual value of NMEA message
// receive from the GPS module.
char nmeabuff[128];

// This array will store the initial value read from SD Card
char sdbuff[128];

/*
    Value of Latitude, Longitude and distance will be stored here
    for further used such as displaying on the LCD and storing
    into the SD Card
*/
char pLatGPS[COORDINATE_BUFFER_SIZE];
char pLongGPS[COORDINATE_BUFFER_SIZE];

char pLatSD[COORDINATE_BUFFER_SIZE];
char pLongSD[COORDINATE_BUFFER_SIZE];

char pDistance[20];

// Initialize all devices
void initDevices(void) {
    
    spi_init();

    /* Hardware initialisation */
    gps_init(FREQUENCY, MESSAGES);

    /* LCD Initialisation */
    lcd_init(LCD_DISP_ON_CURSOR);

}


// Main function for the whole software
int main(void){

    unsigned char error, i; //used to check for errors in initialization phases

    _delay_ms(100);     //delay for VCC stabilization

    // Activate interrupts
    sei(); 

    /* Port configuration */
    // code goes here

    /* Disabling unwanted modules */
    // code goes here

    initDevices();      // Call initialization function

    /* move cursor to correct position for welcome message*/
    lcd_clrscr();	// Clear screen of LCD
    lcd_home();		// bring cursor to 0,0
    lcd_puts ("--- GPS LOGGER ---");
    lcd_gotoxy(0,1);	// Go to 2nd row 1st column
    lcd_puts("By Hidayat and Manu");
    lcd_gotoxy(0,2);	// Go to 3rd row 1st column
    lcd_puts("CSE2 Projekt, CE");

    /* LCD OUTPUT of the static text: location, destination, distance in rows  */
    // code here

    for (i=0; i<10; i++){
        error = SD_init();
        if(!error)
            break;
    }

    if(error){
        _delay_ms(500);		// Delay before clearing the screen again
        lcd_clrscr();
        lcd_home();
        if(error == 1) lcd_puts("No SD Card detected");    //replace transmitString_F with transmit function that we use to transfer strings to LCD
        if(error == 2) lcd_puts("Card init failed");
        blinkRedLED();  //replace this with our LED function! Do we have LED? XD No we don't!
    }

    error = getBootSectorData (); //read boot sector of SD and keep necessary data in global variables

    if(error){
    	lcd_gotoxy(0,1);
    	lcd_puts ("FAT32 not found!");  //FAT32 incompatible drive
        blinkRedLED();  //replace this with our LED function!
        _delay_ms(500);
    }
    else{
        lcd_clrscr();
        lcd_home();
        lcd_puts("Read from SD...");
        _delay_ms(500);
    }

    SPI_HIGH_SPEED;   //SCK - 4 MHz as defined in spi.h

    // Keep track of received messages
    uint8_t messageCount = 0;

    /* Read the initial value from SD card and store it in sdbuff[128] */
    error = readFile (READ, "in");

	if(error){
		sdbuff = "n/a";
		lcd_gotoxy(0,1);
		lcd_puts("No init val from sd");
		_delay_ms(100);
	}
	else{
		lcd_home();
		lcd_puts("Starting");
        lcd_clrscr();
		lcd_gotoxy(0,1);
		lcd_puts("Lat:");
		lcd_gotoxy(0,2);
		lcd_puts("Lon:");
		lcd_gotoxy(0,3);
		lcd_puts("Dis:");
	}

    while(1) {
        // We'll write the data only if it contains a valid position
        if (gps_getNMEA(nmeabuff, 128) & GPS_NMEA_VALID) {

        	int disp_loop, arr_loop, pos_loop;

            /* Calculating distance */
            getDistance(nmeabuff, sdbuff, pLatGPS, pLongGPS, pLatSD, pLongSD, pDistance);

            /* Displaying data on the LCD */
            for(disp_loop = 0; disp_loop<2; disp_loop++){
            	if(disp_loop == 0){
                    lcd_home();
            		lcd_puts("Destination");
            		for(arr_loop = 0, pos_loop = 4; arr_loop < COORDINATE_BUFFER_SIZE; arr_loop++){
            			lcd_gotoxy(pos_loop,1);
            			while(!(pLatSD(arr_loop) == '\0')){
            				lcd_putc(pLatSD(arr_loop));
            				pos_loop++;
            			}
            		}
            		for(arr_loop = 0, pos_loop = 4; arr_loop < COORDINATE_BUFFER_SIZE; arr_loop++){
            		    lcd_gotoxy(pos_loop,2);
            		    while(!(pLongSD(arr_loop) == '\0')){
            		    	lcd_putc(pLongSD(arr_loop));
            		    	pos_loop++;
            		    }
            		}
            		for(arr_loop = 0, pos_loop = 4; arr_loop < COORDINATE_BUFFER_SIZE; arr_loop++){
            			lcd_gotoxy(pos_loop,3);
            			while(!(pDistance(arr_loop) == '\0')){
            				lcd_putc(pDistance(arr_loop));
            				pos_loop++;
            			}
            		}
            		_delay_ms(400);
            	}
            	else{
            		lcd_home();
            		lcd_puts("Position   ");
            		for(arr_loop = 0, pos_loop = 4; arr_loop < COORDINATE_BUFFER_SIZE; arr_loop++){
						lcd_gotoxy(pos_loop,1);
						while(!(pLatGPS(arr_loop) == '\0')){
							lcd_putc(pLatGPS(arr_loop));
							pos_loop++;
						}
					}
					for(arr_loop = 0, pos_loop = 4; arr_loop < COORDINATE_BUFFER_SIZE; arr_loop++){
						lcd_gotoxy(pos_loop,2);
						while(!(pLongGPS(arr_loop) == '\0')){
							lcd_putc(pLongGPS(arr_loop));
							pos_loop++;
						}
					}
            	}
            	_delay_ms(400);

            }

            /* logging the data into SD Card */
            // code goes here
            // still need to resolve issue with UART function
            // data comes from transmitString buffer, but not ours so far
        }
        
        sleep_mode();
    }

    return 0;   /* never reached */
}
