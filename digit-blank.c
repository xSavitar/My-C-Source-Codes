/*This is a program to print blanks between a number*/
/*Author: Alangi Derick*/

#include<stdio.h>

void space(int, int *, int);

int main(void) {
	
	int number, i, size;
	printf("Enter the size of the array with respect to the number of digits: ");
	scanf("%d", &size);
	int array[size];
	
	printf("Enter a number (%d-digits): ", size);
	scanf("%d", &number);
	
	/*processes the number and adds the spaces to them*/
	space(number, array, size);

	/* prints the number with the spaces between them*/
	
	printf("The number is now: ");
	for(i=size-1; i>=0; i--)
		printf("%d ", array[i]);

	printf("\n");
	return 0;
}

//function

void space(int num, int a[], int n) {
	int i=0;	

	while(num != 0)	{
		a[i] = num % 10;
		i++;
		num = num/10;
	}
}
		
