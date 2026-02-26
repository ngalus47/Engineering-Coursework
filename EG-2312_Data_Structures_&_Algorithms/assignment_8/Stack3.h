//----------------------------------------------------
// Dr. Art Hanna
// STACK3.h
//----------------------------------------------------
#ifndef STACK2_H
#define STACK2_H

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
void OutputSTACK(const STACK *stack,FILE *OUT);
void CopySTACK(STACK *LHS,const STACK *RHS);
bool EQSTACK(const STACK *LHS,const STACK *RHS);

//==============================================================
// Private utility member function prototypes
//==============================================================
// (none)

#endif

