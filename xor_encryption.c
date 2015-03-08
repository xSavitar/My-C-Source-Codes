/*This is a program that does the XOR encryption*/
/*Author: Alangi Derick reference from Mordern Approach*/

#include<stdio.h>
#include<ctype.h>

#define KEY '&'

int main(void) {
	int orig_char, new_char;

	printf("Enter text: ");
	while((orig_char = getchar()) != EOF) {
		new_char = orig_char ^ KEY;
		if(isprint(orig_char) && isprint(new_char))	
			putchar(new_char);
		else
			putchar(orig_char);	
	}
	return 0;
}

