/*
 * LEDS.c
 *
 * Created: 2/25/2019 10:07:32 AM
 *  Author: AVE-LAP-040
 */ 

#include "DIO_Definitions.h"

void Led_One_Toggle(void)
{
	DIO_TogglePin(PIN12);
}

void Led_Two_Toggle(void)
{
	DIO_TogglePin(PIN13);
}
void Led_Three_Toggle(void)
{
	DIO_TogglePin(PIN14);
}

void Led_Four_Toggle(void)
{
	DIO_TogglePin(PIN15);
}