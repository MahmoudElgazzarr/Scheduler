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

/*Global Variable To Set Timer For How Many Ticks*/
volatile static uint16 Tick;
volatile uint16 OS_Tick_in_Timer;

/*Global Setting To Set Timer For 1 MSec on 16 MHZ Crystal*/
void timer_init(uint16 OS_Tick)
{
	/**/
	OS_Tick_in_Timer = OS_Tick;
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
	Tick++;
	if (OS_Tick_in_Timer == Tick)
	{
		/*Call Back Function*/
		Pointer_To_Func();
		/*Set Tick To Zero*/
		Tick = ZERO;
	}
}