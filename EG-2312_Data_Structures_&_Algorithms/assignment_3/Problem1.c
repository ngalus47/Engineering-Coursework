//-------------------------------------------------
// Dr. Art Hanna
// DATE ADT: Problem #1
// Problem1.c
//-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Date.h"

//-------------------------------------------------
int main()
//-------------------------------------------------
{
   char string[80+1];

// An example of an egregious [outstandingly bad; shocking] violation of the 
//    principle of information hiding!
   DATE date1 = { 1,30,1979,'A' };

   DATE date2;
   ConstructDATE(&date2);

   fprintf(stdout,"\ndate1 = "); OutputDATE(&date1,stdout); fprintf(stdout,"\n");

   SetMMDATE(&date1,1); SetDDDATE(&date1,5);
   SetYYYYDATE(&date1,1953); SetEpochDATE(&date1,'A');
   fprintf(stdout,"\ndate1 = "); OutputDATE(&date1,stdout); fprintf(stdout,"\n");

   fprintf(stdout,"\ndate2? "); InputDATE(&date2,stdin);

// Another example of the violation of the principle of information hiding!
   printf("\ndate2 = %2d/%2d/%4d%s\n",date2.MM,
      GetDDDATE(&date2),
      GetYYYYDATE(&date2),
      (GetEpochDATE(&date2) == 'B') ? "BC" : "AD");

   ConvertToStringDATE(&date2,string);
   printf("\ndate2 = %s\n\n",string);

   DestructDATE(&date2);
   DestructDATE(&date1);
   
  return( 0 );
}

