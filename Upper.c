/*Program to change Lower-case text to Upper-case*/
/*Author: Alangi Derick*/

#include<stdio.h>
#include<string.h>

void convert(char *, int n);

int main(void) {
	
	printf("This program converts lower case text to its corresponding upper-case.\n\n");

	char text[100];

	printf("Enter some text: ");
	scanf("%s", text);

	convert(text, strlen(text));


	printf("The upper case text is: ");
	printf("%s.\n", text);
	return 0;
}


//function

void convert(char a[], int n) {
	int i;
	for(i=0; i<n; i++) 
		a[i]=toupper(a[i]);
		}
