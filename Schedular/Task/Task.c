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
	count_led1++;
	if(count_led1 == 250)
	{
		DIO_WritePin(PIN12,HIGH);
	}
	else if (count_led1 == 500 )
	{
		DIO_WritePin(PIN12,LOW);
		count_led1 = 0;
	}
	
}
void led2()
{
		count_led2++;
		if(count_led2 == 250)
		{
			DIO_WritePin(PIN13,HIGH);
		}
		else if (count_led2 == 500 )
		{
			DIO_WritePin(PIN13,LOW);
			count_led2=0;
		}
}
void led3()
{
		count_led3++;
		if(count_led3 == 250)
		{
			DIO_WritePin(PIN14,HIGH);
		}
		else if (count_led3 == 500 )
		{
			DIO_WritePin(PIN14,LOW);
			count_led3 = 0;
		}
}

void led4()
{
		count_led4++;
		if(count_led4 == 250)
		{
			DIO_WritePin(PIN15,HIGH);
		}
		else if (count_led4 == 500 )
		{
			DIO_WritePin(PIN15,LOW);
			count_led4 = 0;
		}
}


