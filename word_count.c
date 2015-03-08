/* FILE: word_count.c
 * Author: Alangi Derick
 */

#include<stdio.h>

#define IN 1	/*inside a word */
#define OUT 0 	/*outside a word */

/* count lines, words, and characters in input */

int main(void)
{
	int c, nl, nw, nc, state;

	printf("Enter text: ");
	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF) {
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("Number of lines: %d \nNumber of words: %d \nNumber of characters: %d\n", nl, nw, nc);
	return 0;
}
