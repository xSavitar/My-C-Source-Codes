/* Author: Alangi Derick
   Program: Number of days in a particular month
*/

#include<stdio.h>

int main(void) {
	int i;

	struct month
	{
		int numberofdays;
		char name[3];
	};

	const struct month months[12] = 
	{ {31, "Jan"}, {28, "Feb"},
	  {31, "Mar"}, {30, "Apr"},
	  {31, "May"}, {30, "Jun"},
	  {31, "Jul"}, {31, "Aug"},
	  {30, "Sep"}, {31, "Oct"},
	  {30, "Nov"}, {31, "Dec"}};

	printf("Month   Number of Days\n");
	printf("-----   ---------------\n");

	for(i=0; i<12; ++i)
		printf(" %c%c%c              %i\n", months[i].name[0], months[i].name[1], months[i].name[2], months[i].numberofdays);

	return 0;
}
