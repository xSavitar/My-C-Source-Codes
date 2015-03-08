/* file: Calendar.c */
/* version: 4.10.13 */
/* written by: Alangi Derick (d3r1ck) */
/* description: The user enter a year and the program prints out the calendar for that entire year */


/* Header Includes */
#include<stdio.h>

#define TRUE 1
#define FALSE 0


/*Macro definition */
#define myname "Alangi Derick"

/* array of integers that hold the days in a particular month. */
int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/* An array of strings that holds the names of the twelve months of the year. */
char *months[] = 
{
	" ", 
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
	"\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember",
};

/* inputyear() is a routine that takes the year as input. */
int inputyear(void)
{
	int year;

	printf("Please enter a year (example: 2012): ");
	scanf("%d", &year);
	return year;
}


/* determinedaycode() is a routine that dynamically generates a daycode for the inputed year. */
int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1)/ 4;
	d2 = (year - 1)/ 100;
	d3 = (year - 1)/ 400;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


/* this routine checks whether a year is a leap year or not and the updates the array of integers above day_in_month[] */
int determineleapyear(int year)
{
	if(year % 4 == FALSE && year % 100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}


/* this is the function responsible for the printing of the calendar for the year inputed in the inputyear() function. */
void calendar(int year, int daycode)
{
	int month, day;
	for(month = 1; month <= 12; month++)
	{
		printf("%s", months[month]);
		printf("\n\nSun  Mon  Tues  Wed  Thu  Fri  Sat\n");
	
		//Correct the position for the first date
		for(day = 1; day <= 1 + daycode * 5; day++)
		{
			printf(" ");
		}

		//print all the dates for one month

		for(day = 1; day <= days_in_month[month]; day++)
		{
			printf("%2d", day);
		
			//Is day before Sat? Else start next line Sun.
			if((day + daycode) % 7 > 0)
				printf("   ");
			else
				printf("\n ");
		}
			//set position for next month
			daycode = (daycode + days_in_month[month]) % 7;
	}
}

int main(void)
{
	int year, daycode, leapyear;

	/* function calls for all the routines above */
	year = inputyear();
	printf("\n\nCALENDAR FOR THE YEAR %d", year);
	printf("\n---------------------------\n");
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);

	printf("\n\nThanks for using my Gregorian Calendar program.............");
	printf("\n\t\tWritten by ");
	printf(myname);

	printf("\n");
return 0;
}
