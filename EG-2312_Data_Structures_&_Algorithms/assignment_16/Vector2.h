//--------------------------------------------------------------
// Nick Galus
// Generic VECTOR abstract datatype
// Vector2.h
//--------------------------------------------------------------
#ifndef VECTOR2_H
#define VECTOR2_H

#include <stdio.h>
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
// Serialization / Deserialization
//==============================================================
void StoreVECTOR(FILE *OUT,const VECTOR *vector,
                void (*WriteElement)(FILE *OUT,const void *element));
void LoadVECTOR(FILE *IN,VECTOR *vector,
                void (*ReadElement)(FILE *IN,void **element),
                void (*DestructElement)(const void *element));

#endif
