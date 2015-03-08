/* Filename: BinarySearchTree.c */
/* Author: Alangi Derick */
/* Description: Creating a BST and Traversing it in PreOrder, PostOrder and InOrder. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//pointer to treenode
typedef struct treeNode *LINK;

/* self-referential structure */
struct treeNode {
	int data;
	LINK rightPtr;
	LINK leftPtr;
};

//function prototypes
void insertNode(LINK *treePtr, int value);
void inOrder(LINK treePtr);
void preOrder(LINK treePtr);
void postOrder(LINK treePtr);

//main function definition
int
main(void){
	int i, item;
	LINK rootPtr = NULL; //initially, the tree is empty
	
	srand(time(NULL));
	printf("The numbers being placed in the tree are: ");
	
	for(i = 1; i<=10; i++){
		item = rand() % 15;
		printf("%3d ", item);
		insertNode(&rootPtr, item);
	}
	
	printf("\n\nThe preOrder traversal is: ");
	preOrder(rootPtr);
	
	printf("\n\nThe inOrder traversal is: ");
	inOrder(rootPtr);
	
	printf("\n\nThe postOrder traversal is: ");
	postOrder(rootPtr);
	
printf("\n");
return 0;
}

//this is the insert node routine.
void insertNode(LINK *treePtr, int value){
	if(*treePtr == NULL){
		*treePtr = malloc(sizeof(LINK));
		
		if(*treePtr != NULL){
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		}
		else {
			printf("%d not inserted. No memory available.\n", value);
		}
	}
	else {
		if(value < (*treePtr)->data){
			insertNode(&((*treePtr)->leftPtr), value);
		}
		else if( value > (*treePtr)->data){
			insertNode(&((*treePtr)->rightPtr), value);
		}
		else {
			printf("dup");
			}	
	}
}

//inorder print routine.
void inOrder(LINK treePtr){
	if(treePtr != NULL){
		inOrder(treePtr->leftPtr);
		printf("%3d", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}


//preorder print routine.
void preOrder(LINK treePtr){
	if(treePtr != NULL){
		printf("%3d", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}

//post order print routine
void postOrder(LINK treePtr){
	if(treePtr != NULL){
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%3d", treePtr->data);
	}
}
