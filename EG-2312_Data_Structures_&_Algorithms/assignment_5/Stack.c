//--------------------------------------------------
// Dr. Art Hanna
// Stack.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack.h"

//--------------------------------------------------
void ConstructSTACK(STACK *stack,const int capacity)
//--------------------------------------------------
{
   stack->size = 0;
   stack->capacity = capacity;
   stack->elements = (int *) malloc(sizeof(int)*capacity);
}

//--------------------------------------------------
void DestructSTACK(STACK *stack)
//--------------------------------------------------
{
   free(stack->elements);
}

//--------------------------------------------------
void PushSTACK(STACK *stack,const int element)
//--------------------------------------------------
{
   stack->elements[stack->size] = element;
   ++stack->size;
}

//--------------------------------------------------
void PopSTACK(STACK *stack)
//--------------------------------------------------
{
   stack->size--;
}

//--------------------------------------------------
int PeekSTACK(const STACK *stack,const int offset)
//--------------------------------------------------
{
   return( stack->elements[stack->size-(offset+1)] );
}

//--------------------------------------------------
int GetSizeSTACK(const STACK *stack)
//--------------------------------------------------
{
   return( stack->size );
}

//--------------------------------------------------
int GetCapacitySTACK(const STACK *stack)
//--------------------------------------------------
{
   return( stack->capacity );
}

//--------------------------------------------------
bool IsFullSTACK(const STACK *stack)
//--------------------------------------------------
{
   return( (stack->size == stack->capacity) ? true : false );
}

//--------------------------------------------------
bool IsEmptySTACK(const STACK *stack)
//--------------------------------------------------
{
   return( stack->size == 0 );
}
