/* This is a program that sorts words in ascending order, or rather in Alphabetic order */
/* Author: Alangi Derick */
/* Date: Aug 03, Saturday 2013*/
/* Time: 1:18pm finished*/

#include<stdio.h>
#include<string.h>

#define N 8
#define MAXNAME 15

void swap(char *, char *);
void bubble(char a[][MAXNAME], int n);
void get_array(char a[][MAXNAME], int n);
void print_array(char a[][MAXNAME], int n);

int main(void) 
{
	char array[N][MAXNAME];
	get_array(array, N);
	printf("\nBefore Sorting\n");	
	print_array(array, N);
	bubble(array, N);
	printf("\nAfter Sorting\n");
	print_array(array, N);
return 0;
}

void get_array(char a[N][MAXNAME], int n)
{
	int i;
	printf("Enter %d words not upto %d characters each.\n", N, MAXNAME);
	for(i = 0; i<N; i++)
		scanf("%s", a[i]);
}

void bubble(char a[N][MAXNAME], int n)
{
	int i, j;
	for(i =0; i<n-1; i++)
		for(j=n-1; j>i; j--)
			if(strcmp(a[j-1], a[j]) > 0)
				swap(a[j-1], a[j]);
}

void print_array(char a[N][MAXNAME], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%s\n", a[i]);
	printf("\n");
}

void swap(char *n1, char *n2)
{
	char tmp[MAXNAME];
	strcpy(tmp, n1);
	strcpy(n1, n2);	
	strcpy(n2, tmp);
}
