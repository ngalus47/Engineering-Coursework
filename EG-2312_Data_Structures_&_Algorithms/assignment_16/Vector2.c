//--------------------------------------------------------------
// Nick Galus
// Generic VECTOR abstract datatype
// Vector2.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Vector2.h"
#include "ADTExceptions.h"

#define PHYSICALINDEX(logicalIndex,LB) ((logicalIndex)-(LB))

//--------------------------------------------------------------
static int PhysicalIndex(const int logicalIndex,const int LB)
//--------------------------------------------------------------
{
   return( logicalIndex-LB );
}

//--------------------------------------------------------------
void ConstructVECTOR(VECTOR *vector,const int LB,const int UB,
                     void (*DestructElement)(const void *element))
//--------------------------------------------------------------
{
   int i;

   if ( !(LB <= UB) ) RaiseADTException(VECTOR_BOUNDS_ERROR);

   vector->LB = LB;
   vector->UB = UB;
   vector->size = UB-LB+1;
   vector->elements = (void **) malloc(vector->size*sizeof(void *));

   if ( vector->elements == NULL ) RaiseADTException(MALLOC_ERROR);

   for (i = LB; i <= UB; i++)
      vector->elements[PHYSICALINDEX(i,LB)] = NOOBJECT;

   vector->DestructElement = DestructElement;
}

//--------------------------------------------------------------
void DestructVECTOR(VECTOR *vector)
//--------------------------------------------------------------
{
   int i;

   if ( vector->DestructElement != NULL )
   {
      for (i = vector->LB; i <= vector->UB; i++)
         if ( vector->elements[PhysicalIndex(i,vector->LB)] != NOOBJECT )
            vector->DestructElement(
               vector->elements[PhysicalIndex(i,vector->LB)]);
   }
   free(vector->elements);
}

//--------------------------------------------------------------
void SetVECTOR(VECTOR *vector,const int index,const void *element)
//--------------------------------------------------------------
{
   int i;

   if ( index < vector->LB )
   {
      int newLB = index;
      int newSize = vector->UB-newLB+1;
      void **newElements = (void **) malloc(sizeof(void *)*newSize);

      if ( newElements == NULL ) RaiseADTException(MALLOC_ERROR);

      for (i = newLB; i <= vector->UB; i++)
         if ( i < vector->LB )
            newElements[PhysicalIndex(i,newLB)] = NOOBJECT;
         else
            newElements[PhysicalIndex(i,newLB)] =
               vector->elements[PhysicalIndex(i,vector->LB)];

      vector->LB = newLB;
      free(vector->elements);
      vector->elements = newElements;
      vector->size = newSize;
   }
   else if ( index > vector->UB )
   {
      int newUB = index;
      int newSize = newUB-vector->LB+1;
      void **newElements = (void **) malloc(sizeof(void *)*newSize);

      if ( newElements == NULL ) RaiseADTException(MALLOC_ERROR);

      for (i = vector->LB; i <= newUB; i++)
         if ( i > vector->UB )
            newElements[PhysicalIndex(i,vector->LB)] = NOOBJECT;
         else
            newElements[PhysicalIndex(i,vector->LB)] =
               vector->elements[PhysicalIndex(i,vector->LB)];

      vector->UB = newUB;
      free(vector->elements);
      vector->elements = newElements;
      vector->size = newSize;
   }

   if ( (vector->elements[PhysicalIndex(index,vector->LB)] != NOOBJECT) &&
        (vector->DestructElement != NULL) )
      vector->DestructElement(
         vector->elements[PhysicalIndex(index,vector->LB)]);

   vector->elements[PhysicalIndex(index,vector->LB)] = (void *) element;
}

//--------------------------------------------------------------
void *GetVECTOR(const VECTOR *vector,const int index)
//--------------------------------------------------------------
{
   if ( !((vector->LB <= index) && (index <= vector->UB)) )
      RaiseADTException(VECTOR_INDEX_ERROR);

   return( vector->elements[PhysicalIndex(index,vector->LB)] );
}

//--------------------------------------------------------------
int GetLBVECTOR(const VECTOR *vector)
//--------------------------------------------------------------
{
   return( vector->LB );
}

//--------------------------------------------------------------
int GetUBVECTOR(const VECTOR *vector)
//--------------------------------------------------------------
{
   return( vector->UB );
}

//--------------------------------------------------------------
int GetSizeVECTOR(const VECTOR *vector)
//--------------------------------------------------------------
{
   return( vector->size );
}

//--------------------------------------------------------------
void StoreVECTOR(FILE *OUT,const VECTOR *vector,
                void (*WriteElement)(FILE *OUT,const void *element))
//--------------------------------------------------------------
{
   int i;

   fwrite(&(vector->LB),sizeof(int),1,OUT);
   fwrite(&(vector->UB),sizeof(int),1,OUT);
   fwrite(&(vector->size),sizeof(int),1,OUT);

   fwrite(vector->elements,vector->size*sizeof(void *),1,OUT);

   for (i = vector->LB; (i <= vector->UB) && !ferror(OUT); i++)
      if ( vector->elements[PhysicalIndex(i,vector->LB)] != NOOBJECT )
         WriteElement(OUT,
            vector->elements[PhysicalIndex(i,vector->LB)]);

   if ( ferror(OUT) ) RaiseADTException(IO_ERROR);
}

//--------------------------------------------------------------
void LoadVECTOR(FILE *IN,VECTOR *vector,
                void (*ReadElement)(FILE *IN,void **element),
                void (*DestructElement)(const void *element))
//--------------------------------------------------------------
{
   int i,LB,UB,size;

   DestructVECTOR(vector);

   fread(&LB,sizeof(int),1,IN);
   fread(&UB,sizeof(int),1,IN);
   fread(&size,sizeof(int),1,IN);

   ConstructVECTOR(vector,LB,UB,DestructElement);

   fread(vector->elements,vector->size*sizeof(void *),1,IN);

   for (i = vector->LB; (i <= vector->UB) && !ferror(IN); i++)
      if ( vector->elements[PhysicalIndex(i,vector->LB)] != NOOBJECT )
         ReadElement(IN,
            &vector->elements[PhysicalIndex(i,vector->LB)]);

   if ( ferror(IN) ) RaiseADTException(IO_ERROR);
}
