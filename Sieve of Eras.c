/* Program: 3rd Century B.C, "Sieve Eratosthenes Algorithm" */
/* This is a program that prints the sum of all prime numbers less than 1000 */
/* Written by: Alangi Derick */

#include<stdio.h>

#define N 1000

int main(void) {
	long int sum = 0;
	int i, j, a[N+1];
	printf("Program that prints all prime numbers\n "
		"below %d\n", N);
	
	printf("\n\nPrime Numbers below %d: ", N);
	for(a[1] = 0, i = 2; i<=N; i++)
		a[i] = 1;
	for(i = 2; i<= N/2; i++)
		for(j = 2; j<=N/i; j++)
			a[i*j] = 0;
		for(i = 1; i<= N; i++){
			if(a[i])
			printf("%4d", i);
		}
	printf("\n");
return 0;
}
