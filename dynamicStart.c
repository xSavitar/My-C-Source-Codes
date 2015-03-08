/* Filename: dynamicStart.c */
/* Description: Dynamic Start Program */

#include<stdio.h>
#include<stdlib.h>

//self-referential structures
struct stackNode {
	int data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

/* function prototypes */
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr curPtr);
void instructions(void);

//this is the main function
int main(void){
	StackNodePtr stackPtr = NULL;
	int choice;
	int value;
	
	instructions();
	printf("?");
	scanf("%d", &choice);
	
	while(choice != 3){
		switch(choice){
			case 1: 
				printf("Enter an integer: ");
				scanf("%d", &value);
				push(&stackPtr, value);
				printStack(stackPtr);
				break;
			case 2:
				if(!isEmpty(stackPtr)){
					printf("The popped value is %d.\n", pop(&stackPtr));
				}
				printStack(stackPtr);
				break;
			default:
				printf("Invalid choice.\n\n");
				instructions();
				break;
		}
		printf("?");
		scanf("%d", &choice);
	}
	printf("End of run.\n");
return 0;
}

//function definitions

//display program instructions to the user
void instructions(void){
	printf("Enter choice:\n"
		"1 to push a value on the stack\n"
		"2 to pop a value off the stack\n"
		"3 to end program\n");
}

//insert a node at the stack top
void push(StackNodePtr *topPtr, int info){
	StackNodePtr newPtr;
	
	newPtr = malloc(sizeof(StackNode));
	
	if(newPtr != NULL){
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else {
		printf("%d not inserted. No memory available.\n", info);
	}
}

//this is the pop function
int pop(StackNodePtr *topPtr){
	StackNodePtr tempPtr;
	int popValue;
	
	tempPtr = *topPtr;
	popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return popValue;
}

//print the stack
void printStack(StackNodePtr curPtr){
	if(curPtr == NULL){
		printf("The stack is empty.\n\n");
	}
	else {
		printf("The stack is: \n");
		while(curPtr != NULL){
			printf("%d --> ", curPtr->data);
			curPtr = curPtr->nextPtr;
		}
		printf("NULL\n\n");
	}
}

//function to test if list is empty
int isEmpty(StackNodePtr topPtr){
	return topPtr == NULL;
}
