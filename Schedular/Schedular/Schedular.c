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



Tasks_T Tasks_Arr[MAX_NUM_TASKS];

void scheduler_Init()
{
	uint32 i;
	for(i=0;i<NUM_TASKS;i++)
	{
		Tasks_Arr[i].Tasks_Ptr = NULL;
		Tasks_Arr[i].Task_Priority = 0;
		Tasks_Arr[i].Task_Periodicity = 0;
		Tasks_Arr[i].Task_Priority = 99;
	}
}

void scheduler_Start()
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
uint8 scheduler_Add_Task(void (*Task)(void),uint32 Periodicity)
{
	if( NUM_TASKS >= MAX_NUM_TASKS )
	{
		return 0;
	}
	else
	{
	Tasks_Arr[Last].Tasks_Ptr = Task;
	Tasks_Arr[Last].Task_Periodicity = Periodicity;
	Last++;
	}
}

void dispatcher(void)
{
	volatile static uint8 NewTickFlag = ZERO ;
	uint32 i,j;
	
	if (1 == flag)
	{
		/* Increment Flag */
		NewTickFlag++;
	
		
	for(j=0;j<NUM_TASKS;j++)
	{
			for(i=1;i<MAX_Periodicity;i++)
		{
			if(Tasks_Arr[j].Task_Periodicity == ( NewTickFlag * i))
			{
				Tasks_Arr[j].Tasks_Ptr();
			}
		}
	}
		if(NewTickFlag == MAX_Periodicity)
		{
			NewTickFlag = 0;
		}
		flag = 0;
	}
}