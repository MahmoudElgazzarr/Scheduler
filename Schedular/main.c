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
	/*Schedular Data Structure Init*/
	scheduler_Init();
	
	/*Add Tasks*/
	scheduler_Add_Task(Task1,500);
	scheduler_Add_Task(Task2,500);
	scheduler_Add_Task(Task3,500);
	scheduler_Add_Task(Task4,500);
	
    /* Start Schedular */
	scheduler_Start();
	
    while (1)
    {
		
    }
}

