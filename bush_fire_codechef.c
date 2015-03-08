/* Brush Fire Program in Codechef.com */
/* Program - Help! A brush fire has started near your house and you are the only one who can help extinguish it. The only tool you have at your disposal is a single fireproof barrier that can protect one bush at a time, provided the bush has not yet caught fire already. For simplicity, we will assume the flames spread according to the following discrete time model.

Initially, a single bush, say s, is on fire. You choose a bush, say k, to save. The flames then leap from s to every bush near s with the exception of bush k if it was near s. Say these new burning bushes form a set B. Bush s is then reduced to ashes and will never burn again. Now that the bushes in B are on fire, you may move the protective barrier from bush k to some other bush k'. The flames leap from bushes in B to every bush that has not yet burned (i.e. not s or in B) and is close enough to some bush in B except, perhaps, bush k'. Say this new set of burning bushes is B'.
The bushes in set B are reduced to ashes and will never burn again. Now, you may move the protective barrier from k' to another bush to protect it from the flames that will spread from bushes in B' and so on. This process repeats until there are no more bushes on fire.

The bushes are arranged in a peculiar manner. Before the fire started, each bush was close enough to spread a fire to at most three other bushes. Moreover, the bush that was initially on fire is actually close enough to only at most two other bushes. It is understood that for any two bushes A and B, if bush A is close enough to bush B then bush B is also close enough to bush A. Finally, the graph underlying the "close enough" relation has no cycles.

For whatever reason, some of the bushes hold some sentimental value to you. For this reason, you want to save all of these bushes.
*/

#if 1
#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long unint64;
typedef short int sint;

char g_sInputBuffer[1024];
char *g_sInputBufferPtr = g_sInputBuffer;

unsigned int g_iInputBufferLength = 0;

inline int IsDigit(char c)
{
	return ((c >= '0') && (c <= '9'));
}

inline char InputReadChar(void)
{
	if(g_iInputBufferLength == 0)
	{
		g_sInputBufferPtr = g_sInputBuffer;
		g_iInputBufferLength = fread(g_sInputBuffer, 1, sizeof(g_sInputBuffer), stdin);
	if(g_iInputBufferLength == 0)
		return 0;
	}

	g_iInputBufferLength--;
	return *g_sInputBufferPtr++;
}

int InputReadTextInt(void)
{
	char c;
	while(!IsDigit(c = InputReadChar())); //skip blanks

	int iResult = 0;
	do
	{
		iResult*= 10;
		iResult+= (c - '0');
		c = InputReadChar();
	}while(IsDigit(c));
	return iResult;
}

inline int scanInt()
{
	register int retVar = 0, d;
	while((d = getchar()) < '0');
	do
	{
		retVar = (retVar<<3) + (retVar<<1) + d - '0';
	}
	while((d = getchar()) >= '0');
	return retVar;
}

int arr[11000][4];
char save[11000];
int n, s, t;

char result;

void DFS(int parent, int vertex)
{
	if(1 == result)
		return;
	if(1 == save[vertex])
		return;
	if(arr[vertex][0] == 1 || arr[vertex][0] == 0)
		{
			result = 1;
			return;
		}
	if(vertex != s && (arr[vertex][0] == 2))
	{
		result = 1;
		return;
	}

	/*if (vertex != s && arr[vertex][0] == 2 {
		result = 1;
		return;
	}*/

	int i;
	for(i = 1; i<= arr[vertex][0]; i++)
	{
		if(arr[vertex][i] != parent)
			DFS(vertex, arr[vertex][i]);
		}
	}

int main(void)
{
	#ifndef ONLINE_JUDGE
	
	freopen("in.txt", "r", stdin);
	
	#endif

	char T;
	T = InputReadTextInt();
	while(T--)
	{
		n = InputReadTextInt();
		s = InputReadTextInt();
		t = InputReadTextInt();
	int i, j;
	for(i = 1; i<=n; i++)
	{
		arr[i][0] = InputReadTextInt();
			for(j=1; j<=arr[i][0]; j++) {
				arr[i][j] = InputReadTextInt();
		}
	}
	memset(save, 0, (n+2) * sizeof(char));
	for(i=0; i<t; i++) {
		int t = InputReadTextInt();
		save[t] = 1;
	}

	result = 0;
	DFS(s, s);
	if(result == 0)
		printf("no\n");
	else
		printf("Yes\n");
	}
	return 0;
}
#endif
