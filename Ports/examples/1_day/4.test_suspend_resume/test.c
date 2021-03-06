#include "includes.h"

#define  TASK_STK_SIZE                 512 
#define  N_TASKS                        1       

OS_STK        TaskStartStk[TASK_STK_SIZE];
OS_STK        TaskStartStk1[TASK_STK_SIZE];

void  TaskStart(void *data);                  
void  Task1 (void *pdata);

int  main (void)
{

	OSInit();        
	OSTaskCreate(TaskStart, (void *)0, &TaskStartStk[TASK_STK_SIZE - 1], 0);

	sleep(1);
	OSStart();     
	return 0;
}


void  TaskStart (void *pdata)
{
	INT16S     key;
	INT8U      temp[100];

	OSTaskCreateExt(Task1, (void *)0, &TaskStartStk1[TASK_STK_SIZE - 1], 1,
			1000,
			&TaskStartStk1[0],
			TASK_STK_SIZE,
			0,
			OS_TASK_OPT_STK_CHK);

	for (;;) 
	{  
		if (PC_GetKey(&key)) {                             
			if (key == '1') 
			{
				OSTaskSuspend(1);
			}
			if (key == '2') 
			{
				OSTaskResume(1);
			}
			if (key == 0x1B) 
			{                             
				exit(0);
			}
		}
		OSTimeDly(10);
	}
}

void  Task1 (void *pdata)
{
	for (;;)
	{
		printf("Task1\n");
		OSTimeDly(200);
	}
}
