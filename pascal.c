#include<stdio.h>
 
long factorial(int);
 
main()
{
   int i, n, j;
 
   printf("Enter the number of rows you wish to see in pascal triangle: ");
   scanf("%d",&n);

   printf("The pascal's traingle is: \n");
 
   for ( i = 0 ; i < n ; i++ )
   {
      for ( j = 0 ; j <= ( n - i - 2 ) ; j++ )
         printf(" ");
 
      for( j = 0 ; j <= i ; j++ )
         printf("%ld ", factorial(i)/(factorial(j)*factorial(i-j)));
 
      printf("\n");
   }
 
   return 0;
}
 
long factorial(int n)
{
   int j;
   long result = 1;
 
   for( j = 1 ; j <= n ; j++ )
         result = result*j;
 
   return ( result );
}


