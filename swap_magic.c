#include<stdio.h>

void swap(int *, int *);

int main(){
	int a= 10, b = 20;
	
	printf("Before swapping: a = %d and b = %d\n", a, b);
	swap(&a, &b);
	printf("After swapping: a = %d and b = %d\n", a, b);

return 0;
}

void swap(int *a, int *b){
	*a ^= *b, *b ^= *a, *a ^= *b;
}
