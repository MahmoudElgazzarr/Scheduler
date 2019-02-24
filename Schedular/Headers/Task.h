/*
 * Task.h
 *
 * Created: 2/23/2019 2:41:20 PM
 *  Author: AVE-LAP-040
 */ 


#ifndef TASK_H_
#define TASK_H_
#define ZERO 0
#define ONE 1
#define NUM_TASKS 4

/*defines Maxmium Number of Tasks*/
#define MAX_NUM_TASKS 9

void (*tasks[MAX_NUM_TASKS])(void);
void scheduler_Add_Task(void (*Task)(void));

/*Function Definitions */
void led1();
void led2();
void led3();
void led4();


#endif /* TASK_H_ */