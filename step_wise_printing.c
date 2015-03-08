#include<stdio.h>
#include<string.h>

int main(void)
{
	FILE *read, *write;
	
	char buf[10];
	int i = 0;

	if((read = fopen("file.txt", "r")) == NULL)
		printf("Error while opening file.\n");
	else
		write = fopen("test.txt", "w");

	while((fscanf(read, "%s", buf) != EOF && !feof(read))){
		i+=strlen(buf);
		fprintf(write, "%*s\n", i, buf);
	}
	
	fclose(read);
	fclose(write);

return 0;
}
