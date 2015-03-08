/* FILE: 2x2 matrix.c
 * Version: unknown
 */

#include<stdio.h>
#include<stdlib.h>
#define N 2

int main(void)
{
	int i, j, b[N][N], a[N][N], c[N][N];
	printf("Enter the elements in the matrix. ");
	printf("\nMatrix 1.\n");
	for(i = 0; i<N; i++){
		for(j = 0; j < N; j++){
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}

	printf("\nMatrix 2.\n");
	
	for(i = 0; i<N; i++){
		for(j = 0; j < N; j++){
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &b[i][j]);
		}
	}

	printf("\nSumming the matrices....\n");
	system("sleep 3");
	printf("\n");

	for(i = 0; i<N; i++)
		for(j=0; j<N; j++)
			c[i][j] = a[i][j] + b[i][j];


	printf("\nThe results M is: \n");
	for(i = 0; i<N; i++){
		for(j = 0; j < N; j++){
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}

return 0;
}
