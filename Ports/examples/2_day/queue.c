#include <stdio.h>

#define MAX 10
int queue[MAX];
int front;
int rear;

int is_empty()
{
	return rear == front;
}
int is_full()
{
	return (rear+1)%MAX == front;
}

void put(int data)
{
	if( is_full() )
		return ;
	queue[rear] = data;
	rear = (rear+1) % 10;
}

int get(void)
{
	int temp;
	
	if( is_empty() )
		return -1;

	temp = queue[front];
	front = (front+1) % 10;
	return temp;
}

int main()
{
	int i;
	int ret;
	ret = is_empty();
	printf("ret=%d\n", ret);

	for(i=0; i<5; i++ )
		put(i+1);
	
	for(i=0; i<5; i++ )
		put(i+1);

	ret = is_empty();
	printf("ret=%d\n", ret);

	return 0;
}
