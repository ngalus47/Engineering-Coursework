//-------------------------------------------------
// Dr. Art Hanna
// Date.c
//-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>  // atoi
#include <string.h>  // strtok, strlen
#include <ctype.h>   // toupper
#include "Date.h"

//--------------------------------------------------------------
void ConstructDATE(DATE *date)
//--------------------------------------------------------------
{
   (*date).MM = 2; date->DD = 3;
   date->YYYY = 1954; date->epoch = 'A';
// Instrumentation
   printf("Construction of DATE = "); OutputDATE(date,stdout); printf("\n");
}

//--------------------------------------------------------------
void DestructDATE(DATE *date)
//--------------------------------------------------------------
{
// Instrumentation
   printf("Destruction of DATE = "); OutputDATE(date,stdout); printf("\n");
}

//--------------------------------------------------------------
int InputDATE2(DATE *date,FILE *IN)
//--------------------------------------------------------------
{
   const char DELIMITERS[] = " -/.\t\n";

   char line[80+2];
   
   if ( fgets(line,80,IN) == NULL )
      return( EOF );
   else
   {
      char *pMM = strtok(line,DELIMITERS);
      char *pDD = strtok(NULL,DELIMITERS);
      char *pYYYY = strtok(NULL,DELIMITERS);
      char *pepoch = strtok(NULL,DELIMITERS);
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
void OutputDATE(const DATE *date,FILE *OUT)
//--------------------------------------------------------------
{
// Use the format MM-DD-YYYYEE where EE = "AD" or "BC"
   fprintf(OUT,"%2d-%2d-%4d%2s",date->MM,date->DD,date->YYYY,
      (date->epoch == 'B') ? "BC" : "AD");
}

void OutputDATE2(const DATE *date, const char separator, FILE *OUT)
{
	fprintf(OUT, "%d%c%d%c%d%s", date->MM, separator, date->DD, separator, date->YYYY, (date->epoch == 'B') ? "BC" : "AD");
}

//--------------------------------------------------------------
void SetMMDATE(DATE *date,const int MM)
//--------------------------------------------------------------
{
   date->MM = MM;
}

//--------------------------------------------------------------
void SetDDDATE(DATE *date,const int DD)
//--------------------------------------------------------------
{
   date->DD = DD;
}

//--------------------------------------------------------------
void SetYYYYDATE(DATE *date,const int YYYY)
//--------------------------------------------------------------
{
   date->YYYY = YYYY;
}

//--------------------------------------------------------------
void SetEpochDATE(DATE *date,const char epoch)
//--------------------------------------------------------------
{
   date->epoch = epoch;
}

//--------------------------------------------------------------
int GetMMDATE(const DATE *date)
//--------------------------------------------------------------
{
   return( date->MM );
}

//--------------------------------------------------------------
int GetDDDATE(const DATE *date)
//--------------------------------------------------------------
{
   return( date->DD );
}

//--------------------------------------------------------------
int GetYYYYDATE(const DATE *date)
//--------------------------------------------------------------
{
   return( date->YYYY );
}

//--------------------------------------------------------------
char GetEpochDATE(const DATE *date)
//--------------------------------------------------------------
{
   return( date->epoch );
}

//--------------------------------------------------------------
void ConvertToStringDATE(const DATE *date,char string[])
//--------------------------------------------------------------
{
   sprintf(string,"%2d-%2d-%4d%2s",date->MM,date->DD,date->YYYY,
      (date->epoch == 'B') ? "BC" : "AD");
}

int IsLeapYearDATE(const DATE *date)
{
	return (date->epoch != 'B' &&
              date->YYYY % 4 == 0 &&
              (date->YYYY % 100 != 0 || date->YYYY % 400 == 0)); 
}
