// Most of the code is from https://github.com/marmat/gps-logger/ and edited to suite my purpose


#include <avr/sleep.h>
#include "global.h"
#include "gps.h"

// Set GPS Message update rate to 1 HZ using 9600 as Baudrate
 #define FREQUENCY 1

// Define MESSAGES as GPS_NMEA_GGL since only this message is valid for displaying on LCD, logging into SD Card and also calculating the distance
#define MESSAGES GPS_NMEA_GGL

char nmeaBuf[128];

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
            // code goes here

            /* Displaying data on the LCD */
            // code goes here

            /* logging the data into SD Card */
            // code goes here
        }     
        
        sleep_mode();
    }

    return 0;   /* never reached */
}
