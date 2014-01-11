// Most of the code is from https://github.com/marmat/gps-logger/ and edited to suite my purpose


#include <avr/sleep.h>
#include "global.h"
#include "gps.h"
#include "calc.h"

// Set GPS Message update rate to 1 HZ using 9600 as Baudrate
 #define FREQUENCY 1

// Define MESSAGES as GPS_NMEA_GGL since only this message is valid for displaying on LCD, logging into SD Card and also calculating the distance
#define MESSAGES GPS_NMEA_GGL

// This array will store the actual value of NMEA message
// recieve from the GPS module.
char nmeaBuf[128];

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

// Main function for the whole software
int main(void)
{

    // Activate interrupts
    sei(); 

    /* Port configuration */
    // code goes here

    /* Disabling unwanted modules */
    // code goes here

    /* Hardware initialisation */
    gps_init(FREQUENCY, MESSAGES);

    // Keep track of received messages
    uint8_t messageCount = 0;

    while(1) {
        // We'll write the data only if it contains a valid position
        if (gps_getNMEA(nmeaBuf, 128) & GPS_NMEA_VALID) {

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
