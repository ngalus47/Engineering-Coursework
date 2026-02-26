//--------------------------------------------------------------
// Dr. Art Hanna
// QUEUE abstract datatype
// Queue.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Queue.h"
#include "ADTExceptions.h"

//--------------------------------------------------------------
void ConstructQUEUE(QUEUE *queue,
                    void (*DestructElement)(const void *element))
//--------------------------------------------------------------
{
   ConstructDLL(&queue->dll,DestructElement);
}

//--------------------------------------------------------------
void DestructQUEUE(QUEUE *queue)
//--------------------------------------------------------------
{
   ClearDLL(&queue->dll);
}

//--------------------------------------------------------------
void PushTailQUEUE(QUEUE *queue,const void *element)
//--------------------------------------------------------------
{
   Student provides missing code
}

//--------------------------------------------------------------
void PopHeadQUEUE(QUEUE *queue)
//--------------------------------------------------------------
{
   Student provides missing code
}

//--------------------------------------------------------------
void *HeadQUEUE(const QUEUE *queue)
//--------------------------------------------------------------
{
   Student provides missing code
}

//--------------------------------------------------------------
bool IsEmptyQUEUE(const QUEUE *queue)
//--------------------------------------------------------------
{
   return( IsEmptyDLL(&queue->dll) );
}

//--------------------------------------------------------------
int GetSizeQUEUE(const QUEUE *queue)
//--------------------------------------------------------------
{
   Student provides missing code
}

