/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:16:23 PM
 *  Author: AVE-LAP-040
 */ 
#include "Timer.h"
#include "Schedular.h"
#include "Task.h"

/*void ((*arr_To_Functions[])(void));*/

volatile uint8 flag = 0;

void schedulerInit_AndStart()
{
	timer_init();
	set_Callback_Function(set_flag);
	while(1)
	{
		dispatcher();
	}
}
void set_flag(void)
{
	if( flag == 0)
	{
		flag = 1;
	}
}
void dispatcher(void)
{
	volatile static uint8 NewTickFlag = ZERO ;
	if (1 == flag)
	{
	NewTickFlag++;
	
	if (NewTickFlag == NUM_TASKS + 1 )
	{
		NewTickFlag = ONE;
		flag = 0;
	}

	if(NewTickFlag == ONE)
	{
		tasks[ZERO]();
		flag = 0;
	}
	else if (NewTickFlag == TWO)
	{
		tasks[ONE]();
		flag = 0;
	}
	else if (NewTickFlag == THREE)
	{
		tasks[TWO]();
		flag = 0;
	}
	else if (NewTickFlag == FOUR)
	{
		tasks[THREE]();
		flag = 0;
	}
	else if (NewTickFlag == FIVE)
	{
		tasks[FOUR]();
		flag = 0;
	}
	else if (NewTickFlag == SIX)
	{
		tasks[FIVE]();
		flag = 0;
	}
	}
}