/* Filename: linkTest.c */
/* Author: d3r1ck */
/* Description: The program takes input from a user(integers) and stores in a list(self-referencial structures) */
		/* And this list can later be printed to see the items in the list. */

//header files included
#include<stdio.h>
#include<stdlib.h>

//user defined pointer to structure
typedef struct node *LINK;

//structure declaration
struct node {
	int item;
	LINK next;
};


//function prototypes
void add_item_to_list(LINK *, int);
void print_items_in_the_list(LINK);
void UserMenu(void);
//void delete_item_from_the_list(LINK, int);
//int isEmpty(LINK head);


//main function definition
int
main(void){
	LINK HeadNode = malloc(sizeof(LINK));
	LINK trackPtr = HeadNode;
	HeadNode->item = 0;
	HeadNode->next = NULL;
	
	int num, choice, value;
	char ans = 'y', response;
	
	printf("Will you like to use this list?: ");
	scanf("%c", &ans);
	
	while(ans == 'y'){
		UserMenu();
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enter an integer: ");
				scanf("%d", &num);
				add_item_to_list(&HeadNode, num);
				break;
			case 2: 
				print_items_in_the_list(trackPtr->next);
				break;
			case 3:
				printf("Quiting the program...\nPlease wait for some seconds....\n");
				sleep(5);
				goto l1;
			/*case 4:
				printf("Enter the value you want to delete: ");
				scanf("%d", &value);
				if(!isEmpty(trackPtr->next)){
					delete_item_from_the_list(trackPtr->next, value);
					printf("%d has been deleted from the list.\n", value);
				}
				else {
					printf("The item you want to delete is not found in the list.\n");
				}
				break;*/
			default:
				printf("Invalid input!!! Try again!!!.\n");
		}
	}
	
	printf("End of run.\n\t You don't want to use the list.\n");
l1: return 0;
}

//these are the function definitions

//function definition for instructions
void UserMenu(void){
	printf(" Make a choice from the Menu below\n\n"
		"\t1 to add item to the list.\n"
		"\t2 to print the items in the list.\n"
		"\t3 to quit the program.\n"
		"\tEnter a number?: ");
}


//function definition for add items to list
void add_item_to_list(LINK *head, int item){
	//LINK track = *head;
	//trackPtr = *head;
	if((*head)->next == NULL){
		(*head)->next = malloc(sizeof(LINK));
		(*head)->next->item = item;
		*head = (*head)->next;
		(*head)->next = NULL;
		printf("%d has been inserted into the list.\n", item);
	}
}


//function to print items in the list
void print_items_in_the_list(LINK curPtr){
	if(curPtr != NULL){
		printf("\n\nThe list now contains items: ");
	
		while(curPtr != NULL){
			printf("%d --> ", curPtr->item);
			curPtr = curPtr->next;
		}
		printf("NULL\n\n");
	}
	else {
		printf("The list is empty.\n");
	}
}

//subroutine to delete items in the list
/*void delete_item_from_the_list(LINK head, int value){
	LINK prevPtr;
	while(head->next != NULL){	
		if(head->item == value){
			prevPtr->next = NULL;
			free(head);	
		}
		else {
			head = head->next;
			prevPtr = head;
		}
	}
}

//this routine is to test and see if the nodes are more than one
//that is not only the dummy node.
int isEmpty(LINK head){
	return head == NULL;
}*/
