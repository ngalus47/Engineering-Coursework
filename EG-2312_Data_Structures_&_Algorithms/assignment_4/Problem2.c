//-------------------------------------------------
// Dr. Art Hanna
// DATE ADT: Problem #2
// Problem2.c
//-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>  // atoi
#include <string.h>  // strtok, strlen
#include <ctype.h>   // toupper

#include "Date.h"

//-------------------------------------------------
int main()
//-------------------------------------------------
{
   DATE date;
   
   ConstructDATE(&date);
   printf("date? ");
   while ( InputDATE2(&date,stdin) != EOF )
   {
      if ( IsLeapYearDATE(&date) )
         OutputDATE2(&date,'/',stdout), printf(" is  leap year\n");
      else
         OutputDATE2(&date,'/',stdout), printf(" not leap year\n");
      printf("\ndate? ");
   }
   DestructDATE(&date);
   
   return( 0 );
}

