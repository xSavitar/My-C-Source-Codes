/* Using qsort() and bsearch() with strings. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 20

int comp(const void *s1, const void *s2);

int main(void) {
	
	char *data[max], buf[80], *key, **key1, *ptr;
	int count;

	/* Input a list of words */

	printf("Enter %d words, pressing Enter after each.\n", max);

	for(count = 0; count < max; count++) {
		printf("Word %d: ", count + 1);
		gets(buf);
		data[count] = malloc(strlen(buf) + 1);
		strcpy(data[count], buf);
		}

	/* sort the words (actually, sort the pointers). */

	qsort(data, max, sizeof(data[0]), comp);

	/* Display the sorted words */

	for(count = 0; count < max; count++)
		printf("\n%d: %s", count + 1, data[count]);


	/* Get a search key */

	printf("\nEnter a search key: ");
	gets(buf);

	/* Perform the search. First, make key1 a pointer to the pointer to the search key */

	key = buf;
	key1 = &key;

	ptr = bsearch(key1, data, max, sizeof(data[0]), comp);

	if(ptr!=NULL)
		printf("%s found.\n", buf);

	else
		printf("%s not found.\n", buf);

	return 0;
}


//function of the compare


int comp(const void *s1, const void *s2) {
		return (strcmp(*(char **)s1, *(char **)s2));
}


