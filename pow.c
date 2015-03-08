/* Program - This is the power function. */
/* Programming practice for the online contest. */
/* Time and day: 12:24am & Wed 14th Aug, 2013. */
/* Author: Alangi Derick */

/* This is a non-recursive algorithm implementation of the power function.
   The program takes as input the value a which is the base and another
   value n which is the exponent. The program calls the power function
   and outputs the results.
*/

#include<stdio.h>
double power(double, int);

int main(void)
{
	double a;
	int n;
	printf("Enter a number: ");
	scanf("%lf", &a);

	printf("Enter the power: ");
	scanf("%d", &n);

	int ans = power(a, n);

	printf("The answer is %d.\n", ans);

return 0;
}//end of main function

//this is the power function

double power(double a, int n)
{
	double ret = 1;
	while(n) {
		if(n%2 == 1)
		ret*=a;
		a*=a;
		n/=2;
		}
	return ret;
}
//end of the power function
