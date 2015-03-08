/* FILE: Reverse.c
 * VERSION: 0.0.0
 * PROGRAM: prints the digits of a number in the reverse order
 */

/* Libreary Includes */
#include<stdio.h>

//this is the main function definition
int main(void)
{
	int value, r_digit;
	printf("Enter the number and see the reverse: ");
	scanf("%d", &value);
	do
	  {
	    r_digit = value % 10;
	    printf("%d", r_digit);
	    value = value / 10;
	  }while(value != 0);
	printf("\n");
return 0;
}
