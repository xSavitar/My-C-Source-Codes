/* Author: Alangi Derick
   Program: Finding the largest and smallest element in an array
*/

#include<stdio.h>

#define N 10

void max_min(int *, int, int *, int *);

int main(void) {
	
	printf("This is a small app to find the largest and smallest number in an array\n\n\n");
	int b[N], i, big, small;

	printf("Enter %d numbers: ", N);
	for(i=0; i<N; i++)
	  scanf("%d", &b[i]);

	max_min(b, N, &big, &small);
	
	printf("The largest number is: %d\n", big);
	printf("The smallest number is: %d\n", small);

	return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
	int i;

	*max = *min= a[0];
	for(i=1; i<n; i++){
	 if(a[i] > *max)
		*max = a[i];
	else if(a[i] < *min)
	 	*min = a[i];
	}
}
	
