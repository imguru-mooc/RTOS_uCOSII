#include "includes.h"

#define  TASK_STK_SIZE            512    

OS_STK        TaskStartStk[TASK_STK_SIZE];
OS_STK        TaskStartStk1[TASK_STK_SIZE];
OS_STK        TaskStartStk2[TASK_STK_SIZE];

void  TaskStart(void *data);   
void  Task1 (void *pdata);
void  Task2 (void *pdata);

typedef struct devinfo
{
	int temp;
	INT32U current; 
} DEV_INFO;

DEV_INFO dev_info;

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
			if (key >=  '1' && key <= '9' )
			{
				int temp;
				temp = key - '0';
				dev_info.temp = temp;
				dev_info.current = OSTime;
				OSMboxPostOpt(pevent,&dev_info,OS_POST_OPT_BROADCAST);
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
	DEV_INFO *info;

	//OSTimeDly(200*5);
	while(1)
	{
		info = OSMboxPend(pevent, 0, &err);
		printf("Task1 수신 : 온도:%d, 시간:%lu\n", info->temp, info->current );

		OSTimeDly(1);
	}
}

void  Task2 (void *pdata)
{
	INT8U err;
	DEV_INFO *info;
	OS_EVENT  *pevent = (OS_EVENT*)pdata;

	while(1)
	{
		//OSTimeDly(200*5);
		info = OSMboxPend(pevent, 0, &err);
		printf("Task2 수신 : 온도:%d, 시간:%lu\n", info->temp, info->current );

		OSTimeDly(1);
	}
}
