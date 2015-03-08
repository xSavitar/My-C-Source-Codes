/* This is a program to interchange the position of two numbers */
/* Author: Alangi Derick */

#include<stdio.h>

void swap(int *, int *);

int main(void) {
	int val1, val2;
	
	/* Gets two numbers from the user*/
	
	printf("Enter two numbers sepatated by space: ");
	scanf("%d%d", &val1, &val2);
	
	/* Prints the initial inputed values */
	
	printf("The initial values entered are:- ");
	printf("\n\nval1 = %d and val2 = %d.\n", val1, val2);

	/* calls the swap function and swap the values */
	
	swap(&val1, &val2);

	/* Prints the swaped values */

	printf("\n\nThe numbers now are:- ");
	printf("\nval1 = %d and val2 = %d.\n", val1, val2);

	printf("\n");
	return 0;
}

//This is the swap function */


void swap(int *a, int *b) {
	int tmp = 0;
	tmp = *a;
	*a = *b; 
	*b = tmp;
	}
