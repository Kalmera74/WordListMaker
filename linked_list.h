#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef char LIST_TYPE;

typedef struct node_s
{	LIST_TYPE data[30];
	struct node_s *next; 
} node_t;

node_t *getnode (void)
{
	node_t *node;
	node = (node_t *) malloc (sizeof(node_t));
	node->next = NULL;
	return (node);
}
void add_after (node_t *p, LIST_TYPE* item)
{
	node_t *newp;
	newp = getnode();	
	strcpy(newp->data, item);
	newp->next = p->next;
	p->next = newp;
}
node_t *add_beginning (node_t *headp, LIST_TYPE* item)
{	
	node_t *newp;
	newp = getnode();	
	strcpy(newp->data, item);
	newp->next = headp;
	return (newp);
}

//function that displays the list
void display_list (node_t *headp)
{	
	node_t *p;
	
	if (headp == NULL)
		printf("\nThe List is EMPTY !!!\n\n");
	else 
	{	
		p = headp;
		
		while (p != NULL)
		{	
			printf ("%s\n",p->data);
			p = p->next;
		}
	//	printf("NULL\n\n");
	}
}
