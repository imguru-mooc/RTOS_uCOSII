#if 1
#include <stdio.h>

int foo(int a, int b)
{
    int result;
    result = a+b;
    return result;
}

int main()
{
    foo(10,20);
    return 0;
}

#endif
#if 0
#include <stdio.h>

void foo(int a, int b)
{
	printf("foo(%d, %d)\n", a, b);
}

int main()
{
	foo(10, 20);
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
	foo();
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main()
{
	int a=10;
	int b=20;
	printf("%p, %p\n", &a, &b);
	return 0;
}
#endif
