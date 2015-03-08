#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int num = 0;
	int i;
	system("clear");
	printf("Pakage is Downloading.\n");
	for(num = 0; num<=100; num++){
	printf("Downloading.......%d%%\n", num);
	system("sleep 1");
	system("clear");
	}
	printf("Downloading Complete.....%d%%.\n", num - 1);
	printf("Pakage Downloaded, Ready for use.\n");
	return 0;
}
