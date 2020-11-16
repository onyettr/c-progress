/**
 * MODULE: C Programming Examples
 *
 * Display rotating flicks
 *
 * @file   flicks.c
 * @author ronyett
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static char Flicks[]="|/-\\|/-\\";

static void flicker(int timeDelay)
{
   int Flick=0;
   int i;

   for(i=0; i < 100000000; i++);   
   printf("%c\b", Flicks[Flick]);
   (void)fflush(stdout);   
   if ( ++Flick == 8 ) {
     for(i=0; i < timeDelay; i++);
     Flick -= 8;
   }
   
   (void)fflush(stdout);
}

int main ( void )
{
   int goes = 10;
   bool done = false;
   
   flicker(100000);

   while (!done)
   {
     int i;

     for(i=0; i < 1000000000; i++);
     
     flicker(1000);

     goes--;
     if (goes <= 0)
     {
       done = true;
     }
   }

   return 0;
}
