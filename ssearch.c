/* file: ssearch.c */
/* Author: Alangi Derick */

#include<stdio.h>
#define N 10000 /* assume max # of chars is 10000 */

int main(int argc, char *argv[])
{
	
	FILE *fp;
	char a[N], *p = argv[1]; /*item to be searched for */
	
	fp = fopen("ssearch.txt", "r");
	int c, i, j;
	
	for(i = 0; i<N-1; a[i] = c, i++)
		if((c = getc(fp)) == EOF)
			break;
		a[i] = 0;

	/* now determine occurences of substring in array */
	for(i = 0; a[i] != 0; i++){
		for(j = 0; p[j]!= 0; j++)
			if(a[i+j] != p[j])
				break;
			if(p[j] == 0)
			printf("%d ", i);	/* print substring position */
	}
	printf("\n");
	fclose(fp);
	return 0;
}
