//--------------------------------------------------------------
// Dr. Art Hanna
// VECTOR ADT Problem #2 
// Problem2.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Vector2.h"

//--------------------------------------------------------------
int main()
//--------------------------------------------------------------
{
   void DestructDouble(const void *element);
   void DisplayVector(const VECTOR *vector);
   void WriteVectorToDiskFile(const VECTOR *vector);
   void ReadVectorFromDiskFile(VECTOR *vector);

   int LB,UB;

//printf("sizeof(int)    = %d bytes\n",sizeof(int));
//printf("sizeof(void *) = %d bytes\n",sizeof(void *));
//printf("sizeof(double) = %d bytes\n",sizeof(double));

   printf("LB? ");
   while ( scanf("%d",&LB) != EOF )
   {
      VECTOR vector;
      int index;

      printf("UB? "); scanf("%d",&UB);
      ConstructVECTOR(&vector,LB,UB,DestructDouble);
      for (index = GetLBVECTOR(&vector)+1; index <= GetUBVECTOR(&vector)-1; index++)
      {
         double *element = (double *) malloc(sizeof(double));

         *element = (double) index;
         SetVECTOR(&vector,index,element);
      }
      DisplayVector(&vector);

      WriteVectorToDiskFile(&vector);
      ReadVectorFromDiskFile(&vector);
      DisplayVector(&vector);

      DestructVECTOR(&vector);
      printf("\nLB? ");
   }

   system("PAUSE");
   return( 0 );
}

//--------------------------------------------------------------
void DestructDouble(const void *element)
//--------------------------------------------------------------
{
   free((double *) element);
}

//--------------------------------------------------------------
void DisplayVector(const VECTOR *vector)
//--------------------------------------------------------------
{
   int index;

   printf("LB = %3d, UB = %3d, size = %d\n",
      GetLBVECTOR(vector),GetUBVECTOR(vector),GetSizeVECTOR(vector));
   for (index = GetLBVECTOR(vector); index <= GetUBVECTOR(vector); index++)
      if ( GetVECTOR(vector,index) == NOOBJECT )
         printf("vector[%3d] = NOOBJECT\n",index);
      else
         printf("vector[%3d] = %lf\n",index,*((double *) GetVECTOR(vector,index)));
}

//--------------------------------------------------------------
void WriteVectorToDiskFile(const VECTOR *vector)
//--------------------------------------------------------------
{
   void WriteDouble(FILE *OUT,const void *element);

   char fileName[80+1];
   FILE *OUT;

   do
   {
      printf("OUT fileName? ");
      scanf("%s",fileName);
      if ( (OUT = fopen(fileName,"wb")) == NULL ) printf("Unable to open file!\n");
   } while ( OUT == NULL );
   StoreVECTOR(OUT,vector,WriteDouble);
   fclose(OUT);
}

//--------------------------------------------------------------
void WriteDouble(FILE *OUT,const void *element)
//--------------------------------------------------------------
{
   fwrite(element,sizeof(double),1,OUT);
}

//--------------------------------------------------------------
void ReadVectorFromDiskFile(VECTOR *vector)
//--------------------------------------------------------------
{
   void ReadDouble(FILE *IN,void **element);
   void DestructDouble(const void *element);

   char fileName[80+1];
   FILE *IN;

   do
   {
      printf(" IN fileName? ");
      scanf("%s",fileName);
      if ( (IN = fopen(fileName,"rb")) == NULL ) printf("Unable to open file!\n");
   } while ( IN == NULL );
   LoadVECTOR(IN,vector,ReadDouble,DestructDouble);
   fclose( IN);
}

//--------------------------------------------------------------
void ReadDouble(FILE *IN,void **element)
//--------------------------------------------------------------
{
   *element = (void *) malloc(sizeof(double));
   
   if ( *element == NULL )
   {
      printf("\a\nmalloc() error\n\n");
      system("PAUSE");
      exit( 1 );
   }
   fread(*element,sizeof(double),1,IN);
}

