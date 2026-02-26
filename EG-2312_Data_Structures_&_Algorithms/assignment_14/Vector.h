//--------------------------------------------------------------
// Dr. Art Hanna
// Generic VECTOR abstract datatype
// Vector.h
//--------------------------------------------------------------
#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

//==============================================================
// Data model definitions
//==============================================================
#define NOOBJECT NULL

typedef struct VECTOR
{
   int LB;
   int UB;
   int size;
   void **elements;
   void (*DestructElement)(const void *element);
} VECTOR;

//==============================================================
// Public member function prototypes
//==============================================================
void ConstructVECTOR(VECTOR *vector,const int LB,const int UB,
                     void (*DestructElement)(const void *element));
void DestructVECTOR(VECTOR *vector);
void SetVECTOR(VECTOR *vector,const int index,const void *element);
void *GetVECTOR(const VECTOR *vector,const int index);
int GetLBVECTOR(const VECTOR *vector);
int GetUBVECTOR(const VECTOR *vector);
int GetSizeVECTOR(const VECTOR *vector);

//==============================================================
// Private utility member function prototypes
//==============================================================
//static int PhysicalIndex(const int logicalIndex,const int LB);

#endif

