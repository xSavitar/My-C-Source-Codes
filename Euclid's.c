/*Implementation of Euclid's Algorithm in the C programming language*/
/*Author: Alangi Derick*/

#include<stdio.h>
int gcd(int u, int v)
{
	int t;
	while(u>0)
		{
			if(u<v)
				{
					t = u;
					u = v;
					v = t;
				}
			u = u - v;
		}
	return v;
}


int main(void) {
	int x, y;
	l1: printf("Enter Values below: x and y.\n");
	while(scanf("%d %d", &x, &y) != EOF)
	if(x>0 && y>0)
		printf("The GCD of %d and %d is: %d.\n", x, y, gcd(x, y));
	else	
	{
		printf("The GCD is 0.\n");
		goto l1;
	}
	return 0;
}
