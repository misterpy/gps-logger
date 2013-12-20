#ifndef GLOBAL_H
	#define GLOBAL_H

	#ifndef F_CPU
		//	CPU Frequency, based on the external oscillator 7,3728MHz (baud-rate crystal)
		#define 7372800UL
	#endif

	#define TRUE 1
	
	#define FALSE 0

	#include <stdint.h>
    #include <stdlib.h>
    #include <avr/io.h>
    #include <avr/interrupt.h>
    #include <util/delay.h>

#endif
