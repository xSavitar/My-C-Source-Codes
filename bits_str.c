/* This is a program to determine the number of 1's in a bit string */
/* Author: Alangi Derick */

#include<stdio.h>
#define bits 8

int main(void) {
	
	int number, i =0, cnt = 0;
	static int array[bits];
	
	/*Get a number from the user */
	printf("Enter a number: ");
	scanf("%d", &number);


	printf("Processing your number........\n");
	system("sleep 3");
	/* This part of the program does the binary conversion */
	
	while(number != 0) {
		array[i] =number % 2;
		i++;
		number =number / 2;
		}

		printf("\n\nThe number in binary form is: ");
			for(i = bits - 1; i>= 0; i--)
		printf("%d ", array[i]);

	/* After doing the binary conversion of the number */

	/* Now we have to determine how many number of ones
		are in the bit string*/


	for(i = 0; i<bits; i++){
		if(array[i] == 1)
		cnt++;
		}

	/* Counting the number of ones in the string */
	
	printf("\n\nCounting the number of 1's........\n");
	system("sleep 3");
	printf("\n\nThe number of 1's in the bit string is %d.\n", cnt);
	
	printf("\n");
	return 0;
}
