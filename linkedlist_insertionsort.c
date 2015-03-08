/* Author: Alangi Derick
   Program: Linked list to implement Insertion sort
*/

#include<stdio.h>
#include<stdlib.h>

#define N 20

typedef struct node *LINK;
struct node {
	int item;
	LINK next;
};

void list_prn(LINK head);

int main(void) {

	printf("Linked List implementation of Insertion Sort.\n\n\n");
	
	struct node heada, headb;
	int i;
	LINK t, u, x, a= &heada, b;

	/*store N random numbers in the first array list*/

	for(i=0, t = a; i<N; i++) {
	t->next = malloc(sizeof *t);
	t = t-> next;
	t -> next = NULL;
	t -> item = rand() % 1000;
	}

	printf("Unsorted List\n");
	list_prn(&heada);

	/*starting with the second list empty, transfering, storing and sorting them at once*/

	b = &headb;
	b->next = NULL;
	for(t = a-> next; t!=NULL; t = u) {
		u = t->next;
	for(x = b; x->next !=NULL; x = x->next)
	if(x->next->item > t -> item)
	break;
	
	t-> next = x -> next;
	x -> next = t;
	}
	
	printf("\nSorted List\n");
	list_prn(&headb);
	}

void list_prn(LINK head)
{
	LINK tmp = head -> next;
	while(tmp!=NULL) {
		printf("%d ", tmp->item);
		tmp = tmp -> next;
	}
	printf("\n");
}
