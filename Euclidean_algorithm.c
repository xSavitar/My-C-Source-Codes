/* Program - This is a program that implements the Euclidean's algorithm.*/
/* Author: Alangi Derick. */

#include<stdio.h>
int gcd(int, int);

int main(void)
{
	int a, b;
	printf("Enter two values separated by spaces: ");
	scanf("%d%d", &a, &b);

	int ans = gcd(a, b);

	printf("The GCD of %d and %d = %d.\n", a, b, ans);
return 0;
}//end of the main function

int gcd(int a, int b)
{
	while(b)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}//end of the gcd function
