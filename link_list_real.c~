#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef struct node *LINK;
struct node
{
	int item;
	LINK next;
};

void list_prn(LINK head);
void list_add(LINK head, int);
LINK list_reverse(LINK head);
struct node heada;
LINK t, a = &heada;

int main()
{
	int i, num;
	list_add(&heada, N);
	printf("This is a linked list with %d integers.\n", N);
	list_prn(&heada);

	printf("This is the list in reverse order.\n");	
	list_prn(list_reverse(&heada));
return 0;
}

void list_add(LINK t, int n)
{
	int i;
	for(i = 0, t = a; i<n; i++){
	t -> next = malloc(sizeof *t);
	t = t -> next;
	t -> next = NULL;
	t -> item = rand() % 100;
	}
}

void list_prn(LINK head)
{
	LINK tmp = head -> next;
	while(tmp != NULL)
	{	
		printf("%d ", tmp -> item);
		tmp = tmp -> next;
	}
	printf("\n");
}

LINK list_reverse(LINK head)
{
	LINK t, y = head -> next, r = NULL;
	while(y!= NULL)	
	{
		t = y -> next;
		y -> next = r;
		r = y;
		y = t;
	}
	return r;
}
