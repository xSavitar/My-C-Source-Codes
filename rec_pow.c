/* Program - This is the power function. */
/* Programming practice for online contest. */
/* Time and day: 12:24am & Wed 14th Aug, 2013. */
/* Author: Alangi Derick */

/* This is a recursive algorithm implementation of the power function.
   The program takes as input the value 'a' which is the base and another
   value 'n' which is the exponent. The program calls the power function
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

double power(double a, int n)
{
	if(n == 0)
		return 1;
	if(n == 1)
		return a;
	double t = power(a, n/2);
	return t * t * power(a,n%2);
}
