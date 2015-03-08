/* Author: Alangi Derick
   Program: Linked list implementation of student info
*/


#include<stdio.h>
#include<stdlib.h>

struct st_info {
	int id;
	float score1;
	float score2;
};

typedef struct st_info ST_INFO;
typedef struct node *LINK;

struct node {
	ST_INFO stud;
	LINK next;
};

void list_add(LINK *head, ST_INFO st_info);
ST_INFO get_info(ST_INFO stud);
void list_prn(LINK head);

int main(void) {
	printf("Program Takes information about students and prints them from below.\n");
	int i;
	LINK h;
	ST_INFO st;
	h = NULL;	/* empty list */

	for(i=0; i<5; i++) {
		st = get_info(st);
		list_add(&h, st);
	}

	list_prn(h);
}

ST_INFO get_info(ST_INFO stud) {
	printf("\nStudent ID: ");
	scanf("%d", &stud.id);
	printf("Score I: ");
	scanf("%f", &stud.score1);
	printf("Score II: ");
	scanf("%f", &stud.score2);
	
	return stud;
}

void list_add(LINK *head, ST_INFO st_info) {
	LINK tmp;
	/* allocate space for new node */

	if((tmp = malloc(sizeof(*tmp))) == NULL) { /* out of memory - exit */

	printf("\nNot enough memory");
	exit(1);
	}
	tmp -> stud = st_info;
	tmp -> next = *head;
	*head = tmp;
}


void list_prn(LINK head) {
	LINK tmp = head;
	printf("\n%12s%9s%10s", "Student ID", "Score I", "Score II");

	while(tmp!=NULL) {
		printf("\n%12d%9.2f%10.2f", tmp->stud.id, tmp->stud.score1, tmp->stud.score2);
	tmp = tmp -> next;
}

printf("\n");
}

