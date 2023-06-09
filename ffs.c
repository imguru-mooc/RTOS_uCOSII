#if 0
#include <stdio.h>

int my_ffs(int word){
    int num = 0;
    if ((word & 0xffff) == 0) {
        num += 16;
        word >>= 16;
    }
    if ((word & 0xff) == 0) {
        num += 8;
        word >>= 8;
    }
    if ((word & 0xf) == 0) {
        num += 4;
        word >>= 4;
    }
    if ((word & 0x3) == 0) {
        num += 2;
        word >>= 2;
    }
    if ((word & 0x1) == 0)
        num += 1;
    return num;
}

int main()
{
	int bitmap = 0x1000;  // 1000000000000

	int idx = my_ffs(bitmap);
	printf("idx=%d\n", idx);
	return 0;
}
#endif
#if 0
#include <stdio.h>

int ffs( int bitmap )
{
	int idx;

	for(idx=0; idx<32; idx++)
		if( bitmap & (1<<idx) )
			break;
	return idx;
}
int main()
{
	int bitmap = 0x1000;  // 1000000000000

	int idx = ffs(bitmap);
	printf("idx=%d\n", idx);
	return 0;
}
#endif
