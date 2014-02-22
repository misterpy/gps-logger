/*
 * led_test.c
 *
 * Created: 2/21/2014 11:53:42 PM
 *  Author: Hidayat Halim
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	
	lcd_init(LCD_DISP_ON_CURSOR_BLINK);
	//Setup the I/O for LEDs and turn it on if lcd_init is successful
	//DDRC |= 0xFF; // Set PortC pins as outputs
	//PORTC |= (1<<PORTC0); // Set Ports pins high to turn on all LEDs
	
	lcd_clrscr();
	lcd_home();
	lcd_puts("GPS Logger Project");
	lcd_gotoxy(0,1);
	lcd_puts("By Hidayat and Manu");
	lcd_gotoxy(0,2);
	lcd_puts("Comp Eng HTW Berlin");
	_delay_ms(30000);
	
	lcd_clrscr();
	lcd_home();
	lcd_puts("Reading from SD.");
	_delay_ms(10000);
	lcd_home();
	lcd_puts("Reading from SD..");
	_delay_ms(10000);
	lcd_home();
	lcd_puts("Reading from SD...");
	_delay_ms(10000);
	lcd_home();
	lcd_puts("Reading from SD....");
	_delay_ms(10000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Read success!");
	_delay_ms(10000);
	
	lcd_clrscr();
	lcd_home();
	lcd_puts("Init display.");
	_delay_ms(10000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Init display..");
	_delay_ms(10000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Init display...");
	_delay_ms(10000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Init display....");
	_delay_ms(10000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Dest coor from SD");
	lcd_gotoxy(0,1);
	lcd_puts("Lat:");
	lcd_gotoxy(0,2);
	lcd_puts("Lon:");
	_delay_ms(30000);
	
	lcd_clrscr();
	lcd_home();
	lcd_puts("Fetch GPS coor.");
	_delay_ms(10000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Fetch GPS coor..");
	_delay_ms(10000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Fetch GPS coor...");
	_delay_ms(10000);
	lcd_clrscr();
	lcd_home();
	lcd_puts("Fetch GPS coor....");
	_delay_ms(10000);
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
	_delay_ms(10000);
	
	
    while(1)
    {
		
		//PORTC |= (1<<PORTC1);
		_delay_ms(10000);
		//lcd_clrscr();
    }
}