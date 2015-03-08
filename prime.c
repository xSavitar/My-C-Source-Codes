/* Author: Alangi Derick
   Program: Test for Prime numbers
   file: prime.c
   day and date: 4th Oct, 2013 && 2:53pm
*/

#include<stdio.h>

/*is_prime(int) prototype */
int is_prime(int);

int is_prime(int n)

{
	int divisor;
	if(n <= 1)
	return 0; /* returns false when n < = 1;  */
	
	for(divisor = 2; divisor * divisor <= n; divisor++)
	if(n%divisor == 0)
	return 0; /*returns false when n is divisible by other numbers. */
		return 1;	/* returns true when n is divisible by only 1 and its self and >= 2. */
}

int main(void) {
	int num;

	printf("Enter a Number: ");
	scanf("%d", &num); //gets the number 
	
	if(is_prime(num))
		printf("The number is a prime number.\n");
	else
		printf("The number is not a prime number.\n");

	return 0;
}
