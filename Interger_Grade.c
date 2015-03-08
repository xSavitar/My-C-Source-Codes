/*************************************@I*************************************
 FILE        : Interger_Grade.c
 VERSION     : 15.8.13 
 AUTHOR      : Alangi Derick
 START DATE  : 08/15/2013 [mm/dd/yyyy]
 DESCRIPTION : Grading Program that returns the grade of an inputed interger.
**************************************@F************************************/

/* Library Includes */
#include<stdio.h>

/* Function Prototype includes */
char *Grading_Object_Module(int);

/* Main function */

int main(void)
{
	int Mark;
	//int Return_Grade;
	
	printf("This program return the grade of a Student's Inputed Mark.\n");
	
	/* User inputs the marks here... */

	printf("Enter Your mark: ");
	scanf("%d", &Mark);
	
	printf("\n");
	printf("Processing Your Mark...\n");

	system("sleep 3");

	/* Function Grading_Object_Module is being called here.. */

	/* Outputs the grade of the student */

	printf("The corresponding is grade is: %s.\n", Grading_Object_Module(Mark));

	printf("\n\nThis is just a Demo Version of this program.\n");
	printf("\n\tTry to get a Full version at www.Unknown.com.\n");

	/* Control is passed back to main */
	return 0;
}

/* Redefinition of the Grading_Object_Module function */
char *Grading_Object_Module(int Number)
{
	/* Initialisation of an array of strings that holds the grade of each mark */
	
	char *Grading_Std[] = {"\0", "A+", "A", "B+", "B", "C", "F", "Invalid Number"};
	
	/*Here the program does a control flow search to see if the Integer matches the grade*/
	
	if(Number >100 || Number < 0)
		return *(Grading_Std + 7);
	if(Number >= 90 && Number <= 100)
		 return *(Grading_Std + 1);
	else if(Number >= 80 && Number <= 89)
		return *(Grading_Std + 2);
	else if(Number >= 70 && Number <= 79)
		return *(Grading_Std + 3);
	else if(Number >= 60 && Number <= 69)
		return *(Grading_Std + 4);
	else if(Number >= 50 && Number <= 59)
		return *(Grading_Std + 5);
	else if(Number < 50)
		return *(Grading_Std + 6);
} // End of the Grading_Object_Module function
