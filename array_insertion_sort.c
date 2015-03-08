/*                                                                   */
/* Name of file: array_insertion_sort.c            */
/* Author: Alangi Derick                                  */
/* Description: Implementation of an insertion sort algorithm from Introduction to Algorithm third edition */
/* date & time: Wed Jan 8, 12:12 am 2014 */

#include<stdio.h>

int main(void){

	int size_of_array;
	printf("Enter the size of your array with respect to the number of elements: ");
	scanf("%d", &size_of_array); //gets the size of array and store in memory

	int integer_array[size_of_array];

	int i, j, key; //declaration of variables that will be used for the sorting.

	printf("Enter %d elements into the array: ", size_of_array);
	for(i = 0; i<size_of_array; i++)
		scanf("%d", &integer_array[i]);
	
	//printing the unsorted list of items
	printf("The unsorted list is: ");
	for(i = 0; i<size_of_array; i++)
		printf("%d ", integer_array[i]);

	printf("\n\n");

	//now process the array and print the sorted array
	for(j = 1; j<size_of_array; j++){
		key = integer_array[j];
		i = j - 1;
		while(i >= 0 && integer_array[i] > key){
			integer_array[i + 1] = integer_array[i];
			i = i - 1;
			integer_array[i + 1] = key;
		}
	}
	//end of for

	printf("\nNow the sorted array is: ");
	for(i = 0; i<size_of_array; i++)
		printf("%d ", integer_array[i]);
	
	printf("\n\n");
	return 0;
}
