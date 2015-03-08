/* file: array_implementation_stack.c */
/* version: unknown */
/* description: this is the implementation of stack using arrays. */
/* by: Alangi Derick */

#include<stdio.h>
#include<stdlib.h>
#define M 100 /*maximum size of stack*/

int *s;	/*stack will contain integers*/
int N;	/*top of stack*/
void stackInit(int max)
{
	s = malloc(max * sizeof(int));
	N = 0;
}

int stackEmpty()
{
	return 0;
}

int stackFull()
{
	return 0;
}

void stackPush(int item)
{
	s[N++] = item;
}

int stackPop(void)
{
	return s[--N];
}

void stackDisplay(void)
{
	int i;
	for(i = N-1; i>=0; i--)
		printf("%d ", s[i]);
	printf("\n");
}

int main(void)
{
	int i;
	stackInit(M);
	/*add 10 random numbers to stack*/
	for(i = 0; i < 10; i++)
		if(!stackFull())
			stackPush(rand() % 100);
	printf("Initial Contents: ");
	stackDisplay();
	/*pop 5 items off the stack*/
	for(i = 0; i<5; i++)
		if(!stackEmpty())
			stackPop();
	printf("Contents after poping off 5 items: ");
	stackDisplay();

return 0;
}
