#include <avr/sleep.h>
#include "global.h"
#include "gps.h"
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

// Main function for the whole software
int main(void){
	
	_delay_ms(100);
	
	// Activate interrupts
	sei();
	
	DDRC |= 0xFF; //Set Port C pins as outputs
	
	lcd_init(LCD_DISP_ON_CURSOR_BLINK);

	/* Hardware initialisation */
	gps_init(FREQUENCY, MESSAGES);
	
	 /* Disabling unwanted modules */
	PRR0 |= (1<<PRTWI) | (1<<PRTIM0) | (1<<PRTIM2) | (1<<PRTIM1) | (1<<PRADC);

	lcd_clrscr();
	lcd_home();
	lcd_puts("GPS Logger Project");
	lcd_gotoxy(0,1);
	lcd_puts("By Hidayat and Manu");
	lcd_gotoxy(0,2);
	lcd_puts("Comp Eng HTW Berlin");
	_delay_ms(4500);

/*	
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
	lcd_puts("Read success!");
	_delay_ms(1000);
	
	lcd_clrscr();
	lcd_home();
	lcd_puts("Init display.");
	_delay_ms(1000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Init display..");
	_delay_ms(1000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Init display...");
	_delay_ms(1000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Init display....");
	_delay_ms(1000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Dest coor from SD");
	lcd_gotoxy(0,1);
	lcd_puts("Lat:");
	lcd_gotoxy(0,2);
	lcd_puts("Lon:");
	_delay_ms(4500);
	
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
	
*/

	lcd_clrscr();
	lcd_home();
	lcd_gotoxy(4,0);
	lcd_puts("Pos and dist");
	lcd_gotoxy(0,1);
	lcd_puts("Dist:");
	lcd_gotoxy(0,2);
	lcd_puts("Lat:");
	lcd_gotoxy(0,3);
	lcd_puts("Lon:");
	_delay_ms(1000);
	
    while(1) {
		int i, j, cur_pos_lat, cur_pos_lon;
		
        // We'll write the data only if it contains a valid position
		/*
        if (gps_getNMEA(nmeabuff, 128) & GPS_NMEA_VALID) {
			PORTC |= (1<<PORTC2);
        }
		*/
		
		if (gps_getNMEA(nmeabuff, 128));
		for(i=7,cur_pos_lat=4;i<18;i++){
			lcd_gotoxy(cur_pos_lat,2);
			lcd_putc(nmeabuff[i]);
			cur_pos_lat++;	
		}
		for(j=19,cur_pos_lon=4;j<31;j++){
			lcd_gotoxy(cur_pos_lon,3);
			lcd_putc(nmeabuff[j]);
			cur_pos_lon++;
		}
		_delay_ms(500);	
        
        sleep_mode();
    }

    return 0;   /* never reached */
}
