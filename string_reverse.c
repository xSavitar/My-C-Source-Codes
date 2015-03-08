#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(void){
	char *s;
	register int t;
	
	s = (char *)malloc(80); // (char *) forces the void * to a char *
	if(!s){
		printf("Memory request failed \n");
		exit(1);
	}
	
	printf("Enter a Sentence: ");
	gets(s); //used for passing arrays into funcitons stdlib function
	
	printf("The Reverse Sentence is: ");
	for(t=strlen(s)-1; t>=0; t--)
		putchar(s[t]);
	
	printf("\n");
	free(s);
}
