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
volatile uint8 Last = ZERO;

typedef struct Tasks_Struct
{
	void (*Tasks_Ptr)();
	const uint8 Task_Periodicity;
	uint8 remaining_Ticks;
}Tasks_T;

Tasks_T Tasks[MAX_NUM_TASKS];



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
uint8 scheduler_Add_Task(void (*Task)(void))
{
	if( NUM_TASKS >= MAX_NUM_TASKS )
	{
		return 0;
	}
	else
	{
	Tasks[Last].Tasks_Ptr = Task;
	Last++;
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
		Tasks[ZERO].Tasks_Ptr();
		flag = 0;
	}
	else if (NewTickFlag == TWO)
	{
		Tasks[ONE].Tasks_Ptr();
		flag = 0;
	}
	else if (NewTickFlag == THREE)
	{
		Tasks[TWO].Tasks_Ptr();
		flag = 0;
	}
	else if (NewTickFlag == FOUR)
	{
		Tasks[THREE].Tasks_Ptr();
		flag = 0;
	}
	else if (NewTickFlag == FIVE)
	{
		Tasks[FOUR].Tasks_Ptr();
		flag = 0;
	}
	else if (NewTickFlag == SIX)
	{
		Tasks[FIVE].Tasks_Ptr();
		flag = 0;
	}
	}
}