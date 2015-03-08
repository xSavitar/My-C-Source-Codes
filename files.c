/* Program-9.1 */
/* This is a program that reads characters from a file */
/* Author: Alangi Derick */

#include<stdio.h>

int main(void) {
	
	FILE *fp;
	char c;

	printf("This is a program that reads a file.\n");

	fp = fopen("Hello", "r"); //open read-only
	if(fp != NULL)
	{
		c = getc(fp); //reads the first character
		while(c != EOF) { //if not the end of file
			printf("%c", c);
			c = getc(fp); //read next character
		}
	fclose(fp);  //close the file
	}
	else
		printf("\nError while opening file....");
		printf("\n");
	
	return 0;
}
	
