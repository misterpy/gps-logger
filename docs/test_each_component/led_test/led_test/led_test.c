/*
 * led_test.c
 *
 * Created: 2/21/2014 11:53:42 PM
 *  Author: Hidayat Halim
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	cli();	//Disable global interrupts
	TCCR1B |= 1<< CS11 | 1<<CS10; //Divide by 11
	OCR1A = 15624; //Count 15624 cycles for 1 second interrupt
	TCCR1B |= 1<<WGM12; //Put Timer/Counter1 in CTC mode
	TIMSK1 |= 1<<OCIE1A; //Enable timer compare interrupt
	sei();

	//Setup the I/O for LEDs
	
	DDRC |= 0xFF; // Set PortC pins as outputs
	PORTC |= (1<<PORTC0); // Set Ports pins high to turn on all LEDs
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}


ISR(TIMER1_COMPA_vect) //Interrupt Service Routine
{
	PORTC ^= 0xFF;	//Use xor to toggle the LEDs
}
