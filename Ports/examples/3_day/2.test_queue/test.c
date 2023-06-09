#include "includes.h"

#define  TASK_STK_SIZE                 512 

OS_STK        TaskStartStk[TASK_STK_SIZE];
OS_STK        TaskStartStk1[TASK_STK_SIZE];
OS_STK        TaskStartStk2[TASK_STK_SIZE];

void  TaskStart(void *data);                  
void  Task1 (void *pdata);
void  Task2 (void *pdata);

typedef struct
{
	INT16S    key;
	INT32U    cur;
} KEY_EVENT;

static KEY_EVENT  my_mem[100];
static OS_MEM  *pmem;

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
	KEY_EVENT  *temp;
	KEY_EVENT  *my_queue[8];
	OS_EVENT  *pevent;
	INT8U err;

	pevent =  OSQCreate ( (void**)my_queue , 8 );
	pmem   = OSMemCreate( my_mem, 100, sizeof(KEY_EVENT), &err );

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
	for (;;) 
	{  
		if (PC_GetKey(&key)) {                             
			if (key >=  'a'  &&  key <= 'z' )
			{
				// ASCII 코드='1' , 시간=OS_TIME
				temp = OSMemGet( pmem, &err );
				temp->key = key;
				temp->cur = OSTimeGet();
				OSQPost( pevent, temp );
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
	INT16U  i;
	INT16U  temp;
	INT8U err;
	OS_EVENT  *pevent = (OS_EVENT*)pdata;
	KEY_EVENT *e;

	while(1)
	{
		e = OSQPend(pevent, 0, &err);
		printf("Task1 수신 : %c, %ld\n", e->key - ('a' - 'A'), e->cur );
		OSMemPut( pmem, e );
		OSTimeDly(1);
	}
}

void  Task2 (void *pdata)
{
	INT16U  i;
	INT16U  temp;
	INT8U err;
	char *msg;

	//   OS_EVENT  *pevent = (OS_EVENT*)pdata;

	//	OSTimeDly(200*2);
	//	msg = OSQPend(pevent, 0, &err);
	//    printf("Task2 수신 : %s\n", msg );

	while(1)
	{
		OSTimeDly(1);
	}
}

