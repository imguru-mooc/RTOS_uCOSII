#include "includes.h"

#define  TASK_STK_SIZE                 512 

OS_STK        TaskStartStk[TASK_STK_SIZE];
OS_STK        TaskStartStk1[TASK_STK_SIZE];
OS_STK        TaskStartStk2[TASK_STK_SIZE];
OS_STK        TaskStartStk3[TASK_STK_SIZE];

void  TaskStart(void *data);                  
void  Task1 (void *pdata);
void  Task2 (void *pdata);
void  Task3 (void *pdata);

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
	INT8U      err;
    INT16S     key, flag=0;
	OS_FLAG_GRP    *pgrp;

	pgrp  = OSFlagCreate(0, &err);
	OSTaskCreateExt(Task1, (void *)pgrp, 
			&TaskStartStk1[TASK_STK_SIZE - 1], 1,
			1000,
			&TaskStartStk1[0],
			TASK_STK_SIZE,
			0,
			OS_TASK_OPT_STK_CHK);

	OSTaskCreateExt(Task2, (void *)pgrp, 
			&TaskStartStk2[TASK_STK_SIZE - 1], 2,
			1000,
			&TaskStartStk2[0],
			TASK_STK_SIZE,
			0,
			OS_TASK_OPT_STK_CHK);

	for (;;) 
	{  
		if (PC_GetKey(&key)) {                             
			if (key >= '1' && key <= '9' )
			{
				flag |= key - '0';
				printf("%c\n", key );
				OSFlagPost(pgrp, flag, OS_FLAG_SET, &err );
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
	INT8U err;
	OS_FLAG_GRP  *pgrp = (OS_FLAG_GRP *)pdata;

	OSFlagPend (pgrp, 0x3, OS_FLAG_WAIT_SET_ALL, 0, &err);

	printf("TASK1 : 소비 하다\n" );

	while(1)
	{
		OSTimeDly(1);
	}
}


void  Task2 (void *pdata)
{
	INT8U err;
	OS_FLAG_GRP  *pgrp = (OS_FLAG_GRP *)pdata;

	OSFlagPend (pgrp, 0xc, OS_FLAG_WAIT_SET_ANY, 0, &err);

	printf("TASK2 : 소비 하다\n" );

	while(1)
	{
		OSTimeDly(1);
	}
}
