#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#define MEMORY_OVERHEAD 1024

static unsigned char *cleaning_ptr;
static unsigned int memOverhead = 0;

/* 'a' to 'z' - 26 -- 0x61 to 0x7a
 * 'A' to 'Z' - 26 -- 0x41 to 0x5a
 * 0 to 9 - 10 -- 0x30 to 0x39
 * total : 62 characters
 */
static unsigned int
nextChar(unsigned char *current)
{
	unsigned char result = 0;
	/*printf("*current is 0x%x\n", *current);*/
	if (*current == 0x39)
		return 1;

	if (*current == 0x7a)
		result = 0x41;

	if (*current == 0x5a)
		result = 0x30;

	if (*current == 0)
		result = 0x61;
	
	if (result == 0)
		*current = *current + 1;
	else
	{
		*current = result;
	}
	/*printf("herein2 0x%x -- *current is 0x%x\n", result, *current);*/
	return 0;
}

static void
printCpass(unsigned char *str, unsigned int len)
{
	unsigned int i = 0;
	while (i < len)
	{
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
}

static void
passCracker()
{
	unsigned char *cPass;
	int cPassLen = 0;
	int cursor = 0;
	int result = 0;

	cPass = (unsigned char*)calloc(1, sizeof(unsigned char) * MEMORY_OVERHEAD);
	cPass[0] = 0;
	cPassLen = 1;
	cleaning_ptr = cPass;
	memOverhead = MEMORY_OVERHEAD - 1;

	while (1 != 2)
	{
		result = nextChar(&cPass[cursor]);

		if (result)
		{
			cPass[cursor] = 0;
			nextChar(&cPass[cursor]); /* reset the cursor to 'a' */

			cursor++;
			if (cursor >= cPassLen)
			{
				if (memOverhead == 0)
				{
					cPass = (unsigned char*)realloc(cPass, sizeof(unsigned char) * (cPassLen + MEMORY_OVERHEAD));
					cleaning_ptr = cPass;
					memOverhead = MEMORY_OVERHEAD - 1;
				}
				else
				{
					memOverhead--;
				}
				cPassLen++;
				cPass[cursor] = 0;
				continue;
			}
			else
				continue;
		}
		else
		{
			cursor = 0;
			printCpass(cPass, cPassLen);
			continue;
		}
	}
}

static void
clean_up(int sig)
{
	printf("cleaning up the program\n");
	if (cleaning_ptr)
		free(cleaning_ptr);
	exit(0);
}

int 
main()
{
	signal(SIGINT, &clean_up);
	passCracker();
	clean_up(0);
	return 0;
}
