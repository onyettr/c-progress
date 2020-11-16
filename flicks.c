#include <stdio.h>
#include <stdlib.h>

int main ( void )
{
   static char Flicks[]="|/-\\|/-\\" ;
   int Flick=0;
   int goes = 30;

   while (goes--)
   {
     int i;

     for(i=0; i < 100000000; i++);

     printf("%c\b", Flicks[Flick]);
     if ( ++Flick == 8 ) {
       
       for(i=0; i < 100000; i++);       
       Flick -= 8;
     }
     fflush(stdout);
   }
}
