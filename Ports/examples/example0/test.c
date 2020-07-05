#include "includes.h"

#define TASK_STK_SIZE   1024  

int kbhit();

OS_STK  TestTaskStk1[TASK_STK_SIZE];      
OS_STK  TestTaskStk2[TASK_STK_SIZE];
OS_STK  TestTaskStk3[TASK_STK_SIZE];
OS_STK  TestTaskStk4[TASK_STK_SIZE];

void TestTask1(void *pdata);   
void TestTask2(void *pdata);
void TestTask3(void *pdata);
void TestTask4(void *pdata);
void OurIsr1(void);     

int main()
{
	OSInit();    
	OSTaskCreate(TestTask1, (void *) 11, &TestTaskStk1[TASK_STK_SIZE], 11); 

	PC_IntVectSet(1, OurIsr1);    

	sleep(1);
	OSStart();                                

	printf("main(): We should never execute this line\n");

	return 0;
}


void TestTask1(void *pdata)
{   
	printf("%4lu: ***** Test Task 1 First call *****\n", OSTime);

#if OS_TASK_STAT_EN > 0
	OSStatInit();    
#endif

	OSTaskCreate(TestTask2, (void *) 22, &TestTaskStk2[TASK_STK_SIZE], 22);     
	OSTaskCreate(TestTask3, (void *) 33, &TestTaskStk3[TASK_STK_SIZE], 33);
	OSTaskCreate(TestTask4, (void *) 10, &TestTaskStk3[TASK_STK_SIZE], 10);

	while (1)
	{   
		printf("%4lu: ***** Test Task 11 *****\n", OSTime);

#ifdef SUSPEND_RESUME
		OSTaskSuspend(OS_PRIO_SELF);     
#else
		OSTimeDly(100);    
#endif
	}
}

void TestTask2(void *pdata)
{   
	while (1)
	{   printf("%4lu: ***** Test Task 22 *****\n", OSTime);

#ifdef SUSPEND_RESUME
		OSTaskSuspend(OS_PRIO_SELF);
#else
		OSTimeDly(50);
#endif
	}
}

void TestTask3(void *pdata)
{   
	while (1)
	{
#ifdef SUSPEND_RESUME
		printf("%4lu: ***** Test Task 33 *****\n", OSTime);
		OSTaskResume(11);

		printf("%4lu: ***** Test Task 33 *****\n", OSTime);
		OSTaskResume(22);
#endif
		printf("%4lu: ***** Test Task 33 *****\n", OSTime);
		OSTimeDly(200);

		if (kbhit())
			exit(0);
	}
}

void TestTask4(void *pdata)
{   
	while (1)
	{
		printf("%4lu: +++++ Test Task 40 +++++\n", OSTime);
		OSTaskSuspend(10);    
	}
}


void OurIsr1(void)
{       
	OSIntEnter();
	printf("##### Interrupt service routine for IRQ 1 #####\n");
	OSTaskResume(10);    
	OSIntExit();
}
