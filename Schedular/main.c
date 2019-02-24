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
#include "Schedular.h"

int main(void)
{
	/*Set Leds As OUTPUt*/
	DIO_SetPinDirection(PIN12,OUTPUT);
	DIO_SetPinDirection(PIN13,OUTPUT);
	DIO_SetPinDirection(PIN14,OUTPUT);
	DIO_SetPinDirection(PIN15,OUTPUT);
	/*Schdular Data Structure Init*/
	scheduler_Init();
	
	/*Add Tasks*/
	scheduler_Add_Task(led1,1000);
	scheduler_Add_Task(led2,1000);
	scheduler_Add_Task(led3,1000);
	scheduler_Add_Task(led4,1000);
	/**/
    /* Start Schedular */
	scheduler_Start();
	
    while (1)
    {
		
    }
}

