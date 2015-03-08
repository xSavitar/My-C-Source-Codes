/* FILE: largest_div.c
 * Version: 0.0.0
 * Program: Finding the smallest number divisible by each of the numbers 1 to 20
 * Date and Time: 30th Aug, 2013 & 12:09pm
 */

/*library includes*/
#include<stdio.h>

/*Macros includes*/
#define N 20

/*routine definitions(prototypes) are.*/
double fact(int);

//definition of the main()
int main(void)
{
	int Num, i;
	double div;
	printf("This is the set of divisors: {");
		for(i = 1; i<=N; i++)
	printf(" %d, ", i);
	printf(" }");

	printf("\nEnter the smallest number: ");
	scanf("%d", &Num);
	
	printf("Number			   Answer	   	    Divisor.\n");
	for(i = 1; i<=20; i++){
		div = fact(Num)/i;
		printf("%lg		%lg		      %d\n", fact(Num), div, i);
		}
	printf("\n");
	return 0;
}

//subroutine for the factorial
double fact(int n)
{
	if(n <= 1)
		return 1;
	else 	
		n*=fact(n-1);
		return n;
}
