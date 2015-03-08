#include<stdio.h>

int AddMachine(int, int);
int (*add)(int, int);

int main(void){

	int a, b, sum = 0;

	//this is a program that does addition of two numbers using pointers
	//to function
	printf("Enter value 1: ");
	scanf("%d", &a);

	printf("Enter value 2: ");
	scanf("%d", &b);

	add = AddMachine;
	sum = add(a, b);

	printf("The sum of %d and %d is: %d\n", a, b, sum);
	return 0;
}

//this is the adding machine function
int AddMachine(int a, int b){
	return (a+b);
}