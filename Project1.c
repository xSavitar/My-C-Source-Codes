/* Program: // project 1 - Telephone Directory */
/* Author: Alangi Derick */

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int request;
	char name[10], email[30];
	char Tel_Num[10];
	
	printf("This is a program Concerned with Telephone Directiories.\n");
	
	printf("\n\n-----------------------Menu-----------------------\n");
	printf("1. Add New Friend.\n"
		"2. Display Contact Information.\n"
		"3. Exit\n");
	
	printf("--------------------------------------------------\n");
	
	FILE *fp;
	
	fp = fopen("directory.txt", "w");
	
	l1: printf("\nEnter menu number: ");
	scanf("%d", &request);

	switch(request){
		case 1: 
			printf("\n------------New Friend Info--------------\n");
			printf("Name: ");
			scanf("%s", name);
		
			printf("Phone-No: ");
			scanf("%s", Tel_Num);
	
			printf("e-Mail: ");
			scanf("%s", email);
			fprintf(fp, "%s         %s       %s\n", name, Tel_Num, email);
			printf("\n");
			int cnt = 0;
			cnt++;
			goto l1;
			
		
		case 2: 
			fclose(fp);  //close the file
			
			fprintf(fp, "Name           Tel-No              E-mail Addr\n");
			printf("Name           Tel_No             E-mail\n");
			int i;
			char c;
			fp = fopen("directory.txt", "r"); //open read-only
			printf("---------------Contact Info-----------------------------\n");
			if(fp != NULL)
			{
			c = getc(fp); //reads the first character
			while(c != EOF) { //if not the end of file
			printf("%c", c);
			c = getc(fp); //read next character
			}
			fclose(fp);  //close the file
			}
			printf("--------------------------------------------------------\n");
			goto l1;
			
		case 3: 
			printf("Exiting.......\n");
			printf("Saving All Data.......\n");
			system("sleep 3");
			printf("Bye Bye !!!!!!");
			printf("\n");
			exit(1);
		}

	return 0;
}
