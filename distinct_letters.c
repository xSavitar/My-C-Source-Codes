#include<stdio.h>
#include<string.h>

int Check(char *);

int main()
{
	char string[30];
	int catch;
	
	printf("Enter a string here: ");
	fgets(string, 30, stdin);
	strtok(string, "\n");

	catch = Check(string);
	if(catch == 0)
		printf("The letters are distinct.\n");
	else
		printf("The letters are not distinct.\n");

return 0;
}

int Check(char *string){
	int i, j;
	for(i = 0; i<= strlen(string); i++){
		for(j = i + 1; j<=strlen(string); j++)
			if(string[i] == string[j])
				return 1;
			}
			return 0;
}
