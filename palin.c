#include<stdio.h> 
//#include<conio.h>

#define EOL '\n' 
#define TRUE  1 
#define FALSE 0

int main()  {

	int count,tag,countback,flag,loop=TRUE; 
	char letter[80];

	//clrscr(); 
		while (loop) { 
 			flag=TRUE; 
 			printf("\nPROGRAM TO CHECK FOR A PALINDROME\n"); 
 			printf("\nPlease enter a word,pharse or sentence below\n"); 
 				for (count=0;(letter[count]=getchar())!=EOL;++count) 
 					if ((letter[0]=='E'||letter[0]=='e')&&(letter[1]=='N'||letter[1]=='n') 
 						&&(letter[2]=='D'||letter[2]=='d')) { loop=FALSE;break;
			} 
 			tag=count-1;

 			for ((count=0,countback=tag);count<=tag/2;(++count,--countback))  { 
  				if (letter[count]!=letter[countback]) { 
   					flag=FALSE; 
   				break; 
  			} 
 		}

 		for (count=0;count<=tag;++count) 
 		 putchar(letter[count]); 
  			if (flag)
				 printf(" IS A PALINDROME"); 
  			else 
				printf(" IS NOT A PALINDROME"); 
 		} 
	return 0;
} 
