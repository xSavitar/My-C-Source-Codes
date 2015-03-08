#include<stdio.h>
#include<ctype.h>

int main(void)
{
	int counter=0,i;
	char ch, letter[300];

	printf("Enter the message to be encrypted: ");
	for(i=0; counter<300; i++){
	scanf("%c", &letter[i]);

	if(letter[i] == '\n'){
	break;
	}

	counter++;

	if(letter[i] == ' '){
	continue;
	}

	letter[i] = toupper(letter[i]);

	if(letter[i] >= 65 && letter[i] <= 91){

	letter[i]=((((letter[i]-65)*3)+7)%26)+65;
	}
}
	printf("\nThe encrypted message is: ");
	for(i=0; i<counter; i++){
	printf("%c", letter[i]);
	}
	printf("\n");
return 0;
}
