//----------------------------------------------------
// Dr. Art Hanna
// Understanding strtok()
// Understandingstrtok().c
//----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <ctype.h>

#include "Date.h"

//----------------------------------------------------
int main()
//----------------------------------------------------
{
   int InputDATE2(DATE *date,FILE *IN);
   void OutputDATE2(const DATE *date,const char separator,FILE *OUT);

   DATE date;

//   ConstructDATE2(&date);
   printf("date? ");
   while ( InputDATE2(&date,stdin) != EOF )
   {
      OutputDATE2(&date,'/',stdout);
      printf("\ndate? ");
   }
//   DestructDATE(&date);
   return( 0 );
}

//--------------------------------------------------------------
int InputDATE2(DATE *date,FILE *IN)
//--------------------------------------------------------------
{
void ShowCharacters(const char line[],const int len,const bool displayRecall);

   const char DELIMITERS[] = " -/.\t\n";

   char line[80+2];
   
   if ( fgets(line,80,IN) == NULL )
      return( EOF );
   else
   {
int len = strlen(line)+1;

ShowCharacters(line,len,true);
      char *pMM = strtok(line,DELIMITERS);
ShowCharacters(line,len,false);
      char *pDD = strtok(NULL,DELIMITERS);
ShowCharacters(line,len,false);
      char *pYYYY = strtok(NULL,DELIMITERS);
ShowCharacters(line,len,false);
      char *pepoch = strtok(NULL,DELIMITERS);
ShowCharacters(line,len,false);
      char epoch;

      if ( pMM   != NULL ) date->MM = atoi(pMM);
      if ( pDD   != NULL ) date->DD = atoi(pDD);
      if ( pYYYY != NULL )
      {
         date->YYYY = atoi(pYYYY);
         if ( pepoch != NULL )
            epoch = pepoch[0];
         else
            epoch = pYYYY[strlen(pYYYY)-1];
         if      ( toupper(epoch) == 'A' )
            date->epoch = 'A';
         else if ( toupper(epoch) == 'B' )
            date->epoch = 'B';
         else
            ; // DO NOTHING!
      }
      return(   1 );
   }
}

//--------------------------------------------------------------
void OutputDATE2(const DATE *date,const char separator,FILE *OUT)
//--------------------------------------------------------------
{
// Use the format MMSDDSYYYYEE where S = separator, EE = 'AD' or 'BC'
//    with MM and DD expressed as 1-or-2 digits (as necessary) and
//    with YYYY expressed as 1-to-4 digits (as necessary) 
   fprintf(OUT,"%d%c%d%c%d%s",date->MM,separator,
      date->DD,separator,date->YYYY,
      (date->epoch == 'B') ? "BC" : "AD");
}

//--------------------------------------------------------------
void ShowCharacters(const char line[],const int len,const bool displayRecall)
//--------------------------------------------------------------
{
   if ( displayRecall ) printf("Recall, 00 = NUL, 09 = HT(\\t), 0A = \\n\n");
   for (int i = 0; i <= len-1; i++)
      if ( isprint(line[i]) )
         printf("%2c",line[i]);
      else
         printf("  ",line[i]);
   printf(" printable characters\n");

   for (int i = 0; i <= len-1; i++)
      if ( isprint(line[i]) )
         printf("  ",line[i]);
      else
         printf("%02X",line[i]);
   printf(" control characters\n");
}

