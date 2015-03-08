/* Program - Clearing stdin of extra characters. */
/* Author: Alangi Derick */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void clear_kb(void);

int main(void) 
{
	int age;
	char name[20];

	/* prompts for user's age. */

	printf("Enter your age: ");
	scanf("%d", &age);

	/* clears stdin of any extra characters. */

	clear_kb();

	/* Now prompts for user's name. */
	
	printf("Enter your first name: ");
	scanf("%s", name);

	/* Display the data. */

	printf("Your age is: %d.\n", age);
	printf("Your name is: %s.\n", name);

	return 0;
}// end of main function


//this is the clear_kb function

void clear_kb(void)
/* Clears stdin of any waiting characters. */

{
	char junk[80];
	fgets(junk, 80, stdin);
	strtok(junk, "\n");
}

//end of program
