/* Program - This is a program to convert Numbers to Words */
/* Date: 04 Aug, 2013 */
/* This program uses Derick's Algorithm */
/* Author: Alangi Derick */

/*******************************************************************************************************************************************************/
/* This program is going to take as input a natural number and converts it to its corresponding word. This program will pass the number inputed by the */
/* 					user to a function and returns the word form of the number						       */


#include<stdio.h>
#include<string.h>

int Whole(int);
int Remain(int);
int Hundred(int);
int Unit_of(int);

int main(void)
{
	int W, R, H, Unit;
	char *Num_Word[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", 					"fourteen", "fiftheen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "fourty", "fifty", "sixty", 						"seventy", "eighty", "ninety", "One hundred"};
	
	int Num;
	printf("Enter a number: ");
	scanf("%d", &Num);
	
	if(Num<0)
		printf("You inputed an invalid number.\n");
	else if(Num<=20)
		printf("The number is: %s.\n", *(Num_Word + Num));

	else if(Num==30)
		printf("The number is: %s.\n", *(Num_Word + 21));
	
	else if(Num==40)
		printf("The number is: %s.\n", *(Num_Word + 22));

	else if(Num==50)
		printf("The number is: %s.\n", *(Num_Word + 23));

	else if(Num==60)
		printf("The number is: %s.\n", *(Num_Word + 24));

	else if(Num==70)
		printf("The number is: %s.\n", *(Num_Word + 25));

	else if(Num==80)
		printf("The number is: %s.\n", *(Num_Word + 26));

	else if(Num==90)
		printf("The number is: %s.\n", *(Num_Word + 27));

	else if(Num==100)
		printf("The number is: %s.\n", *(Num_Word + 28));

	
	else if(Num > 20 && Num < 30) {
		W = Whole(Num);
		R = Remain(Num);
		printf("The number in words is: %s %s.\n", *(Num_Word + 20), *(Num_Word + R));
		}

	
	else if(Num > 30 && Num < 40) {
		W = Whole(Num);
		R = Remain(Num);
		printf("The number in words is: %s %s.\n", *(Num_Word + 21), *(Num_Word + R));
		}

	else if(Num > 40 && Num < 50) {
		W = Whole(Num);
		R = Remain(Num);
		printf("The number in words is: %s %s.\n", *(Num_Word + 22), *(Num_Word + R));
		}

	else if(Num > 50 && Num < 60) {
		W = Whole(Num);
		R = Remain(Num);
		printf("The number in words is: %s %s.\n", *(Num_Word + 23), *(Num_Word + R));
		}

	else if(Num > 60 && Num < 70) {
		W = Whole(Num);
		R = Remain(Num);
		printf("The number in words is: %s %s.\n", *(Num_Word + 24), *(Num_Word + R));
		}

	else if(Num > 70 && Num < 80) {
		W = Whole(Num);
		R = Remain(Num);
		printf("The number in words is: %s %s.\n", *(Num_Word + 25), *(Num_Word + R));
		}

	else if(Num > 80 && Num < 90) {
		W = Whole(Num);
		R = Remain(Num);
		printf("The number in words is: %s %s.\n", *(Num_Word + 26), *(Num_Word + R));
		}

	else if(Num > 90 && Num < 100) {
		W = Whole(Num);
		R = Remain(Num);
		printf("The number in words is: %s %s.\n", *(Num_Word + 27), *(Num_Word + R));
		}

	else if(Num > 100 && Num < 1000){
		H = Hundred(Num);
		Unit = Unit_of(Num);
		R = Remain(Unit);

		if(Unit_of(Num) <= 20)
		printf("The number is: %s hundred and %s.\n", *(Num_Word + H), *(Num_Word + Unit));

		}
return 0;

}
		

// function Whole

int Whole(int N)
{
	int num;
	num = ((N / 10) * 10);
	return (num);
}

int Remain(int N)
{
	int number;
	number = N % 10;
	return number;
}


int Hundred(int n)
{
	int number;
	number = n / 100;
	return number;
}

int Unit_of(int n)
{
	int num;
	num = n % 100;
	return num;
}
