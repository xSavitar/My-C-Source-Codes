/**************************************************************************************
 * FILE: binary.c
 * AUTHOR: Alangi Derick Ndimnain
 * Day and Time: Sat 17th August, 2013
 * Program: Implementation of a binary search tree with all its subroutines
 * Version: Assignment from Nya Check (Computer Engineering Student, University of Buea
 **************************************************************************************/

/* Header files includes */

#include <stdio.h>
#include <stdlib.h>

/* Macro Definitions */
#define myname "Alangi Derick"

/* Declaration of BST structure */

typedef struct BST
{
    int data;
    struct BST *left_child, *right_child;
}node;

// function definitions called in main

void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node *, int, node **);

//this is the main function
void main()
{
 int choice;
 char ans;
 int key;
 node *new_node, *root, *tmp, *parent;
 node *get_node();
 root = NULL;
 //clrscr();
 /* Usage of Predefined Macros in C */

 printf("You just compiled and ran File: %s at Time: %s on Date: %s.\n", __FILE__, __TIME__, __DATE__);

	/* Reference: C Programming A Mordern Approach 2nd Edition.pdf */

 printf("\nProgram For Binary Search Tree ");
 do
 {
   printf("\n1.Create");
   printf("\n2.Search");
   printf("\n3.Recursive Traversals");
   printf("\n4.Exit");
   printf("\nEnter your choice :");
   scanf("%d", &choice);

   switch(choice)
   {
    case 1:
           do
             {
             new_node = get_node();

             printf("\nEnter The Element ");
             scanf("%d", &new_node->data);

             if(root == NULL)   /* Tree is not Created */
                 root = new_node;
             else
                 insert(root, new_node);

             printf("\nWant To enter More Elements?(y/n)");
             ans = getchar();

             }while(ans == 'y');

             break;

     case 2:
             printf("\nEnter Element to be searched :");
             scanf("%d", &key);

             tmp = search(root, key, &parent);
	
         		printf("\nParent of node %d is %d",
                              tmp->data, parent->data);
             break;

    case 3:

            if(root == NULL)
                printf("Tree Is Not Created");
            else
               {
               printf("\nThe Inorder display : ");
               inorder(root);
               printf("\nThe Preorder display : ");
               preorder(root);
               printf("\nThe Postorder display : ");
               postorder(root);
               }

            break;
    }
 }while(choice != 4);
	printf("Exiting the program...\n");
	system("sleep 3");
	printf("\n\nThis Program is written ");
	printf(myname);
	printf("\n");
}
/*
  Get new Node 
*/
node *get_node()
 {
 node *temp;
 temp=(node *)malloc(sizeof(node));
 temp->left_child = NULL;
 temp->right_child = NULL;
 return temp;

 }//end of main function.
/*
  function for creating a binary search tree 
*/
void insert(node *root, node *new_node)
{
  if(new_node->data < root->data)
     {
     if(root->left_child == NULL)
         root->left_child = new_node;
     else
         insert(root->left_child, new_node);
     }

  if(new_node->data > root->data)
     {
     if(root->right_child == NULL)
         root->right_child = new_node;
     else
         insert(root->right_child, new_node);
     }
}
/*
This function is for searching the nodes of the
      binary Search Tree
*/
node *search(node *root, int key, node **parent)
{
 node *temp;
 temp = root;
    while(temp != NULL)
    {
      if(temp->data == key)
         {
         printf("\n The %d Element is Present", temp->data);
         return temp;
         }
      *parent = temp;

      if(temp->data > key)
         temp = temp->left_child;
      else
         temp = temp->right_child;
    }
 return NULL;
}
/*
This function displays the tree in inorder manner
*/
void inorder(node *temp)
{
   if(temp != NULL)
    {
    inorder(temp->left_child);
    printf("%d ", temp->data);
    inorder(temp->right_child);
    }
}
/*
This function displays the tree in preorder manner
*/
void preorder(node *temp)
{
 if(temp!=NULL)
    {
    printf("%d ", temp->data);
    preorder(temp->left_child);
    preorder(temp->right_child);
    }
}

/*
This function displays the tree in postorder manner
*/
void postorder(node *temp)
{
 if(temp != NULL)
    {
    postorder(temp->left_child);
    postorder(temp->right_child);
    printf("%d ", temp->data);
    }
}
