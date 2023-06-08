#if 1
#include <stdio.h>

void swap( void *a, void *b, int size )
{
	char t;
	int i;

	for(i=0; i<size; i++ )
	{
		t = ((char*)a)[i];
		((char*)a)[i] = ((char*)b)[i];
		((char*)b)[i] = t;
	}
}

void bubble(void *a, int n, int size, int (*cmp)(void*,void*) )
{
	int i,j;
	
	for( i=0; i<n-1; i++ )
		for( j=0; j<n-1-i; j++ )
			if( cmp( (char*)a+j*size, (char*)a+(j+1)*size ) > 0 )
				swap((char*)a+j*size, (char*)a+(j+1)*size, size);
}

//--------------------------------------------------------------------------

// qsort
int int_cmp( void *a, void *b)
{
	return *(int*)b - *(int*)a;
}

int main()
{
	int i;
	int a[] = { 500,400,600,200,700,100,300 };

	bubble(a, 7, sizeof(a[0]), int_cmp);

	for( i=0; i<7; i++ )
		printf("%4d", a[i]);
	printf("\n");
	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( void *a, void *b, int size )
{
	char t;
	int i;

	for(i=0; i<size; i++ )
	{
		t = ((char*)a)[i];
		((char*)a)[i] = ((char*)b)[i];
		((char*)b)[i] = t;
	}
}

void bubble(void *a, int n, int size)
{
	int i,j;
	
	for( i=0; i<n-1; i++ )
		for( j=0; j<n-1-i; j++ )
			if( *((char*)a+j*size) >  *((char*)a+(j+1)*size) )
				swap((char*)a+j*size, (char*)a+(j+1)*size, size);
}

int main()
{
	int i;
	int a[] = { 500,400,600,200,700,100,300 };

	bubble(a, 7, sizeof(a[0]));

	for( i=0; i<7; i++ )
		printf("%4d", a[i]);
	printf("\n");
	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( void *a, void *b, int size )
{
	char t;
	int i;

	for(i=0; i<size; i++ )
	{
		t = ((char*)a)[i];
		((char*)a)[i] = ((char*)b)[i];
		((char*)b)[i] = t;
	}
}

void bubble(int *a, int n)
{
	int i,j;
	
	for( i=0; i<n-1; i++ )
		for( j=0; j<n-1-i; j++ )
			if( a[j] > a[j+1] )
				swap(a+j, a+j+1, sizeof(a[j]));
}

int main()
{
	int i;
	int a[] = { 5,4,6,2,7,1,3 };

	bubble(a, 7);

	for( i=0; i<7; i++ )
		printf("%4d", a[i]);
	printf("\n");
	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( void *a, void *b, int size )
{
	char t;
	int i;

	for(i=0; i<size; i++ )
	{
		t = ((char*)a)[i];
		((char*)a)[i] = ((char*)b)[i];
		((char*)b)[i] = t;
	}
}

int main()
{
	int a=3;
	int b=4; 

	double ad=3.;
	double bd=4.; 

	printf("a=%d, b=%d\n", a, b );
	swap( &a, &b, sizeof(a) );
	printf("a=%d, b=%d\n", a, b );

	printf("ad=%lf, bd=%lf\n", ad, bd );
	swap( &ad, &bd, sizeof(ad) );
	printf("ad=%lf, bd=%lf\n", ad, bd );
	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( char *a, char *b, int size )
{
	char t;

	int i;

	for(i=0; i<size; i++ )
	{
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}

int main()
{
	int a=3;
	int b=4; 

	double ad=3.;
	double bd=4.; 

	printf("a=%d, b=%d\n", a, b );
	swap( (char*)&a, (char*)&b, sizeof(a) );
	printf("a=%d, b=%d\n", a, b );

	printf("ad=%lf, bd=%lf\n", ad, bd );
	swap( (char*)&ad, (char*)&bd, sizeof(ad) );
	printf("ad=%lf, bd=%lf\n", ad, bd );
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a=3;
	int b=3; 

	printf("a=%d, b=%d\n", a, b );

	/*
	a = a+b;
	b = a-b;
	a = a-b;
	*/

	/*
	a = a*b;
	b = a/b;
	a = a/b;
	*/

	/*
	a = a^b;  // 0011
	          // 0100 ^
	          // 0111
	b = a^b;  // 0111
	          // 0100 ^
	          // 0011
	a = a^b;  // 0111
	          // 0011 ^
	          // 0100
  */

	/*
	a ^= b;
	b ^= a;
	a ^= b;
	*/

	// a ^= b ^= a ^= b;

#define SWAP(a,b )  ((a!=b)?(a ^= b ^= a ^= b):1)
	SWAP( a,b );
	printf("a=%d, b=%d\n", a, b );

	return 0;
}
#endif

#if 0
#include <stdio.h>

int main()
{
	int a=3;
	int b=4; 
	int c;

	printf("a=%d, b=%d\n", a, b );

	c = a;
	a = b;
	b = c;

	printf("a=%d, b=%d\n", a, b );

	return 0;
}
#endif
