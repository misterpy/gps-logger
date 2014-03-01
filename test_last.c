/*----------------------------------------------------------------------*/
/* Foolproof FatFs sample project for AVR              (C)ChaN, 2013    */
/*----------------------------------------------------------------------*/

#include <avr/sleep.h>
#include "global.h"
#include "ff.h"		/* Declarations of FatFs API */
#include "gps.h"
#include "lcd.h"
#include "calc.h"

FATFS FatFs;		/* FatFs work area needed for each volume */
FIL Fil;			/* File object needed for each open file */

// Set GPS Message update rate to 1 HZ using 9600 as Baudrate
#define FREQUENCY 1

// Define MESSAGES as GPS_NMEA_GGL since only this message is valid for displaying on LCD, logging into SD Card and also calculating the distance
#define MESSAGES GPS_NMEA_GLL

// This array will store the actual value of NMEA message
// receive from the GPS module.
BYTE nmeabuff[128];

// This array will store the initial value read from SD Card
BYTE sdbuff[28];

// Value of Latitude, Longitude and distance will be stored here
// for further used such as displaying on the LCD and storing
// into the SD Card

char pLatGPS[20];
char pLongGPS[20];

char pLatSD[20];
char pLongSD[20];

BYTE pDistance[20];

int main (void)
{
	_delay_ms(3000);
	
	sei();
	
	int i, cur_pos_lat, cur_pos_lon, write_pos=0;

	UINT bw;
	DDRC |= 0xFF;

	//Hardware initialisation 
	gps_init(FREQUENCY, MESSAGES);

	lcd_init(LCD_DISP_ON_CURSOR_BLINK);
	
	_delay_ms(1000);

	f_mount(&FatFs, "", 0);		/* Give a work area to the default drive */

	if (f_open(&Fil, "IN.txt", FA_READ | FA_OPEN_EXISTING) == FR_OK) {	/* Read the file from SD */
			
			f_read(&Fil, sdbuff, 28, &bw);
			
			f_close(&Fil);
			
			if(bw == 28){
				PORTC |= (1<<PORTC0);
			}
		}

	/* Disable unwanted module */
	PRR0 |= (1<<PRTWI) | (1<<PRTIM0) | (1<<PRTIM2) | (1<<PRTIM1) | (1<<PRADC);

	lcd_clrscr();
    lcd_home();
    lcd_puts("GPS Logger Project");
    lcd_gotoxy(0,1);
    lcd_puts("By Hidayat and Manu");
    lcd_gotoxy(0,2);
    lcd_puts("Comp Eng HTW Berlin");
    _delay_ms(4500);
	
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
	
	lcd_clrscr();
	lcd_home();
    lcd_puts("Dest coor from SD");
    lcd_gotoxy(0,1);
    lcd_puts("Lat:");
    lcd_gotoxy(0,2);
    lcd_puts("Lon:");

    for(i=7,cur_pos_lat=4;i<17;i++){
    lcd_gotoxy(cur_pos_lat,1);
    lcd_putc(sdbuff[i]);
    cur_pos_lat++;
    }
    for(i=18,cur_pos_lon=4;i<28;i++){
	    lcd_gotoxy(cur_pos_lon,2);
	    lcd_putc(sdbuff[i]);
	    cur_pos_lon++;
    }

    _delay_ms(4000);

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

	while(1) {
        // We'll write the data only if it contains a valid position
        if (gps_getNMEA(nmeabuff, 128) & GPS_NMEA_VALID) {	
			lcd_clrscr();
			lcd_home();
			lcd_puts("Position");
			lcd_gotoxy(0,1);
			lcd_puts("Dis:");
			lcd_gotoxy(0,2);
			lcd_puts("Lat:");
			lcd_gotoxy(0,3);
			lcd_puts("Lon:");
				
        	int arr_loop, pos_loop;

            /* Calculating distance */
            getDistance(nmeabuff, sdbuff, pLatGPS, pLongGPS, pLatSD, pLongSD, pDistance);

            /* Displaying data on LCD */
            for(i=0,cur_pos_lon=4;i<8;i++){
			    lcd_gotoxy(cur_pos_lon,1);
			    lcd_putc(pDistance[i]);
			    cur_pos_lon++;
		    }
			--cur_pos_lon;
			lcd_gotoxy(cur_pos_lon,1);
			lcd_puts("km");

		    PORTC ^= (1<<PORTC1);

            for(i=7,cur_pos_lat=4;i<18;i++){
			    lcd_gotoxy(cur_pos_lat,2);
			    lcd_putc(nmeabuff[i]);
			    cur_pos_lat++;
		    }
		    for(i=19,cur_pos_lon=4;i<31;i++){
			    lcd_gotoxy(cur_pos_lon,3);
			    lcd_putc(nmeabuff[i]);
			    cur_pos_lon++;
		    }

            /* Logging the data on the SD card */
			if (f_open(&Fil, "OUT.txt", FA_WRITE | FA_CREATE_ALWAYS) == FR_OK) {
				f_lseek(&Fil, write_pos);
				f_write(&Fil, nmeabuff, 49, &bw);	/* Write data to the file */
				write_pos += 50;
				f_close(&Fil);
						
				if(bw == 49){
					PORTC ^= (1<<PORTC2);
				}
			}

			_delay_ms(500);
        }
		else{
			lcd_gotoxy(0,1);
			lcd_puts("Waiting for valid");
			lcd_gotoxy(0,2);
			lcd_puts("coor from GPS...");
		}
        sleep_mode();
    }

	    return 0;   /* never reached */
}


/*---------------------------------------------------------*/
/* User Provided RTC Function called by FatFs module       */

DWORD get_fattime (void)
{
	/* Returns current time packed into a DWORD variable */
	return	  ((DWORD)(2013 - 1980) << 25)	/* Year 2013 */
	| ((DWORD)7 << 21)				/* Month 7 */
	| ((DWORD)28 << 16)				/* Mday 28 */
	| ((DWORD)0 << 11)				/* Hour 0 */
	| ((DWORD)0 << 5)				/* Min 0 */
	| ((DWORD)0 >> 1);				/* Sec 0 */
}

