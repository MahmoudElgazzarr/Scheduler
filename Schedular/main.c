/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:13:24 PM
 * Author : AVE-LAP-040
 */ 

/*#include <avr/io.h>*/
#include "DIO.h"
#include "DIO_Definitions.h"
#include "Task.h"

int main(void)
{
	/*Set Leds As OUTPUt*/
	DIO_SetPinDirection(PIN12,OUTPUT);
	DIO_SetPinDirection(PIN13,OUTPUT);
	DIO_SetPinDirection(PIN14,OUTPUT);
	DIO_SetPinDirection(PIN15,OUTPUT);
	
	/*Add Tasks*/
	scheduler_Add_Task(led1);
	scheduler_Add_Task(led2);
	scheduler_Add_Task(led3);
	scheduler_Add_Task(led4);
	
    /* Start Schedular */
	schedulerInit_AndStart();
	
    while (1)
    {
		
    }
}

