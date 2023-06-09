#include "includes.h"

#define  TASK_STK_SIZE            512    
#define  N_TASKS                    1   

OS_STK        TaskStartStk[TASK_STK_SIZE];

void  TaskStart(void *data);   

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
	INT8U       temp[100];

	OSStatInit();

	printf("TaskStart()\n");
	for (;;) {
		if (PC_GetKey(&key)) 
		{  
			if (key == 0x1B) 
			{   
				exit(0);  
			}
		}

		OSTimeDly(OS_TICKS_PER_SEC);   
		//printf("OSCPUUsage %d%%\n", OSCPUUsage );
		sprintf(temp, "OSCPUUsage %d%%\n", OSCPUUsage );
		PC_DispStr( 3,  3, temp, DISP_FGND_WHITE + DISP_BGND_RED);
	}
}
