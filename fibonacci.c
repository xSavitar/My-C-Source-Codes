/*This is a program to print the fibonacci series of a number n*/
/*Author: Alangi Derick*/

#include<stdio.h>

int fib(int);

int main(void) {	
	int i, Num;

	printf("This application prints the fibonacci series.\n");
	
	printf("Enter a number: ");
	scanf("%d", &Num);

	printf("The series is: ");
	
	for(i=0; i<=Num; i++)
		printf("%d ", fib(i));

	printf("\n");

	return 0;
}


//function

int fib(int n) {
	
	if(n==0)
	return 0;
	else if(n==1 || n==2)
	return 1;
	else
		return (fib(n-1) + fib(n-2));
}
