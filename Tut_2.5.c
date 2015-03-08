/* This is a program to print the month of a year given the Month number*/
/* Anthor: Alangi Derick */
/* Day and Time: 9th Aug, 2013 & 9:45pm */


#include<stdio.h>

int main(void) {
	int Num;

	char *Months[] = {"\0", "January", "Febuary", "March", "April", "May", "June", 
			"July", "August", "September", "October", "November", "December"};
	
	printf("This application return the Month name when the Number is given.\n");

	printf("\n\nEnter the month number: ");
	scanf("%d", &Num);
	if(Num > 0 && Num < 13)
	printf("\nThe month is: %s.\n", *(Months + Num));
	
	else
		printf("Invalid Month number.\n");
	return 0;
}	
