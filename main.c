/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */

#include <avr/io.h>

int main(void)
{
    /* insert your hardware initialization here */

    while(1) {
        // We'll write the data only if it contains a valid position
        if (gps_getNMEA(nmeaBuf, 128) & GPS_NMEA_VALID) {

            // calculate distance and display in LCD

            // logging the data into SD Card
        }     
        
        sleep_mode();
    }

    return 0;   /* never reached */
}
