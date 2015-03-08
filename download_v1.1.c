/* file: download.c */
/* version: 1.1 */
/* written by: Alangi Derick */
/* description: this program is still under development */
/* Licence: open source */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	char ans[] = "yes";	//reference answer
	int i;
	char ans1[4];	//user's answer storage medium
	printf("Do you want to download this package? (yes/no): ");
	scanf("%s", ans1);	//gets the user's ans

	if(strcmp(ans, ans1) == 0){	//checks to see if the condition holds.
		for(i = 0; i<101; i++){
		printf("Downloading....%d%%.\n", i); //this statement is coordinated by the loop showing the percentage downloaded.
		system("sleep 2");
		system("clear");
		}
	printf("Download complete.....%d%%\n", i - 1);  //after downloading, the program shows printfs the complete message.
	printf("Package now Available and Ready for Use.\n");
	}
	else
		{
		printf("Download Aborted, Exiting......\n"); /*The else aborts the download */
		system("sleep 2");				/* and exits the programs. */
		}
	return 0;
}
