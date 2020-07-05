#include "includes.h"

#define  TASK_STK_SIZE                 512       

OS_STK        TaskStartStk[TASK_STK_SIZE];
OS_STK        TaskStartStk1[TASK_STK_SIZE];
OS_STK        TaskStartStk2[TASK_STK_SIZE];

void  TaskStart(void *data);       
void  Task1 (void *pdata);
void  Task2 (void *pdata);

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

	pevent =  OSSemCreate ( 1 );

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

	for (;;) 
	{  
		if (PC_GetKey(&key)) 
		{
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
	INT16U  i;
	INT16U  temp;
	INT8U err;
	OS_EVENT  *pevent = (OS_EVENT*)pdata;

	//for( i=0; i<50; i++ )
	//{  
	OSSemPend (pevent, 0, &err);
	temp = count;
	temp = temp + 1;
	OSTimeDly(200*5);
	count = temp;
	printf("TASK1 : count=%d\n", count );
	OSSemPost( pevent );        
	//}
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

	//for( i=0; i<50; i++ )
	//{  
	OSSemPend(pevent, 200*10,&err); 
	if ( err != OS_TIMEOUT )
	{
		temp = count;
		temp = temp + 1;
		count = temp;
		OSTimeDly(1);
		printf("TASK2 : count=%d\n", count );
		OSSemPost( pevent ); 
	} else {
		printf("TASK2 : OS_TIMEOUT\n" );
	}
	//}
	while(1)
	{
		OSTimeDly(1);
	}
}



