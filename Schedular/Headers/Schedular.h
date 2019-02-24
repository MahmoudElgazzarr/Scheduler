/*
 * Shedular.h
 *
 * Created: 2/23/2019 2:16:44 PM
 *  Author: AVE-LAP-040
 */ 


#ifndef SHEDULAR_H_
#define SHEDULAR_H_

#define OS_TICK_INTERVAL_MSEC 1
#define NUM_TASKS 4
#define MAX_NUM_TASKS 9

#define TRUE 1
#define FALSE 0

typedef struct Tasks_Struct
{
	void (*Tasks_Ptr)(void);
	uint8 Task_Periodicity;
	uint32 Remaining_Ticks;
	uint32 Task_Priority;
}Tasks_T;

void (*tasks[MAX_NUM_TASKS])(void);
uint8 scheduler_Add_Task(void (*Task)(void),uint32 Periodicity);
/*Defines OS Tick Interval*/


void scheduler_Init();
void scheduler_Start();

void dispatcher(void);
void set_flag(void);

#define NULL ((void *)0)
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define TEN 10

#endif /* SHEDULAR_H_ */