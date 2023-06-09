#if 1
#include <stdio.h>

void swap( void *a, void *b, int n )
{
	char t;
	int i;
	char *x = (char*)a;
	char *y = (char*)b;
	for(i=0; i<n; i++)
	{
		t = x[i];
		x[i] = y[i];
		y[i] = t;
	}
}

int main()
{
	double a=3.0;
	double b=4.0;
	swap(&a, &b, sizeof a);

	printf("a=%lf, b=%lf\n", a, b);
	return 0;
}
#endif
#if 0
#include <stdio.h>

void swap( char *a, char *b, int n )
{
	char t;

	int i;
	for(i=0; i<n; i++)
	{
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}

int main()
{
	double a=3.0;
	double b=4.0;
	swap((char*)&a, (char*)&b, sizeof a);

	printf("a=%lf, b=%lf\n", a, b);
	return 0;
}
#endif

#if 0
#include <stdio.h>

void swap( int *a, int *b )
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int a=3;
	int b=4;
	swap(&a, &b);

	printf("a=%d, b=%d\n", a, b);
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a=3;
	int b=4;

	int t;
	t = a;
	a = b;
	b = t;

	printf("a=%d, b=%d\n", a, b);
	return 0;
}
#endif
