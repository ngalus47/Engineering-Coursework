//--------------------------------------------------------------
// Dr. Art Hanna
// PQUEUE abstract datatype
// PQueue.h
//--------------------------------------------------------------
#ifndef PQUEUE_H
#define PQUEUE_H

#include "DLL.h"

//==============================================================
// Data model definitions
//==============================================================
typedef struct PQUEUE
{
   DLL dll;
   bool (*IsHigherPriority)(const void *LHS,const void *element,const void *RHS);
} PQUEUE;

//==============================================================
// Public member function prototypes
//==============================================================
void ConstructPQUEUE(PQUEUE *pqueue,
                     bool (*IsHigherPriority)(const void *LHS,const void *element,const void *RHS),
                     void (*DestructElement)(const void *element));
void DestructPQUEUE(PQUEUE *pqueue);
void InsertPQUEUE(PQUEUE *pqueue,const void *element);
void PopHeadPQUEUE(PQUEUE *pqueue);
void *HeadPQUEUE(const PQUEUE *pqueue);
bool IsEmptyPQUEUE(const PQUEUE *pqueue);
int GetSizePQUEUE(const PQUEUE *pqueue);
void TraversePQUEUE(const PQUEUE *pqueue,
                    void (*ProcessElement)(void *element));

//==============================================================
// Private utility member function prototypes
//==============================================================
// (none)

#endif

