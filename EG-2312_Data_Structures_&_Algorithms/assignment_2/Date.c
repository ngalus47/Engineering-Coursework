//-------------------------------------------------
// Dr. Art Hanna
// Date.c
//-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void InputDATE(DATE *date,FILE *IN)
//--------------------------------------------------------------
{
   fscanf(IN,"%d-%d-%d%c",&date->MM,&date->DD,&date->YYYY,&date->epoch);
}

//--------------------------------------------------------------
void OutputDATE(const DATE *date,FILE *OUT)
//--------------------------------------------------------------
{
// Use the format MM-DD-YYYYEE where EE = "AD" or "BC"
   fprintf(OUT,"%2d-%2d-%4d%2s",date->MM,date->DD,date->YYYY,
      (date->epoch == 'B') ? "BC" : "AD");
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

