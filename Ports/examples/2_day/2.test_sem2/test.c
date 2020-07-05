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

static INT16U  count=0;

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
	OS_EVENT  *pevent;

	pevent =  OSSemCreate ( 2 );

	OSTaskCreateExt(
			Task1, 
			(void *)pevent, 
			&TaskStartStk1[TASK_STK_SIZE - 1], 
			1,
			1000,
			&TaskStartStk1[0],
			TASK_STK_SIZE,
			0,
			OS_TASK_OPT_STK_CHK); 

	OSTaskCreateExt(
			Task2, 
			(void *)pevent, 
			&TaskStartStk2[TASK_STK_SIZE - 1], 
			2,
			1000,
			&TaskStartStk2[0],
			TASK_STK_SIZE,
			0,
			OS_TASK_OPT_STK_CHK); 

	OSTaskCreateExt(
			Task3, 
			(void *)pevent, 
			&TaskStartStk3[TASK_STK_SIZE - 1], 
			3,
			1000,
			&TaskStartStk3[0],
			TASK_STK_SIZE,
			0,
			OS_TASK_OPT_STK_CHK); 

	for (;;) 
	{  
		if (PC_GetKey(&key)) 
		{
			if (key == '1') 
			{
				OSTaskDel(1);
			}
			if (key == 0x1B) { 
				exit(0); 
			}
		}
		OSTimeDly(10);
	}
}


void  Task1 (void *pdata)
{
	INT16U  i;
	INT16U  temp;
	INT8U err;
	OS_EVENT  *pevent = (OS_EVENT*)pdata;


	OSSemPend (pevent, 0, &err);

	printf("TASK1 : 임계영역 진입\n" );

	while(1)
	{
		OSTimeDly(1);
	}
}

void  Task2 (void *pdata)
{
	INT16U  i;
	INT16U  temp;
	INT8U err;
    OS_EVENT  *pevent = (OS_EVENT*)pdata;

	OSSemPend (pevent, 0, &err);

	printf("TASK2 : 임계영역 진입\n" );

	while(1)
	{
		OSTimeDly(1);
	}
}

void  Task3 (void *pdata)
{
	INT16U  i;
	INT16U  temp;
	INT8U err;
    OS_EVENT  *pevent = (OS_EVENT*)pdata;

	OSSemPend (pevent, 0, &err);

	printf("TASK3 : 임계영역 진입\n" );

	while(1)
	{
		OSTimeDly(1);
	}
}



