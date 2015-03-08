/*This is a program to calculate the exponent of a number E^x*/
/*Author: Alangi Derick*/

#include<stdio.h>
long int factorial(int); 
int power(int, int);

long int factorial(int n) {
	if(n<=1)
	return 1;
	else
		n*=factorial(n-1);
	}

int power(int n, int a) {
	int i, x;
	if(i==1)
	return n;
	else
		for(i=2, x=n; i<=a; i++)
		n*=x;
	return n;
}

int main(void) {
	int x, i, n;
	float E_x=1;

	printf("Enter the values of x and n: ");
	scanf("%d%d", &x, &n);
	
	for(i=1; i<=n; i++)
	E_x+= (float) power(x, i)/factorial(i);
	

	printf("The results of this calculation is: \n");
	
	printf("\t\tE^x = %f\n", E_x);
	printf("\n");
return 0;
}
