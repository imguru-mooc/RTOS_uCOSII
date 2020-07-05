#include "includes.h"

#define  TASK_STK_SIZE            512    

OS_STK        TaskStartStk[TASK_STK_SIZE];
OS_STK        TaskStartStk1[TASK_STK_SIZE];
OS_STK        TaskStartStk2[TASK_STK_SIZE];

void  TaskStart(void *data);   
void  Task1 (void *pdata);
void  Task2 (void *pdata);

int  main(void)
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
	OS_EVENT  *pevent;

	pevent = OSMboxCreate ( 0 );

	OSTaskCreateExt(Task1, (void *)pevent, 
			&TaskStartStk1[TASK_STK_SIZE - 1], 1,
			1000,
			&TaskStartStk1[0],
			TASK_STK_SIZE,
			0,
			OS_TASK_OPT_STK_CHK);

	OSTaskCreateExt(Task2, (void *)pevent, 
			&TaskStartStk2[TASK_STK_SIZE - 1], 2,
			1000,
			&TaskStartStk2[0],
			TASK_STK_SIZE,
			0,
			OS_TASK_OPT_STK_CHK);

	for (;;) {
		if (PC_GetKey(&key)) 
		{  
			if (key == '1')
			{
				OSMboxPostOpt(pevent,"hello",OS_POST_OPT_BROADCAST);
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
	OS_EVENT  *pevent = (OS_EVENT*)pdata;
	char *msg;

	//OSTimeDly(200*5);
	msg = OSMboxPend(pevent, 0, &err);
	printf("Task1 수신 : %s\n", msg );

	while(1)
	{
		OSTimeDly(1);
	}
}

void  Task2 (void *pdata)
{
	INT8U err;
	char *msg;
	OS_EVENT  *pevent = (OS_EVENT*)pdata;

	//OSTimeDly(200*5);
	msg = OSMboxPend(pevent, 0, &err);
	printf("Task2 수신 : %s\n", msg );

	while(1)
	{
		OSTimeDly(1);
	}
}
