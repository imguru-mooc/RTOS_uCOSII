#if 1
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main()
{
	sigset_t set, oldset;
	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_BLOCK, &set, &oldset);


	printf("임계영역 진입\n");
	sleep(3);
	printf("임계영역 탈출\n");

	sigprocmask(SIG_SETMASK, &oldset, 0);


	while(1)
		;
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <signal.h>
int main()
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while(1)
		;
	return 0;
}
#endif
