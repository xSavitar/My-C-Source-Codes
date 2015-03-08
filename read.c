#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINES 5000 /* max no of lines that can be read */
#define MAXLEN 1000 /*max line length */

char *lines[MAXLINES]; /* pointer to lines of text */
int read_line(char *, int); /*pointer to a single line of text*/
void write_lines(char *lines[], int line_cnt);

int main(void)
{
	int line_cnt; /*no of lines read*/
	if((line_cnt = read_lines(lines, MAXLINES)) >= 0) /*was read successfully*/
	write_lines(lines, line_cnt);
	else
		printf("Error: input too big\n");
	return 0;
	}

int read_lines(char *lines[], int maxlines) {
	
	int len; /*length of current line*/
	int line_cnt; /*no of lines read*/
	char line[MAXLEN]; /*lines will hold the line read*/
	char *p; /*p will point to the space that will be allocated for the line*/
	line_cnt = 0;
	while((len = read_line(line, MAXLEN)) > 0)
	/* signal error if line_cnt > MAXLINES or system runs out of memory fo array*/
	if((line_cnt >= maxlines) || (p = malloc(len * sizeof(char))) == NULL)
	return -1;
	else
	{
		line[len - 1] = 0;
	strcpy(p, line); /*copy line into allocated space*/
	lines[line_cnt++] = p; /*place pointer to line in array*/
	}
	return line_cnt;
	}

void write_lines(char *lines[], int line_cnt) {
	int i;
	for(i=0; i<line_cnt; i++)
	printf("%s\n", lines[i]);
	}
int read_line(char line[], int maxline) {
	int c, i;
	for(i=0; (i < maxline-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
	line[i++] = c;
	line[i] = 0;
	return i; /*return line length*/
}	
