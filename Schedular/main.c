/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:13:24 PM
 * Author : AVE-LAP-040
 */ 

#define FIVE_HUNDRED_OS_TICKS 500
/*#include <avr/io.h>*/
#include "DIO.h"
#include "DIO_Definitions.h"
#include "Task.h"
#include "Schedular.h"

int main(void)
{
	/*Set Leds As OUTPUt*/
	DIO_SetPinDirection(PIN12,OUTPUT);
	DIO_SetPinDirection(PIN13,OUTPUT);
	DIO_SetPinDirection(PIN14,OUTPUT);
	DIO_SetPinDirection(PIN15,OUTPUT);
	/*Schedular Data Structure Init*/
	scheduler_Init();
	
	/*Add Tasks*/
	uint8 return_value = scheduler_Add_Task(Task1,FIVE_HUNDRED_OS_TICKS);
	if ( return_value == FALSE )
	{
		/*Do Something*/ 
	}
	scheduler_Add_Task(Task2,FIVE_HUNDRED_OS_TICKS);
	if ( return_value == FALSE )
	{
		/*Do Something*/
	}
	scheduler_Add_Task(Task3,FIVE_HUNDRED_OS_TICKS);
	if ( return_value == FALSE )
	{
		/*Do Something*/
	}
	scheduler_Add_Task(Task4,FIVE_HUNDRED_OS_TICKS);
	if ( return_value == FALSE )
	{
		/*Do Something*/
	}
	
    /* Start Schedular */
	scheduler_Start();
	
    while (1)
    {
		
    }
}

