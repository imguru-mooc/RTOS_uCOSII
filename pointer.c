#if 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init(char ***name, int *n)
{
	printf("인원:");
	scanf("%d", n );
	getchar();
	*name = (char**)malloc( sizeof(char*)*(*n) );
}

int main()
{
	int i, n;
	char **name;
	char buff[4096];

	init(&name, &n);

	for(i=0; i<n; i++)
	{
		printf("이름:");
		fgets(buff, sizeof buff, stdin );
		buff[ strlen(buff)-1 ] = 0;
		name[i] = (char*)malloc( strlen(buff)+1 );
		strcpy(name[i], buff);
	}
	for(i=0; i<n; i++)
		printf("[%s]\n", name[i]);

	for(i=0; i<3; i++)
		free(name[i]);

	free(name);

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i, n;
	char **name;
	char buff[4096];

	printf("인원:");
	scanf("%d", &n );
	getchar();
	name = (char**)malloc( sizeof(char*)*n );

	for(i=0; i<n; i++)
	{
		printf("이름:");
		fgets(buff, sizeof buff, stdin );
		buff[ strlen(buff)-1 ] = 0;
		name[i] = (char*)malloc( strlen(buff)+1 );
		strcpy(name[i], buff);
	}
	for(i=0; i<n; i++)
		printf("[%s]\n", name[i]);

	for(i=0; i<3; i++)
		free(name[i]);

	free(name);

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i;
	char *name[3];
	char buff[4096];

	for(i=0; i<3; i++)
	{
		printf("이름:");
		fgets(buff, sizeof buff, stdin );
		buff[ strlen(buff)-1 ] = 0;
		name[i] = (char*)malloc( strlen(buff)+1 );
		strcpy(name[i], buff);
	}
	for(i=0; i<3; i++)
		printf("[%s]\n", name[i]);

	for(i=0; i<3; i++)
		free(name[i]);

	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *name;
	char buff[4096];

	printf("이름:");
	fgets(buff, sizeof buff, stdin );
	buff[ strlen(buff)-1 ] = 0;
	name = (char*)malloc( strlen(buff)+1 );
	strcpy(name, buff);
	printf("[%s]\n", name);

	free(name);

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

void init(int **score, int *n)
{
	int i;
	printf("인원수:");
	scanf("%d", n);
	*score = (int*)malloc(sizeof(int)*(*n));
}

void input(int *score, int n)
{
	int i;
	for(i=0; i<n; i++ )
	{
		printf("점수:");
		scanf("%d", &score[i]);
	}
}

void output(int *score, int n)
{
	int i;
	for(i=0; i<n; i++ )
		printf("%d\n", score[i]);
}

int main()
{
	int *score;
	int n;

	init(&score, &n); 
	input(score, n);
	output(score, n);

	free(score);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *score;

	int i, n;
	printf("인원수:");
	scanf("%d", &n);

	score = (int*)malloc(sizeof(int)*n);

	for(i=0; i<n; i++ )
	{
		printf("점수:");
		scanf("%d", &score[i]);
	}

	for(i=0; i<n; i++ )
		printf("%d\n", score[i]);

	free(score);
	return 0;
}
#endif

#if 0
#include <stdio.h>

int main()
{
	int i=10;
	int *p1 = &i;
	int **p2 = &p1;
	int** *p3 = &p2;
	***p3 = 20;
	printf("%d\n", i );
    printf("%p,%p,%p,%p\n", &i,&p1,&p2,&p3);

	return 0;
}
#endif
