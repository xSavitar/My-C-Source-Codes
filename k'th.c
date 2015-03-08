/* Program - This is a program that uses the function 'digit(n, k)' that returns the kth digit (from the right) in n (a positive interger). For example, digit(829, 1) returns 9, digit(829, 2) returns 2. If k is greater that the number of digits in n, have the function return 0. */

/* Author: Alangi Derick */
/* Date & Time: 7th Aug, 2013 & 10:04pm */

#include<stdio.h>

int digit(int, int);

int main(void)
{
	int Number, Kth_digit, num;

	printf("Enter a number: ");
	scanf("%d", &Number);

	printf("Enter the K'th digit: ");
	scanf("%d", &Kth_digit);

	num = digit(Number, Kth_digit);

	printf("The number is: %d.\n", num);
return 0;
}


int digit(int n, int k)
{
	int i;
	
	for(i = 1; i<k; i++)
		n/= 10;
	
	return n%10;
}


