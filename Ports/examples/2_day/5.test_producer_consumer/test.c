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

typedef struct 
{
	OS_EVENT  *pSem, *pMutex;
} MY_EVENT_DATA;

static int count=0;

int main (void)
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
	INT8U      err;
	MY_EVENT_DATA  event;

	event.pMutex =  OSMutexCreate ( 1, &err );
	event.pSem   =  OSSemCreate (0);

	OSTaskCreateExt(Task1, 
			(void *)&event, 
			&TaskStartStk1[TASK_STK_SIZE - 1], 
			2,
			1000,
			&TaskStartStk1[0],
			TASK_STK_SIZE,
			0,
			OS_TASK_OPT_STK_CHK); 

	OSTaskCreateExt(Task2, 
			(void *)&event, 
			&TaskStartStk2[TASK_STK_SIZE - 1], 
			3,
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
	INT32U  i;
	INT16U  temp;
	INT8U err;
	MY_EVENT_DATA  *pevent = (MY_EVENT_DATA*)pdata;

	while(1)
	{
		OSMutexPend (pevent->pMutex, 0, &err);

		count++;
		printf("생산자 : %d\n", count );

		OSMutexPost (pevent->pMutex);
		OSSemPost( pevent->pSem );

		OSTimeDly(100);
	}
}

void  Task2 (void *pdata)
{
	INT32U  i;
	INT16U  temp;
	INT8U err;
	MY_EVENT_DATA  *pevent = (MY_EVENT_DATA*)pdata;

	while(1)
	{
		OSSemPend( pevent->pSem, 0, &err );
		OSMutexPend (pevent->pMutex, 0, &err);

		printf("\t\t\t소비자 : %d\n", count );

		OSMutexPost (pevent->pMutex);
		OSTimeDly(100);
	}
}


