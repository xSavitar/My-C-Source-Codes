/* Detecting end-of-file. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 100

int main(void)
{
	char buf[BUFSIZE];
	char filename[60];

	FILE *fp;

	printf("Enter name of text file to display: ");
	fgets(filename, 60, stdin);
	strtok(filename, "\n");

	/* Open the file for reading. */

	if((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Error opening file.");
		exit(1);
	}
	/* If end of file not reached, read a line and display it. */
	
	while(!feof(fp))
	{
		fgets(buf, BUFSIZE, fp);
		printf("%s", buf);
	}
	fclose(fp);
	return 0;
}
