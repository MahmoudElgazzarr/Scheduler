/*
 * Schedular.c
 *
 * Created: 2/23/2019 2:16:23 PM
 *  Author: AVE-LAP-040
 */ 

#include "Timer.h"
#include "Schedular.h"
#include "Task.h"

/*Flag To Be Set In The ISR When Happens*/

volatile uint8 flag = ZERO;

/*Variable To Point To the last Element In the array Of Tasks*/
static volatile uint8 Last;


/*Create Array of Structure To the Tasks*/

Tasks_T Tasks_Arr[MAX_NUM_TASKS];

void scheduler_Init()
{
	uint32 i;
	/*Inialize array of structure With Zero*/
	for(i=ZERO;i<NUM_TASKS;i++)
	{
		Tasks_Arr[i].Tasks_Ptr = NULL;
		Tasks_Arr[i].Task_Priority =ZERO;
		Tasks_Arr[i].Task_Periodicity = ZERO;
		Tasks_Arr[i].Task_Priority = ZERO;
	}
}

void scheduler_Start()
{
	/*Inialize Timer*/
	timer_init();
	/*Set Call_Back_function To The Set Flag*/
	set_Callback_Function(set_flag);
	while(1)
	{
		dispatcher();
	}
}
void static set_flag(void)
{
	if( flag == ZERO)
	{
		flag = ONE;
	}
}
uint8 scheduler_Add_Task(void (*Task)(void),uint32 Periodicity,uint8 priority)
{
		
	/*Index Parmater*/
	uint8 index,indexx;
	Tasks_T Swap_Structure;
	/*If Num of Tasks is Larger Than Max Number Of Tasks return False*/
	if( NUM_TASKS >= MAX_NUM_TASKS )
	{
		return FALSE;
	}
	/*Else set pointer of Function into the Structure
		Set Remaining Ticks With Periodicity
		Increment Last Element of Array Of structure
	*/
	else
	{
	Tasks_Arr[Last].Tasks_Ptr = Task;
	Tasks_Arr[Last].Task_Periodicity = Periodicity;
	Tasks_Arr[Last].Remaining_Ticks = Periodicity;
	Last++;
	/*Sort The Array From Low To High Depend on Priority*/
	
	for(index = ZERO; index < NUM_TASKS;index++)
	{
		for (indexx = ZERO; indexx < NUM_TASKS - ONE;indexx++)
		{
			/*if priority is Inverted*/
			if ( Tasks_Arr[indexx].Task_Priority < Tasks_Arr[indexx + ONE].Task_Priority )
			{
				/*Save Tasks_Array[indexx]*/
				Swap_Structure.Task_Priority = Tasks_Arr[indexx].Task_Priority;
				Swap_Structure.Task_Periodicity = Tasks_Arr[indexx].Task_Periodicity;
				Swap_Structure.Remaining_Ticks = Tasks_Arr[indexx].Remaining_Ticks;
				Swap_Structure.Tasks_Ptr = Tasks_Arr[indexx].Tasks_Ptr;
				
				/* Swap Tasks*/
				Tasks_Arr[indexx].Remaining_Ticks = Tasks_Arr[indexx + 1].Remaining_Ticks;
				Tasks_Arr[indexx].Task_Priority = Tasks_Arr[indexx + 1].Task_Priority;
				Tasks_Arr[indexx].Task_Periodicity = Tasks_Arr[indexx + 1].Task_Periodicity;
				Tasks_Arr[indexx].Tasks_Ptr = Tasks_Arr[indexx+1].Tasks_Ptr;
				
				/*Swap Tasks_Arr[indexx+1]*/
				Tasks_Arr[indexx + 1].Remaining_Ticks = Swap_Structure.Remaining_Ticks;
				Tasks_Arr[indexx + 1].Task_Priority = Swap_Structure.Task_Priority;
				Tasks_Arr[indexx + 1].Task_Periodicity = Swap_Structure.Task_Periodicity;
				Tasks_Arr[indexx+1].Tasks_Ptr = Swap_Structure.Tasks_Ptr;
			}
		}
	}
	return TRUE;
	}
}

void dispatcher(void)
{
	volatile static uint8 NewTickFlag = ZERO ;
	uint32 j;
	/*IF Timer Interrupt Happened Flag Will Be One*/
	if (ONE == flag)
	{
		/* Increment Flag */
		NewTickFlag++;
	/*For Loop For The Tasks and Scheduale Them*/
	for(j=ZERO;j<NUM_TASKS;j++)
	{
		/*Decrement Periodicity by ONE Every Tick */
		Tasks_Arr[j].Remaining_Ticks--;
		/*IF Remaining  Ticks Equals Zero Excute Task and Set Remaining To The Periodicity*/
		if(Tasks_Arr[j].Remaining_Ticks == ZERO )
		{
			/*Call Function*/
			Tasks_Arr[j].Tasks_Ptr();
			/*Set Remaining To The Periodicity*/
			Tasks_Arr[j].Remaining_Ticks = Tasks_Arr[j].Task_Periodicity;
		}
	}
	/*Set Flag To Zero*/
		flag = ZERO;
	}
}