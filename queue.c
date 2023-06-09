#if 1
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct 
{
	int data[MAX];
	int front;
	int rear;
} QUEUE;


int is_empty(QUEUE *q)
{
	return q->rear == q->front ;
}

int is_full(QUEUE *q)
{
	return (q->rear+1)%MAX == q->front ;
}

void put(QUEUE *q, int data)
{
	q->data[q->rear] = data;
	q->rear = (q->rear+1)%MAX ;
}

int get(QUEUE *q)
{
	int temp = q->data[q->front];
	q->front = (q->front+1)%MAX ;
	return temp;
}

void display(QUEUE *q)
{
	int i;
	system("clear");
	for(i=0; i<q->front; i++)
		printf("%4c", ' ');
	printf("front\n");

	for(i=0; i<q->front; i++)
		printf("%4c", ' ');
	printf("   |\n");

	for(i=0; i<MAX; i++)
		printf("%4d", q->data[i]);
	printf("\n");

	for(i=0; i<q->rear; i++)
		printf("%4c", ' ');
	printf("   |\n");
	for(i=0; i<q->rear; i++)
		printf("%4c", ' ');
	printf("rear\n");
	getchar();
}

int main()
{
	int i;
	QUEUE queue = {0,};
	display(&queue);
	for(i=0; i<7; i++ )
	{
		put(&queue,i+1);
		display(&queue);
	}
	
	for(i=0; i<7; i++ )
	{
		printf("%d\n", get(&queue));
		display(&queue);
	}
		
	for(i=0; i<7; i++ )
	{
		put(&queue,i+1);
		display(&queue);
	}
	
	for(i=0; i<7; i++ )
	{
		printf("%d\n", get(&queue));
		display(&queue);
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int queue[MAX];
int front;
int rear;

int is_empty()
{
	return rear == front ;
}

int is_full()
{
	return (rear+1)%MAX == front ;
}

void put(int data)
{
	queue[rear] = data;
	rear = (rear+1)%MAX ;
}

int get(void)
{
	int temp = queue[front];
	front = (front+1)%MAX ;
	return temp;
}

void display()
{
	int i;
	system("clear");
	for(i=0; i<front; i++)
		printf("%4c", ' ');
	printf("front\n");

	for(i=0; i<front; i++)
		printf("%4c", ' ');
	printf("   |\n");

	for(i=0; i<MAX; i++)
		printf("%4d", queue[i]);
	printf("\n");

	for(i=0; i<rear; i++)
		printf("%4c", ' ');
	printf("   |\n");
	for(i=0; i<rear; i++)
		printf("%4c", ' ');
	printf("rear\n");
	getchar();
}

int main()
{
	int i;
	display();
	for(i=0; i<7; i++ )
	{
		put(i+1);
		display();
	}
	
	for(i=0; i<7; i++ )
	{
		printf("%d\n", get());
		display();
	}
		
	for(i=0; i<7; i++ )
	{
		put(i+1);
		display();
	}
	
	for(i=0; i<7; i++ )
	{
		printf("%d\n", get());
		display();
	}

	return 0;
}
#endif
#if 0
#include <stdio.h>

#define MAX 10
int queue[MAX];
int front;
int rear;

void put(int data)
{
	queue[rear] = data;
	rear = rear+1 ;
}

int get(void)
{
	int temp = queue[front];
	front = front+1;
	return temp;
}

int main()
{
	int i;
	for(i=0; i<7; i++ )
		put(i+1);
	
	for(i=0; i<7; i++ )
		printf("%d\n", get());

	for(i=0; i<7; i++ )
		put(i+1);
	
	for(i=0; i<7; i++ )
		printf("%d\n", get());
	return 0;
}
#endif
