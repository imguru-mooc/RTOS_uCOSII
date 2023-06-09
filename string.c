#include <stdio.h>

//const char a[6] = "hello";
//const char b[6] = "world";
int main()
{
	char *p = "hello";
	printf("[%s]\n", p );
	printf("%d\n", sizeof("hello") );

	p = "world";
	printf("[%s]\n", p );

	*p = 'a';
	printf("[%s]\n", p );
	return 0;
}
