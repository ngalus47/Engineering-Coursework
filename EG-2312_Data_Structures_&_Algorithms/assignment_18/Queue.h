//--------------------------------------------------------------
// Dr. Art Hanna
// QUEUE abstract datatype
// Queue.h
//--------------------------------------------------------------
#ifndef QUEUE_H
#define QUEUE_H

#include "DLL.h"

//==============================================================
// Data model definitions
//==============================================================
typedef struct QUEUE
{
   DLL dll;
} QUEUE;

//==============================================================
// Public member function prototypes
//==============================================================
void ConstructQUEUE(QUEUE *queue,
                    void (*DestructElement)(const void *element));
void DestructQUEUE(QUEUE *queue);
void PushTailQUEUE(QUEUE *queue,const void *element);
void PopHeadQUEUE(QUEUE *queue);
void *HeadQUEUE(const QUEUE *queue);
bool IsEmptyQUEUE(const QUEUE *queue);
int GetSizeQUEUE(const QUEUE *queue);

//==============================================================
// Private utility member function prototypes
//==============================================================
// (none)

#endif

