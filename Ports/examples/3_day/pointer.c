#if 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input( char **name, int n )
{
	int i;
	char buffer[4096];

	for(i=0; i<n; i++ )
	{
		fgets( buffer, sizeof buffer, stdin );  // "홍 길동\n\0"
		buffer[strlen(buffer)-1] = 0;
		name[i] = malloc( strlen(buffer)+1 ); 
		strcpy( name[i], buffer );
	}
}
void output( char **name, int n )
{
	int i;
	for(i=0; i<n; i++ )
		printf("%s\n", name[i] );
}

void cleanup( char **name, int n )
{
	int i;
	for(i=0; i<n; i++ )
		free(name[i]);

	free(name);
}

void init( char ***name, int *n)
{
	printf("몇명?");
	scanf("%d", n );
	getchar();
	*name = malloc(sizeof(char*)*(*n)); 
}

int main()
{
	int i;
	char **name;
	int n;

	init( &name, &n );
	input( name, n );
	output( name, n );
	cleanup( name, n );

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3
int main()
{
	int i;
	char buffer[4096];
	char *name[MAX];

	for(i=0; i<MAX; i++ )
	{
		fgets( buffer, sizeof buffer, stdin );  // "홍 길동\n\0"
		buffer[strlen(buffer)-1] = 0;
		name[i] = malloc( strlen(buffer)+1 ); 
		strcpy( name[i], buffer );
	}
	for(i=0; i<MAX; i++ )
		printf("%s\n", name[i] );

	for(i=0; i<MAX; i++ )
		free(name[i]);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i;
	char name[3][4096];

	for(i=0; i<3; i++ )
	{
		fgets( name[i], sizeof name[i], stdin );  // "홍 길동\n\0"
		name[i][strlen(name[i])-1] = 0;
	}
	for(i=0; i<3; i++ )
		printf("%s\n", name[i] );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char name[4096];
	fgets( name, sizeof name, stdin );  // "홍 길동\n\0"
	name[strlen(name)-1] = 0;
	printf("%s\n", name );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char name[20];
	fgets( name, sizeof name, stdin );  // "홍 길동\n\0"
	name[strlen(name)-1] = 0;
	printf("%s\n", name );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char name[20];
	gets( name );
	printf("%s\n", name );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char name;
	scanf("%c", &name );
	printf("%c\n", name );
	return 0;
}
#endif



#if 0
#include <stdio.h>
#include <stdlib.h>

void init( int **score, int *n)
{
	printf("몇명?");
	scanf("%d", n );
	*score = malloc( sizeof(int)*(*n) );
}

void input( int *score, int n)
{
	int i;
	for(i=0; i<n; i++ )
	{
		scanf("%d", &score[i] );
	}
}

void output( int *score, int n)
{
	int i;
	for(i=0; i<n; i++ )
	{
		printf("%d\n", score[i] );
	}
}
int main()
{
	int *score;
	int n;

	init( &score, &n );
	input( score, n );
	output( score, n );

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
	int n;
	int i;

	printf("몇명?");
	scanf("%d", &n );
	score = malloc( sizeof(int)*n );
	for(i=0; i<n; i++ )
	{
		scanf("%d", &score[i] );
	}

	for(i=0; i<n; i++ )
	{
		printf("%d\n", score[i] );
	}
	free(score);
	return 0;
}
#endif

#if 0
#include <stdio.h>

#define MAX 3

int main()
{
	int score[MAX];
	int i;

	for(i=0; i<MAX; i++ )
	{
		scanf("%d", &score[i] );
	}

	for(i=0; i<MAX; i++ )
	{
		printf("%d\n", score[i] );
	}
	return 0;
}
#endif


#if 0
#include <stdio.h>
int main()
{
	int score;

	scanf("%d", &score );
	printf("%d\n", score );
	return 0;
}
#endif
