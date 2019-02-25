/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:13:24 PM
 * Author : AVE-LAP-040
 */ 

#define FIVE_HUNDRED_OS_TICKS 500
#define ONE_OS_TICK 1
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
	scheduler_Add_Task(Task1,FIVE_HUNDRED_OS_TICKS,4);
	scheduler_Add_Task(Task2,FIVE_HUNDRED_OS_TICKS,3);
	scheduler_Add_Task(Task3,FIVE_HUNDRED_OS_TICKS,2);
	scheduler_Add_Task(Task4,FIVE_HUNDRED_OS_TICKS,1);
	
    /* Start Schedular */
	scheduler_Start(ONE_OS_TICK);
	
    while (1)
    {
		
    }
}

