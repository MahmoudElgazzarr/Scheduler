/*
 * Task.c
 *
 * Created: 2/23/2019 2:39:35 PM
 *  Author: AVE-LAP-040
 */ 

/*We Include Leds Module in App*/
#include "Types.h"
#include "LEDS.h"
#include "Buttons.h"
#include "Schedular.h"
#include "Task.h"

/*Task 1*/	
void Task1()
{
	/*Toggle The Led 1*/
	Led_One_Toggle();
}
/*Task2*/
void Task2()
{
	/*Toggle The Led 2*/
	Led_Two_Toggle();
}
/*Task3*/
void Task3()
{
	/*Toggle The Led 3*/
	Led_Three_Toggle();
}
/*Task 4*/
void Task4()
{
	/*Toggle The Led 4*/
	Led_Four_Toggle();
}

void Task5()
{
	if(get_Button1_Status() == 1)
	{
		scheduler_Remove_Task(3);
	}
}


