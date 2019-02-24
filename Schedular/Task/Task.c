/*
 * Task.c
 *
 * Created: 2/23/2019 2:39:35 PM
 *  Author: AVE-LAP-040
 */ 
#include "Task.h"
#include "DIO_Definitions.h"
#include "DIO.h"

static volatile uint16 count_led1=0;
static volatile uint16 count_led2=0;
static volatile uint16 count_led3=0;
static volatile uint16 count_led4=0;
	
void led1()
{
	DIO_TogglePin(PIN12);
}
void led2()
{
	DIO_TogglePin(PIN13);
}
void led3()
{
	DIO_TogglePin(PIN14);
}

void led4()
{
	DIO_TogglePin(PIN15);
}


