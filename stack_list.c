/* Stack implementation using linkex list */
/* Author: Alangi Derick */

#include<stdio.h>
#include<stdlib.h>

#define max 100 /* maximum size of stack */

void stackInit(int m);
int stackEmpty();
void stackPush(int item);
int stackPop(void);
void stackDisplay(void);

typedef struct stackNode *LINK;
struct stackNode {
	int item;
	LINK next;
};

LINK head;
LINK newNode(int item, LINK h) {
	LINK nnode = malloc(sizeof(*nnode));
	nnode -> item = item;
	nnode -> next = h;
	return nnode;
}

void stackInit(int m)
{
	head = NULL;
}

int stackEmpty() {
	return head == NULL;
}

void stackPush(int item) {
	head = newNode(item, head);
	printf("%d added to stack ", item);
}

int stackPop(void) {
	int item = head -> item;	
	LINK t = head -> next;
	free(head);
	head = t;
	return item;
}

void stackDisplay(void) {
	LINK t = head;
	while(t!=NULL) {
		printf("%d ", t->item);
		t = t -> next;
	}
	printf("\n");
}


int main(void) {
	int i, item;
	stackInit(max);
	/*add 10 random numbers to stack*/

	for(i=0; i<10; i++){
	stackPush(rand() % 100);
	printf("\n");
	}
	printf("\n");
	
	printf("Initial Contents: ");
	stackDisplay();
	/*pop 5 items off the stack*/
	for(i=0; i<5; i++)
	{
		if(!stackEmpty()) {
		item = stackPop();
		printf("%d popped from stack. ", item);
		printf("\n");
		
	}
}

	printf("\n");
	printf("Contents after popping off 5 items: ");
	stackDisplay();
}
