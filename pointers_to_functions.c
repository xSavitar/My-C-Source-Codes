/* file: pointers_to_functions.c
 * date and time: 21st Sept, 2013 & 11:00pm 
 */
#include<stdio.h>

int div_two(int);

/* this is a pointer to the function div_two, improves flexibility(very neccesary) */
int (*ptr)(int n);	

int main()
{
	int Number;

	printf("Enter a number: ");
	scanf("%d", &Number);

	ptr = div_two;	/* here, the pointer points to the function */

	if(!(*ptr)(Number))
		printf("Done!\n");

	return 0;
}

int div_two(int n)	//function definition.
{
	printf("%d\n", n/2);
	return 0;
}
