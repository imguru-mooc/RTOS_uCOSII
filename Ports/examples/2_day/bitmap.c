#if 1
#include <stdio.h>

int main()
{
	int info;
	info = 87;
	info |= 4<<7;  // 100 10010111

	printf("score=%d\n", info & 0x7f );
	printf("year=%d\n",  (info>>7) & 0x7 );

	return 0;
}
#endif

#if 0
#include <stdio.h>

typedef struct
{
	int score;
	int year;
} ST;

int main()
{
	ST s = {87, 4};

	printf("score=%d\n", s.score );
	printf("year=%d\n", s.year );
	

	return 0;
}
#endif
