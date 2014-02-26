/*----------------------------------------------------------------------*/
/* Foolproof FatFs sample project for AVR              (C)ChaN, 2013    */
/*----------------------------------------------------------------------*/

#include <avr/io.h>	/* Device specific declarations */
#include "ff.h"		/* Declarations of FatFs API */

FATFS FatFs;		/* FatFs work area needed for each volume */
FIL Fil;			/* File object needed for each open file */
BYTE sdbuff[28];

int main (void)
{
	UINT bw1,bw2;
	DDRC |= 0xFF;
	
	int write_pos;

	f_mount(&FatFs, "", 0);		/* Give a work area to the default drive */
	
	if (f_open(&Fil, "IN.txt", FA_READ | FA_OPEN_EXISTING) == FR_OK) {	/* Read the file from SD */
		
		PORTC |= (1<<PORTC0);
		
		f_read(&Fil, sdbuff, 28, &bw1);
		
		f_close(&Fil);
		
		if(bw1 == 28){
			//PORTC |= ~(1<<PORTC0);
		}
		
		if (f_open(&Fil, "OUT.txt", FA_WRITE | FA_CREATE_ALWAYS) == FR_OK) {
			f_lseek(&Fil, write_pos);
			f_write(&Fil, sdbuff, 28, &bw2);	/* Write data to the file */
			write_pos += 28;
			f_close(&Fil);
			
			if(bw2 == 28){
				PORTC |= (1<<PORTC1);
			}
		}
		
	}

	for (;;) ;
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

