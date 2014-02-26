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
char sdbuff[512];

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

    DDRC |= 0xFF; //Set Port C pins as outputs
    
    lcd_init(LCD_DISP_ON_CURSOR_BLINK);

    /* Hardware initialisation */
    gps_init(FREQUENCY, MESSAGES);
    
    /* Disable unwanted module */
    PRR0 |= (1<<PRTWI) | (1<<PRTIM0) | (1<<PRTIM2) | (1<<PRTIM1) | (1<<PRADC);

}


// Main function for the whole software
int main(void){

    int i, j, cur_pos_lat, cur_pos_lon;

    _delay_ms(100);
    
    sei();

    initDevices();      // Call initialization function

    lcd_clrscr();
    lcd_home();
    lcd_puts("GPS Logger Project");
    lcd_gotoxy(0,1);
    lcd_puts("By Hidayat and Manu");
    lcd_gotoxy(0,2);
    lcd_puts("Comp Eng HTW Berlin");
    _delay_ms(4500);

    /* SD Initialisation */

    for (i=0; i<10; i++){
    error = SD_init();
    if(!error)
        break;
    }

    if(error){
        _delay_ms(2000);     // Delay before clearing the screen again
        lcd_clrscr();
        lcd_home();
        if(error == 1) lcd_puts("No SD Card detected");
        if(error == 2) lcd_puts("Card init failed");
    }

    error = getBootSectorData (); //read boot sector of SD and keep necessary data in global variables

    if(error){
        lcd_gotoxy(0,1);
        lcd_puts ("FAT32 not found!");  //FAT32 incompatible drive
        _delay_ms(2000);
    }
    else{
        lcd_clrscr();
        lcd_home();
        lcd_puts("Reading from SD.");
        _delay_ms(1000);
        lcd_home();
        lcd_puts("Reading from SD..");
        _delay_ms(1000);
        lcd_home();
        lcd_puts("Reading from SD...");
        _delay_ms(1000);
        lcd_home();
        lcd_puts("Reading from SD....");
        _delay_ms(1000);
    }

    SPI_HIGH_SPEED;   //SCK - 4 MHz as defined in spi.h

    // Keep track of received messages
    uint8_t messageCount = 0;

    /* Read the initial value from SD card and store it in sdbuff[128] */
    error = readFile (READ, "IN", sdbuff);

    if(error){
        lcd_gotoxy(0,1);
        lcd_puts("No init val from SD");
        _delay_ms(3000);
    }
    else{
        lcd_gotoxy(0,1);
        lcd_puts("Read success!");
        _delay_ms(1000);
        lcd_puts("Dest coor from SD");
        lcd_gotoxy(0,1);
        lcd_puts("Lat:");
        lcd_gotoxy(0,2);
        lcd_puts("Lon:");

        for(i=7,cur_pos_lat=4;i<18;i++){
        lcd_gotoxy(cur_pos_lat,1);
        lcd_putc(sdbuff[i]);
        cur_pos_lat++;  
        }
        for(j=19,cur_pos_lon=4;j<31;j++){
            lcd_gotoxy(cur_pos_lon,2);
            lcd_putc(sdbuff[j]);
            cur_pos_lon++;
        }

        _delay_ms(4000);
    }
  
    lcd_clrscr();
    lcd_home();
    lcd_puts("Fetch GPS coor.");
    _delay_ms(1000);
    lcd_clrscr();
    lcd_home();
    lcd_puts("Fetch GPS coor..");
    _delay_ms(1000);
    lcd_clrscr();
    lcd_home();
    lcd_puts("Fetch GPS coor...");
    _delay_ms(1000);
    lcd_clrscr();
    lcd_home();
    lcd_puts("Fetch GPS coor....");
    _delay_ms(1000);

    lcd_clrscr();
    lcd_home();
    lcd_puts("Position");
    lcd_gotoxy(0,1);
    lcd_puts("Dis:");
    lcd_gotoxy(0,2);
    lcd_puts("Lat:");
    lcd_gotoxy(0,3);
    lcd_puts("Lon:");

    while(1) {
        // We'll write the data only if it contains a valid position
        if (gps_getNMEA(nmeabuff, 128) & GPS_NMEA_VALID) {

        	int disp_loop, arr_loop, pos_loop, sd_loop;

            PORTC |= (1<<PORTC0);

            /* Calculating distance */
            getDistance(nmeabuff, sdbuff, pLatGPS, pLongGPS, pLatSD, pLongSD, pDistance);

            //Displaying data on LCD -------
    		for(arr_loop = 0, pos_loop = 4; arr_loop < COORDINATE_BUFFER_SIZE; arr_loop++){
				lcd_gotoxy(pos_loop,2);
				while(!(pLatGPS[arr_loop] == '\0')){
					lcd_putc(pLatGPS[arr_loop]);
					pos_loop++;
				}
			}
			for(arr_loop = 0, pos_loop = 4; arr_loop < COORDINATE_BUFFER_SIZE; arr_loop++){
				lcd_gotoxy(pos_loop,3);
				while(!(pLongGPS[arr_loop] == '\0')){
					lcd_putc(pLongGPS[arr_loop]);
					pos_loop++;
				}
			}
            for(arr_loop = 0, pos_loop = 4; arr_loop < COORDINATE_BUFFER_SIZE; arr_loop++){
                lcd_gotoxy(pos_loop,1);
                while(!(pDistance[arr_loop] == '\0')){
                    lcd_putc(pDistance[arr_loop]);
                    pos_loop++;
                }
            }
            _delay_ms(500);
            // ------------------------------

            /* Logging the data on the SD card */
            for(sd_loop=0; sd_loop < COORDINATE_BUFFER_SIZE; sd_loop++){
                dataString[sd_loop] = pLatGPS[sd_loop];
            }
            dataString[i++] = ',';

            for(i=0; i < COORDINATE_BUFFER_SIZE; i++){
                dataString[sd_loop] = pLongGPS[sd_loop];
            }
            dataString[i++] = ',';

            error = writeFile("OUT");

            if(error){
                PORTC |= (1<<PORTC0);
            }
        }
        sleep_mode();
    }

    return 0;   /* never reached */
}
