/* FILE: star.c
 * Version: 1.9.0
 * Program: This is the implementation of a small algorithm to print stars
 */

/* Library Includes */
#include<stdio.h>

int main(void)	//main defintion
{
	int i, j;
	for(i = 0; i <= 5; i++)	//outer loop
	{
		for(j = 0; j <= i; j++)	 //inner loop controlled by outer
		{
			printf("*"); //prints the stars in ascending order
		}
	printf("\n");
	}
	for(i = 5; i >0; i--)	//outer loop
	{
		for(j = i; j > 0; j--)	//inner loop controlled by outer
		{
			printf("*"); //prints the stars in descending order
		}
	printf("\n");
	}
	return 0; //controlled is passed back to main
}
