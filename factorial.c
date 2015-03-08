/* Program to calculate the factorial of a number */

/* ? Author: Alangi Derick ? */

#include<stdio.h>
long int factorial(int);

int main(void) {
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	long int f;
	f=factorial(num);
	
	printf("The factorial of %d is %ld.\n", num, f);
return 0;
}

//function

long int factorial(int n) {
	if(n<=1)
	return 1;
	else
		n*=factorial(n-1);
	}
