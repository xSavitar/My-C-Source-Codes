#include<stdio.h>
#include<string.h>

int strlength(char *s);

int main(void)
{
	char array[50];
	printf("Enter text in the array: ");
	fgets(array, 50, stdin);
	strtok(array, "\n");

	int len = strlength(array);

	printf("The string length is %d.\n", len);
	printf("\n");

	return 0;
}

int strlength(char *s)
{
	int n;

	for(n = 0; *s != '\0'; s++)
		n++;
	return n;
}
