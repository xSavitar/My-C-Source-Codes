/* FILE: Natural.c
   Program: Add all the natural numbers below one thousand that are multiples of 3 or 5.
   Date and Time: Sat 24th Aug, 2013 & 3:28pm.
 */


/* Library Includes */
#include<stdio.h>
#include<stdlib.h>

/* This is the subroutine prototype. */
int is_Multiple_of(int);

/* Macros include */
#define N 1000

//here is the definition of the main function
int main(void)
{
	int number, i = 0;
	long int sum = 0;
	
	printf("Adding all Natural numbers below one thousand that are multiples of 3 and 5.\n");
	printf("\nAdding the numbers...");
	printf("\n");
	system("sleep 3");
	
	for(i =1 ; i <= N; i++)
		sum+= is_Multiple_of(i); //calls the subroutine here.
	printf("\nThe sum of all the natural numbers is: %ld.\n", sum);
	printf("This is cool huh......\n");
	return 0;
}

//redeclaration of the subroutine.
int is_Multiple_of(int n)
{
	if(n % 3 == 0 || n % 5 == 0)
		return n;
	else
		return 0;
}
