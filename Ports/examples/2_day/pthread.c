#if 1
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *foo(void *data)
{
	char ip[] = "192.168.56.100";
	char *p;
	char *saveptr;
	p = strtok_r(ip, "." , &saveptr);
	while(p)
	{
		printf("[%s]\n", p );
		sleep(1);
		p = strtok_r(saveptr, ".", &saveptr );
	}
	return 0;
}

void *bar(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;
	char *saveptr;
	p = strtok_r(hp, "-" , &saveptr);
	while(p)
	{
		printf("[%s]\n", p );
		sleep(1);
		p = strtok_r(saveptr, "-", &saveptr );
	}
	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, foo, 0);
	pthread_create(&thread[1], 0, bar, 0);
	pthread_join(thread[0], 0);
	pthread_join(thread[1], 0);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *foo(void *data)
{
	char ip[] = "192.168.56.100";
	char *p;
	pthread_mutex_lock(&mutex);
	p = strtok(ip, "." );
	while(p)
	{
		printf("[%s]\n", p );
		sleep(1);
		p = strtok(0, "." );
	}
	pthread_mutex_unlock(&mutex);
	return 0;
}

void *bar(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;
	pthread_mutex_lock(&mutex);
	p = strtok(hp, "-" );
	while(p)
	{
		printf("[%s]\n", p );
		sleep(1);
		p = strtok(0, "-" );
	}
	pthread_mutex_unlock(&mutex);
	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, foo, 0);
	pthread_create(&thread[1], 0, bar, 0);
	pthread_join(thread[0], 0);
	pthread_join(thread[1], 0);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *foo(void *data)
{
	char ip[] = "192.168.56.100";
	char *p;
	p = strtok(ip, "." );
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok(0, "." );
	}
	return 0;
}

int main()
{
	pthread_t thread;
	pthread_create(&thread, 0, foo, 0);
	pthread_join(thread, 0);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_mutexattr_t ma;

int count=0;

int sum(int n)
{
	if(n==1)
		return 1;

	pthread_mutex_lock(&mutex);   // lock++;
	count = sum(n-1)+n;
	pthread_mutex_unlock(&mutex); // lock--;
	return count;
}

void *foo(void *data)
{
	printf("foo()\n");

	printf("sum(5)=%d\n", sum(5));

	return 0;
}

int main()
{
	pthread_t thread;
	pthread_mutexattr_init(&ma);
    pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &ma);
	pthread_create(&thread, 0, foo, 0);
	pthread_join(thread, 0);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int count=0;

int sum(int n)
{
	if(n==1)
		return 1;

	pthread_mutex_lock(&mutex);
	count = sum(n-1)+n;
	pthread_mutex_unlock(&mutex);
	return count;
}

void *foo(void *data)
{
	printf("foo()\n");

	printf("sum(5)=%d\n", sum(5));

	return 0;
}

int main()
{
	pthread_t thread;
	pthread_create(&thread, 0, foo, 0);
	pthread_join(thread, 0);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int count=0; 
void *foo(void *data)
{
	int i;
	printf("foo()\n");

	for(i=0; i<100000000; i++ )
	{
		pthread_mutex_lock(&mutex);
		count++;
		pthread_mutex_unlock(&mutex);
	}

	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, foo, 0);
	pthread_create(&thread[1], 0, foo, 0);
	pthread_join(thread[0], 0);
	pthread_join(thread[1], 0);
	printf("count=%d\n", count );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>

int count=0; 
int lock=0; 
void *foo(void *data)
{
	int i;
	printf("foo()\n");

	for(i=0; i<100000000; i++ )
	{
		while(lock);
		lock = 1;
		count++;
		lock = 0;
	}

	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, foo, 0);
	pthread_create(&thread[1], 0, foo, 0);
	pthread_join(thread[0], 0);
	pthread_join(thread[1], 0);
	printf("count=%d\n", count );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <pthread.h>

int count=0; 
void *foo(void *data)
{
	int i;
	printf("foo()\n");

	for(i=0; i<1000000000; i++ )
		count++;

	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, foo, 0);
	pthread_create(&thread[1], 0, foo, 0);
	pthread_join(thread[0], 0);
	pthread_join(thread[1], 0);
	printf("count=%d\n", count );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <pthread.h>

void *foo(void *data)
{
	printf("foo()\n");
}

int main()
{
	pthread_t thread;
	pthread_create(&thread, 0, foo, 0);
	pthread_join(thread, 0);
	return 0;
}
#endif
