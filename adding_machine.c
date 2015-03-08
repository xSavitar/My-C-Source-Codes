#include<stdio.h>
int add_machine(size_t, size_t);
int (*ptr)(size_t, size_t);

int main()
{
	int num1, num2, sum;

	printf("Enter num1: ");	
	scanf("%d", &num1);
	

	printf("Enter num2: ");	
	scanf("%d", &num2);
	
	ptr = add_machine;
	sum = ptr(num1, num2);

	printf("The sum is %d.\n", sum);
	
return 0;
}

int add_machine(size_t x, size_t y)
{
	return (x + y);
}
