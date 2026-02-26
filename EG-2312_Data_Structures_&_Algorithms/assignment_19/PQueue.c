//--------------------------------------------------------------
// Nick Galus
// PQUEUE abstract datatype
// PQueue.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "PQueue.h"
#include "ADTExceptions.h"

//--------------------------------------------------------------
void ConstructPQUEUE(PQUEUE *pqueue,
                     bool (*IsHigherPriority)(const void *LHS,const void *element,const void *RHS),
                     void (*DestructElement)(const void *element))
//--------------------------------------------------------------
{
   if ( IsHigherPriority == NULL ) RaiseADTException(CALLBACK_FUNCTION_ERROR);

   ConstructDLL(&pqueue->dll,DestructElement);
   pqueue->IsHigherPriority = IsHigherPriority;
}

//--------------------------------------------------------------
void DestructPQUEUE(PQUEUE *pqueue)
//--------------------------------------------------------------
{
   ClearDLL(&pqueue->dll);
}

//--------------------------------------------------------------
void InsertPQUEUE(PQUEUE *pqueue,const void *element)
//--------------------------------------------------------------
{
   InsertDLL2(&pqueue->dll,element,pqueue->IsHigherPriority);
}

//--------------------------------------------------------------
void PopHeadPQUEUE(PQUEUE *pqueue)
//--------------------------------------------------------------
{
   DeleteDLL(&pqueue->dll,0);
}

//--------------------------------------------------------------
void *HeadPQUEUE(const PQUEUE *pqueue)
//--------------------------------------------------------------
{
   return( PeekDLL(&pqueue->dll,0) );
}

//--------------------------------------------------------------
bool IsEmptyPQUEUE(const PQUEUE *pqueue)
//--------------------------------------------------------------
{
   return( IsEmptyDLL(&pqueue->dll) );
}

//--------------------------------------------------------------
int GetSizePQUEUE(const PQUEUE *pqueue)
//--------------------------------------------------------------
{
   return( GetSizeDLL(&pqueue->dll) );
}

//--------------------------------------------------------------
void TraversePQUEUE(const PQUEUE *pqueue,
                    void (*ProcessElement)(void *element))
//--------------------------------------------------------------
{
   TraverseFromHeadToTailDLL(&pqueue->dll,ProcessElement);
}
