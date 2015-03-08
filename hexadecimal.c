/* Author: Alangi Derick
   Program: Decimal to Hexadecimal convertion
*/


#include<stdio.h>

char hex(int );

int main(void) {

	printf("This app is to convert from Decimal to Hexadecimal\n");
	int n;

	l1: printf("\nEnter a Number between 1 - 15: ");
	scanf("%d", &n);

	if(n>=0 && n<16){
	printf("The Hexadecimal form is: %c\n", hex(n));
	goto l2;
}
	else
		printf("You Exceeded your limit.\n");
		printf("Try Again.....\n");
		goto l1;
	l2: return 0;
}

//function

char hex(int num){
	return "0123456789ABCDEF"[num];
}
