#include "includes.h"

#define  TASK_STK_SIZE                 512 

OS_STK        TaskStartStk[TASK_STK_SIZE];
OS_STK        TaskStartStk1[TASK_STK_SIZE];
OS_STK        TaskStartStk2[TASK_STK_SIZE];

void  TaskStart(void *data);                  
void  Task1 (void *pdata);
void  Task2 (void *pdata);

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

	OSTaskCreateExt(Task2, (void *)0, &TaskStartStk2[TASK_STK_SIZE - 1], 2,
			1000,
			&TaskStartStk2[0],
			TASK_STK_SIZE,
			0,
			OS_TASK_OPT_STK_CHK);

	for (;;) 
	{  
		if (PC_GetKey(&key)) {                             
			if (key == '1') 
			{
				//OSTaskDel(1);
				OSTaskDelReq(1);
			}
			if (key == '2') 
			{
				OSTaskChangePrio(3, 1);
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
	char *temp;
	temp = malloc( 100 );
	pdata = pdata;
	for (;;)
	{
		if( OSTaskDelReq(OS_PRIO_SELF)==OS_TASK_DEL_REQ )
		{
			free(temp);
			OSTaskDel(OS_PRIO_SELF);
		}
		printf("Task1\n");
		OSTimeDly(200);
	}
}

void  Task2 (void *pdata)
{
	pdata = pdata;
	for (;;)
	{
		printf("\t\tTask2\n");
		OSTimeDly(200);
	}
}
