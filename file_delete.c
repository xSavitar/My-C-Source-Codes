/* Program - Demonstrates the remove() function */
/* Author: Alangi Derick */

#include<stdio.h>
 
int main(void)
{
	char filename[80];
	
	printf("Enter the filename to delete: ");
	/* Gets the filename from the user*/
	fgets(filename, 80, stdin);

	/* calls the string tok function to remove the new line('\n')
	   character*/

	strtok(filename, "\n");

	if(remove(filename) == 0)
		printf("The file %s has been deleted.\n", filename);

	else
		fprintf(stderr, "Error deleting the file %s.\n", filename);

	return 0;
}
	
