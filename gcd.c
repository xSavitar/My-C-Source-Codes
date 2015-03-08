/*Program: This is a program to calculate the GCD of two numbers using the Euclideans Algorithm*/
/* Author: Alangi Derick*/

#include<stdio.h>

int gcd(int, int);

int main(void) {
	
	int num1, num2;
	
	printf("This is a small application to calculate the GCD of two numbers.\n\n");
	printf("Starting Application......");
	printf("\n");
	
	system("sleep 3");
	printf("\nEnter two numbers: ");
	scanf("%d%d", &num1, &num2);

	int results = gcd(num1, num2);

	printf("\nThe gcd of %d and %d is %d.\n", num1, num2, results);
	return 0;
}

//gcd function

int gcd(int a, int b) {
	int temp;
	
	while(b!=0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
