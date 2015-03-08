/* Filename: LinkedListSort.c */
/* Description: Operating and maintaining a list */

#include<stdio.h>
#include<stdlib.h>

/* self-referential structure */
struct listNode {
	char data; //nodes contains characters
	struct listNode *nextPtr; //pointer to the next node.
};

typedef struct listNode ListNode; //listNode is called ListNode
typedef ListNode *ListNodePtr; // synonym for ListNode

/* function prototypes */
void insert(ListNodePtr *sptr, char value);
char delete(ListNodePtr *sptr, char value);
int isEmpty(ListNodePtr sptr);
void instructions(void);
void printList(ListNodePtr currentPtr);

int 
main(void){
	ListNodePtr startPtr = NULL; //initially there are no nodes
	int choice;
	char item;
	
	instructions(); //used to display the menu
	printf("?");
	scanf("%d", &choice);
	
	while(choice != 3){
		switch(choice){
			case 1:
				printf("Enter a character: ");
				scanf("\n%c", &item);
				insert(&startPtr, item);
				printList(startPtr);
				break;
			case 2:
				if(!isEmpty(startPtr)){
					printf("Enter character to be deleted: ");
					scanf("\n%c", &item);
					if(delete(&startPtr, item)){
						printf("%c deleted.\n", item);
						printList(startPtr);
					}
					else {
						printf("%c not found.\n\n", item);
					}
				}
				else {
					printf("List is empty.\n\n");
				}
				break;
			default:
				printf("Invalid choice.\n\n");
				instructions();
				break;
		}
		instructions();
		printf("?");
		scanf("%d", &choice);
	}
	
	printf("End of run.\n");
return 0;
}

//function definitions of the prototypes above.
void instructions(void){
	printf("Enter your choice:\n"
		"1 to insert an element into the list.\n"
		"2 to delete an element from the list.\n"
		"3 to end.\n");
}

void insert(ListNodePtr *sptr, char value){
	ListNodePtr newPtr;
	ListNodePtr prevPtr;
	ListNodePtr curPtr;
	
	newPtr = malloc(sizeof(ListNode));
	
	if(newPtr != NULL){
		newPtr->data = value;
		newPtr->nextPtr = NULL;
		
		prevPtr = NULL;
		curPtr = *sptr;
		
		while(curPtr != NULL && value > curPtr->data){
			prevPtr = curPtr;
			curPtr = curPtr->nextPtr;
		}
		
		if(prevPtr == NULL){
			newPtr->nextPtr = *sptr;
			*sptr = newPtr;
		}
		else {
			prevPtr->nextPtr = newPtr;
			newPtr->nextPtr = curPtr;
		}
	}
	else {
		printf("%c not inserted. No memory available.\n", value);
	}
}

//funciton to delete elements in the linked list.
char delete(ListNodePtr *sptr, char value){
	ListNodePtr prevPtr;
	ListNodePtr curPtr;
	ListNodePtr tempPtr;
	
	if(value == (*sptr)->data){
		tempPtr = *sptr;
		*sptr = (*sptr)->nextPtr;
		free(tempPtr);
		return value;
	}
	else {
		prevPtr = *sptr;
		curPtr = (*sptr)->nextPtr;
		
		while(curPtr != NULL && curPtr->data != value){
			prevPtr = curPtr;
			curPtr = curPtr->nextPtr;
		}
		if(curPtr != NULL){
			tempPtr = curPtr;
			prevPtr->nextPtr = curPtr->nextPtr;
			free(tempPtr);
			return value;
		}
	}
	return '\0';
}

int isEmpty(ListNodePtr sptr){
	return sptr == NULL;
}

void printList(ListNodePtr curPtr){
	if(curPtr == NULL){
		printf("List is empty.\n\n");
	}
	else {
		printf("The list is: \n");
		
		while(curPtr != NULL){
			printf("%c --> ", curPtr->data);
			curPtr = curPtr->nextPtr;
		}
		
		printf("NULL\n\n");
	}
}
