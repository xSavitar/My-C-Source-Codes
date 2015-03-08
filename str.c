#include <string.h>
#include <stdio.h>

int main(void)
{
   char text[] = "I learn through IndiaBIX.com";
   char *ptr, c = 'i';

   ptr = strrchr(text, c);
   if (ptr)
      printf("The position of '%c' is: %d\n", c, ptr-text);
   else
      printf("The character was not found\n");
   return 0;
}

