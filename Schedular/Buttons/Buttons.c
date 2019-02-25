/*
 * Buttons.c
 *
 * Created: 2/25/2019 2:25:30 PM
 *  Author: AVE-LAP-040
 */ 

#include "DIO.h"
#include "DIO_Definitions.h"
#include "Buttons.h"

uint8 get_Button1_Status()
{
	uint8 return_value = DIO_ReadPin(Button1);
	return return_value;
}