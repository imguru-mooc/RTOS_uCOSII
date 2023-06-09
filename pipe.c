#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd[2];
	int n, i;
	char buff[4096];
	pipe(fd);
	
	printf("%d,%d\n", fd[0], fd[1]);
	//n = read( fd[0], buff, sizeof buff);
	//buff[n-1] = 0;
	//printf("%s\n", buff );
	for( i=0; ;i++)
	{
		write(fd[1], "c", 1);
		printf("%d\n", i );
	}
			
	return 0;
}
