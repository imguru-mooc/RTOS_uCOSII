#if 1
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	struct _node *next;
	struct _node *prev;
} NODE;

void __list_add( NODE *prev, NODE *next,  NODE *temp )
{
    temp->prev = prev;
    prev->next = temp;
    temp->next = next;
    next->prev = temp;
}

void list_add( NODE *head, NODE *temp )
{
	__list_add( head, head->next,  temp );
}

void list_add_tail( NODE *head, NODE *temp )
{
	__list_add( head->prev, head,  temp );
}


#define   list_entry( ptr, member, type ) ((type*)((char*)ptr - (long)&((type*)0)->member ))

//------------------------------------------------------------------
typedef struct
{
	char name[32];
	NODE list;
	int  id;
} SAWON;

void display( NODE *head )
{
	NODE *temp;
	SAWON *s;
	system("clear");
	printf("[head]");
	for(temp = head->next; temp!=head ; temp = temp->next )
	{
//		s = (SAWON*)((char*)temp - (sizeof(SAWON)-sizeof(NODE)));
//		s = (SAWON*)((char*)temp - (long)&((SAWON*)0)->list );
		s = list_entry(temp, list, SAWON);
		printf("->[%s]", s->name);
	}
	printf("\n");
	getchar();
}

int main()
{
	int i;

	SAWON  sawon[5] = {{"홍길동",},{"이순신",},{"임꺽정",},{"일지매",},{"유관순",}} ;
	NODE head={&head, &head};
	display(&head);
	for(i=0 ; i<5; i++ )
	{
		list_add_tail(&head, &sawon[i].list);
		display(&head);
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	void* data;
	struct _node *next;
	struct _node *prev;
} NODE;

void __list_add( NODE *prev, NODE *next,  NODE *temp )
{
    temp->prev = prev;
    prev->next = temp;
    temp->next = next;
    next->prev = temp;
}

void list_add( NODE *head, NODE *temp )
{
	__list_add( head, head->next,  temp );
}

void list_add_tail( NODE *head, NODE *temp )
{
	__list_add( head->prev, head,  temp );
}


//------------------------------------------------------------------
typedef struct
{
	char name[32];
} SAWON;

void display( NODE *head )
{
	NODE *temp;
	SAWON *s;
	system("clear");
	printf("[head]");
	for(temp = head->next; temp!=head ; temp = temp->next )
	{
		s = (SAWON*)temp->data;
		printf("->[%s]", s->name);
	}
	printf("\n");
	getchar();
}

int main()
{
	int i;

	SAWON  sawon[5] = {{"홍길동"},{"이순신"},{"임꺽정"},{"일지매"},{"유관순"}} ;
	NODE nodes[5]={0,};
	NODE head={0,&head, &head};
	display(&head);
	for(i=0 ; i<5; i++ )
	{
		nodes[i].data = &sawon[i];
		list_add_tail(&head, nodes+i);
		display(&head);
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *next;
	struct _node *prev;
} NODE;

void __list_add( NODE *prev, NODE *next,  NODE *temp )
{
    temp->prev = prev;
    prev->next = temp;
    temp->next = next;
    next->prev = temp;
}

void list_add( NODE *head, NODE *temp )
{
	__list_add( head, head->next,  temp );
}

void list_add_tail( NODE *head, NODE *temp )
{
	__list_add( head->prev, head,  temp );
}

void display( NODE *head )
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for(temp = head->next; temp!=head ; temp = temp->next )
		printf("->[%d]", temp->data);
	printf("\n");
	getchar();
}

int main()
{
	int i;

	NODE nodes[10]={0,};
	NODE head={0,&head, &head};
	display(&head);
	for(i=0 ; i<7; i++ )
	{
		nodes[i].data = i+1;
		list_add_tail(&head, nodes+i);
		display(&head);
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *next;
} NODE;


void list_add( NODE *head, NODE *temp )
{
	temp->next = head->next;
	head->next = temp;
}

void display( NODE *head )
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for(temp = head->next; temp!=head ; temp = temp->next )
		printf("->[%d]", temp->data);
	printf("\n");
	getchar();
}

int main()
{
	int i;

	NODE nodes[10]={0,};
	NODE head={0,&head};
	display(&head);
	for(i=0 ; i<5; i++ )
	{
		nodes[i].data = i+1;
		list_add(&head, nodes+i);
		display(&head);
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *next;
} NODE;


void list_add( NODE *head, int data )
{
	NODE *temp;
	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
}

void display( NODE *head )
{
	NODE *temp;
	system("clear");
	printf("[head]");
	for(temp = head->next; temp!=head ; temp = temp->next )
		printf("->[%d]", temp->data);
	printf("\n");
	getchar();
}

int main()
{
	int i;

	NODE head={0,&head};
	display(&head);
	for(i=0 ; i<5; i++ )
	{
		list_add(&head, i+1);
		display(&head);
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

NODE *head = 0;

void list_add( int data )
{
	NODE *temp;
	temp = malloc(sizeof(NODE));
	temp->data = data;
	temp->next = head;
	head = temp;
}

void display()
{
	NODE *temp;
	system("clear");
	printf("head");
	for(temp = head; temp ; temp = temp->next )
		printf("->[%d]", temp->data);
	printf("\n");
	getchar();
}

int main()
{
	int i;

	display();
	for(i=0 ; i<5; i++ )
	{
		list_add(i+1);
		display();
	}
	return 0;
}
#endif
