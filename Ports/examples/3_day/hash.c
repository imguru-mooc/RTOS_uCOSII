#if 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ver 1.0
typedef struct _node
{
    struct _node *next;
    struct _node *prev;
} NODE;

void __insert_data( NODE *temp , NODE *prev, NODE *next)
{
   temp->next = next;
   prev->next = temp;
   temp->prev = prev;
   next->prev = temp;
}

void insert_add( NODE *temp , NODE *head)
{
	__insert_data(temp, head, head->next );
}
void insert_add_tail( NODE *temp , NODE *head)
{
	__insert_data(temp, head->prev, head );
}

#define  list_entry(ptr, type, member) ((type*)((char*)ptr-(long)&((type*)0)->member))

//-------------------------------------------------------

#define H_MAX 8

typedef  struct 
{
	int id;
	char comm[20];
	NODE list;
} TASK;

int hash_fn( int id )
{
   return id%H_MAX;
}

void display( NODE *heads )
{
	int i;
	NODE *temp;
	TASK *p;
	system("clear");
	for( i=0; i<H_MAX; i++ )
	{
		printf("[head:%d]", i);
		for( temp = heads[i].next; temp != &heads[i]; temp=temp->next )
		{
		    p = list_entry( temp, TASK, list );
			printf("<->[%d]" , p->id);
		}
		printf("\n");
	}
	getchar();
}

TASK* find_task( int id, NODE *heads )
{
	NODE *temp;
	TASK *p;

	for( temp = heads[hash_fn(id)].next; temp != &heads[hash_fn(id)]; temp=temp->next )
	{
		p = list_entry( temp, TASK, list );
		if( id == p->id )
			return p;
	}
	return 0;
}

int main()
{
	NODE  heads[H_MAX];
	TASK  tasks[20];
	TASK  *p;
	int i;

	for(i=0; i<H_MAX; i++ )
	{
		heads[i].next = &heads[i];
		heads[i].prev = &heads[i];
	}

	display(heads);
	for(i=0; i<20; i++ )
	{
		tasks[i].id = i+1;
		sprintf(tasks[i].comm , "TASK : %d", i+1+1000 );
		insert_add_tail( &tasks[i].list,  &heads[hash_fn(i+1)] );
		display(heads);
	}
	p = find_task( 20, heads );
	if( p !=0 )
	{
		printf("%s\n", p->comm );
	}
	else
	{
		printf("해당 태스크는 찾을수 없습니다...\n" );
	}
	return 0;
}
#endif



