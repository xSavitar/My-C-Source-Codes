/* Program - Quick Sort Algorithm */
/* Writter: Alangi Derick */
/* Date & Time: 7th Aug, 2013 , 9:22pm */

#include<stdio.h>

#define N 10

void quicksort(int *, int low, int high);
int split(int *, int low, int high);

int main(void)
{
	int a[N], i;
	
	printf("--------------Quick Sort Algorithm---------------\n");
	printf("\n\nEnter %d numbers to be sorted: ", N);
	
	for(i = 0; i<N; i++)
		scanf("%d", &a[i]);

	quicksort(a, 0, N - 1);

	printf("\nIn sorted order: ");
	for(i = 0; i < N; i++)
		printf("%d ", a[i]);
	   printf("\n");


	printf("--------------Quick Sort Algorithm----------------\n\n");
	return 0;
}

void quicksort(int a[], int low, int high)
{
	int middle;
	
	if(low >= high)
		return;
	middle = split(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
	int part_element = a[low];
	
	for(;;) {
		while(low < high && part_element <= a[high])
			high--;
		if(low >= high)
			break;
		a[low++] = a[high];

		while(low < high && a[low] <= part_element)
			low++;
		if(low >= high)
			break;
		a[high--] = a[low];
		}
	a[high] = part_element;
	return high;
}
