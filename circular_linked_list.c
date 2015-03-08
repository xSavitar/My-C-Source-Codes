/* This is a program that implements a circular linked list */
/* Author: Alangi Derick */

#include<stdio.h>
#include<stdlib.h>

struct node {
	int key;
	struct node *next;
};

int main() 
{
	int i, N, M;
	struct node *t, *x;
	printf("Enter the values of N and M: ");
	scanf("%d %d", &N, &M);
	
	t = (struct node *)malloc(sizeof *t);
	t -> key = 1;
	x = t;
	for(i = 2; i<=N; i++)
	{
		t -> next = (struct node *)malloc(sizeof *t);
		t = t -> next;
		t -> key = i;
	}

	t -> next = x;	//forms the circle of the linked list
	
	while(t != t->next) 
	{
		for(i = 1; i<M; i++)
			t = t->next;
			printf("%d ", t->next->key);
			x = t->next;
			t->next = t->next->next;
			free(x);
	}

	printf("%d\n", t->key);
return 0;
}
