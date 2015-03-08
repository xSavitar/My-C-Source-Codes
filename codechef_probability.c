/* This is the code chef code for probalily*/
/* Program - Chef, Artem and Eugene are the best of friends and teammates. Recently, they won a lot of money at the Are You Feeling Lucky Cup. Having put their fortune to test and emerging victorious, they are now busy enjoying their wealth. Eugene wanted to drink it all away. Chef and Artem had better plans.

Chef and Artem decided to go to Las Vegas and put more of their fortune to test! Eugene stayed at home and continues drinking.

In Vegas, Chef and Artem found lots of interesting games. The most interesting one to them was the game of Lucky Tickets.

Lucky Tickets is played using three kinds of tickets

    * Type-1 called the winning ticket.
    * Type-2 called the losing ticket.
    * Type-3 called the try again ticket.

Lucky Tickets is played as follows

You know there are T1 tickets of Type-1, T2 tickets of Type 2 and T3 tickets of Type-3 before the game begins.

All the tickets are placed in a sealed box. You are allowed to take out only one ticket from the box. Of course, you cannot see inside the box while choosing the ticket.

    * If you choose a Type-1 ticket, you are declared winner of Lucky Tickets and double your money.
    * If you choose a Type-2 ticket, you are declared loser of Lucky Tickets and lose all your money.
    * If you choose a Type-3 ticket, you have to try your fortune again and pick another ticket from the box and the selection process starts all over again.

Chef was able to convince the organizers of Lucky Tickets to let him go first and discard T4 tickets. This means that Chef makes T4 turns to choose exactly one ticket every turn, and despite what ticket he choses, he simply discards it. Chef also convinced the organizers to let Artem go right after he is finished.

What is the probability that Artem will win? */


#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int t, t1, t2, t3, t4;

	printf("Enter a number: ");
	scanf("%d", &t);
	
	while(t--)
	{
		printf("Enter the values for the tickets: ");
		scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
		printf("%lf\n", (double) t1/(t2 + t3));
	}
return 0;
}
