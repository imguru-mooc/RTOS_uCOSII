#if 0
#include <stdio.h>

void aaa(void)   
{
	printf("aaa()\n");
}

void (*foo(void))(void) 
{
	printf("foo()\n");
	return aaa;
}

int main()
{
	foo()();
	return 0;
}
#endif
#if 0
#include <stdio.h>

void foo( void (*fp)(void) )   
{
	fp();
	printf("foo()\n");
}
// ---------------------------------
void aaa()   
{
	printf("aaa()\n");
}
void bbb()   
{
	printf("bbb()\n");
}

int main()
{
	foo(bbb);
	return 0;
}
#endif
#if 0
#include <stdio.h>

void foo(void)   
{
	printf("foo()\n");
}

int main()
{
	// void (*p)(void)  = foo;
	// ...
	// p();

	void (*p)(void)  = &foo;
	// ...
	(*p)();
	return 0;
}
#endif

#if 0
#include <stdio.h>

void foo(void)    
{
	printf("foo()\n");
}

int main()
{
	foo();    // call foo;
	foo;    // foo;
	printf("%p\n", foo);
	return 0;
}
#endif

#if 0
#include <stdio.h>

int (* foo(void) )[2]   
{
	static int a[2][2] = {1,2,3,4};
	return a;
}

int main()
{
	int i,j;
	int (*p)[2] = foo();

	for(i=0 ; i<2; i++ )
		for(j=0 ; j<2; j++ )
			printf("%d\n",p[i][j]);

	return 0;
}
#endif
#if 0
#include <stdio.h>

/*
void foo( int (*p)[2]  )
{
	int i,j;
	for(i=0 ; i<2; i++ )
		for(j=0 ; j<2; j++ )
			p[i][j] = 0;
}
*/

// int a[2][2];
// int p[][2] = a;

void foo( int p[][2] )  // int p[][2] => int (*p)[2] 
{
	int i,j;
	for(i=0 ; i<2; i++ )
		for(j=0 ; j<2; j++ )
			p[i][j] = 0;
}
int main()
{
	int i,j;
	int a[2][2];

	foo(a);
	for(i=0 ; i<2; i++ )
		for(j=0 ; j<2; j++ )
			printf("%d\n",a[i][j]);

	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[2][2] = {1,2,3,4};
	int **p = a;
	//printf("%lu\n",(sizeof(a)/sizeof(a[0])));

	p[1][1] = 10;
	//printf("%d\n",a[1][1]);

	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[2][2] = {1,2,3,4};
	int *p = a;
	//printf("%lu\n",(sizeof(a)/sizeof(a[0])));

	p[1][1] = 10;
	//printf("%d\n",a[1][1]);

	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	//int *p = &a;
	//int [5] *p = &a;
	//int  *p[5] = &a;
	int (*p)[5] = &a;

	(*p)[1] = 10;

	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[5] = {1,2,3,4,5};
	//int *p = a;
	int *p = &a[0];

	printf("sizeof(a)=%lu\n", sizeof(a));
	printf("sizeof(int[5])=%lu\n", sizeof(int[5]));
	printf("sizeof(p)=%lu\n", sizeof(p));
	printf("sizeof(int*)=%lu\n", sizeof(int*));
	return 0;
}
#endif

