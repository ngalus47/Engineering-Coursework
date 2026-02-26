//----------------------------------------------------
// Dr. Art Hanna
// Stack.h
//----------------------------------------------------
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

//==============================================================
// Data model definitions
//==============================================================
typedef struct STACK
{
   int size;
   int capacity;
   int *elements;
} STACK;

//==============================================================
// Public member function prototypes
//==============================================================
void ConstructSTACK(STACK *stack,const int capacity);
void DestructSTACK(STACK *stack);
void PushSTACK(STACK *stack,const int element);
void PopSTACK(STACK *stack);
int PeekSTACK(const STACK *stack,const int offset);
int GetSizeSTACK(const STACK *stack);
int GetCapacitySTACK(const STACK *stack);
bool IsFullSTACK(const STACK *stack);
bool IsEmptySTACK(const STACK *stack);

//==============================================================
// Private utility member function prototypes
//==============================================================
// (none)

#endif
