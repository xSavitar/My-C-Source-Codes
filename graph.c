/*This is a program to print the adjacency matrix of an undirected graph*/
/*Author: Alangi Derick*/

#include<stdio.h>
#include<stdlib.h>

#define V 8

int main(void) {
	int i, j, a, adj[V][V];
	for(i=0; i<V; i++)
		for(j=0; j<V; j++)
		adj[i][j] = 0; /*initialise matrix*/
	for(i=0; i<V; i++) 
		adj[i][i] = 1; /*major diagonal*/

	/* now read in edges as vertex pairs*/
	printf("\nEnter vertex pairs - Press <ctrl-z> to end\n");
	while(scanf("%d%d", &i, &j) == 2) {
		adj[i][j] = 1;
		adj[j][i] = 1;
	}
	/*display matrix*/

	printf("\n\n");
	printf("The adjacency matrix is:\n");
	for(i=0; i<V; i++)
	if(i==0) 
	printf("%6d", i); /*1st column label indented*/
	else
		printf("%3d", i); /*other colomn labels*/
	printf("\n");

	for(i=0; i<V; i++) {
		printf("%3d", i); /*row lable*/
	for(j=0; j<V; j++)
	printf("%3d", adj[i][j]);
	printf("\n");
}
}
