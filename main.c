// Most of the code is from https://github.com/marmat/gps-logger/ and edited to suite my purpose


#include <avr/sleep.h>
#include "global.h"
#include "gps.h"
#include "calc.h"
#include "fat32.h"
#include "sd.h"
#include "spi.h"

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
    // code goes here

}


// Main function for the whole software
int main(void){

    unsigned char error, i; //used to check for errors in initialisation phases

    _delay_ms(100);     //delay for VCC stabilization

    // Activate interrupts
    sei(); 

    /* Port configuration */
    // code goes here

    /* Disabling unwanted modules */
    // code goes here

    initDevices();      // Call initalisation function

    /* move cursor to correct position still missing for all LCD Put String functions */
    lcd_puts ("--- GPS LOGGER ---");

    for (i=0; i<10; i++){
        error = SD_init();
        if(!error)
            break;
    }

    if(error){
        if(error == 1) lcd_puts("SD card not detected..");    //replace transmitString_F with transmit function that we use to transfer strings to LCD
        if(error == 2) lcd_puts("Card Initialization failed..");
        blinkRedLED();  //replace this with our LED function!
    }

    error = getBootSectorData (); //read boot sector of SD and keep necessary data in global variables

    if(error){
    	lcd_puts ("\n\rFAT32 not found!");  //FAT32 incompatible drive
        blinkRedLED();  //replace this with our LED function!
    }

    SPI_HIGH_SPEED;   //SCK - 4 MHz as defined in spi.h

    // Keep track of received messages
    uint8_t messageCount = 0;

    /* Read the initial value from SD card and store it in sdbuff[128] */
    error = readFile (READ, "in");

	if(error){
		sdbuff = "n/a";
	}

    while(1) {
        // We'll write the data only if it contains a valid position
        if (gps_getNMEA(nmeabuff, 128) & GPS_NMEA_VALID) {

            /* Calculating distance */
            getDistance(nmeabuff, sdbuff, pLatGPS, pLongGPS, pLatSD, pLongSD, pDistance);

            /* Displaying data on the LCD */
            // code goes here

            /* logging the data into SD Card */
            // code goes here
        }     
        
        sleep_mode();
    }

    return 0;   /* never reached */
}
