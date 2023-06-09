#include <stdio.h>
typedef struct
{
    short    key;
    short    key1;
	char     ch;
    int      cur;
} KEY_EVENT;


int main()
{
	printf("%d\n", sizeof(KEY_EVENT));
	return 0;
}
