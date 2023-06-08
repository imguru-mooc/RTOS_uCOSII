#if 1 
#include <stdio.h>

int main()
{
	char ch = -8;   // 00001000 -> 11111000

	printf("%d\n", ch>>1 );  // 11111000 -> 11111100 
	                        //              00000100
	return 0;
}
#endif
#if 0 
#include <stdio.h>

int main()
{
	char ch = 1;

	printf("%d\n", ch<<1 );  // 1 -> 10
	printf("%d\n", ch>>1 );  // 1 -> 0.1
	return 0;
}
#endif
