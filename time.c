/* Demonstate the time function. */

#include<stdio.h>
#include<time.h>

int main(void) 
{

	time_t start, finish, now;
	struct tm *ptr;

	char *c, buf1[80];
	double duration;

	/* Record the current time, using the alternate method fo calling the time() */

	time(&now);

	/* convert the time_t value into a type tm structure */

	ptr = localtime(&now);

	/* create and display a formatted string containing the current time */

	c = asctime(ptr);

	puts(c);
	getc(stdin);
	
	/* Now use the strftime() function to create several different formatted versions of the time */

	strftime(buf1, 80, "This is week %U of the year %Y", ptr);
	puts(buf1);
	getc(stdin);
	
	strftime(buf1, 80, "Today is %A, %x", ptr);
	puts(buf1);
	getc(stdin);
	
	/* now get the current time and calculate program duration */

	finish = time(0);
	duration = difftime(finish, start);

	printf("\nProgram execution time using time() = %f seconds.\n", duration);

	/* Also display duration in hundredths of seconds using clock() */

	printf("\nProgram execution time using clock() = %ld hundreths of sec.\n", clock());
	return 0;
}
	
