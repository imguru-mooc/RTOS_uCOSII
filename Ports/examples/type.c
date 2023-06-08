#if 1
#include <stdio.h>

typedef struct 
{
	int b1:4,b2:4,b3:4,b4:4,b5:4,b6:4,b7:4,b8:4;
} BIT;

typedef union {
	float f;	
	BIT   b;
} U;

int main()
{
	U u;
	u.f = 10.25f;

	printf("%x %x %x %x %x %x %x %x \n", 
	  u.b.b1,u.b.b2,u.b.b3,u.b.b4,u.b.b5,u.b.b6,u.b.b7,u.b.b8 );
	return 0;
}
#endif

#if 0
#include <stdio.h>

int main()
{
	float f = 10.25f;

	printf("%5.2f\n", f );
	return 0;
}
#endif
#if 0
#include <stdio.h>

typedef struct 
{
	//char b : 2;
	char b : 1;
} BIT;


int main()
{
	BIT a;
	//a.b = 3;
	a.b = 1;

	if( a.b == 1 )
		printf("%d\n", a.b );
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	char ch=255;
	short s = 0xfffe;
	int i = 0xfffffffc;
	printf("%d\n", ch );
	printf("%d\n", s );
	printf("%d\n", i );
	return 0;
}
#endif

#if 0
#include <stdio.h>

int main()
{
	char ch=200;
	printf("%d\n", ch );
	return 0;
}
#endif
