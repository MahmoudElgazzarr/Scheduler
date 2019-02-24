/*
 * delay_Timer.c
 *
 * Created: 2/14/2019 10:06:23 AM
 *  Author: AVE-LAP-040
 */ 

#include "Types.h"
#include "Timer.h"
#include "avr/interrupt.h"

void (*Pointer_To_Func)(void);
uint8 Tick;
/*Global Setting To Set Timer For 1 MSec on 16 MHZ Crystal*/


void timer_init(void)
{
	/**/
	/*Enable Global Interrupt*/
	SREG |= (1<<IBIT);
	/*Enable Timer 0*/
	TIMSK |=(1<<OCIE0);
	/*Define Values To Timer To be 1 mSec*/
	TCNT0 = 0 ;
	OCR0 = 249 ;
	/*Prescaler 64*/
	TCCR0 |= (1<<CS00)|(1<<CS01)|(1<<WGM01);
}

void set_Callback_Function(void (*ptr)(void))
{
	Pointer_To_Func = ptr;
}
ISR(TIMER0_COMP_vect)
{
	if (1 == OS_TICK_INTERVAL_MSEC)
	{
		Pointer_To_Func();
	}
	if (2 == OS_TICK_INTERVAL_MSEC)
	{
		Tick++;
	}
	if(2 == Tick)
	{
		Tick = 0;
		Pointer_To_Func();
	}
}