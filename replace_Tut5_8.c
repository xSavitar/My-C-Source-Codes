/* Program - This is a program that replaces the spaces in a given text */
/* Author: Alangi Derick */
/* Day and Time: Fri 09th Aug, 2013 & 11:00pm */

#include<stdio.h>
#include<string.h>

int replace(char *, int);

int main(void)
{
	char text[50];
	
	printf("Enter some text: ");
	//gets the text here and stores it in memory

	fgets(text, 50, stdin);
	
	strtok(text, "\n");

	int count = replace(text, strlen(text));

	printf("\nThe replaced text is: %s.\n", text);
	printf("\nThe number of spaces replaced are %d.\n", count);

	return 0;
}

//this is the replace function

int replace(char text[], int n)
{
	int i, counter = 0;
	for(i = 0; i < n; i++){	
		if(text[i] == ' '){
			text[i] = '-';
			counter++;
			}
		}
	return counter;
}
	
	
