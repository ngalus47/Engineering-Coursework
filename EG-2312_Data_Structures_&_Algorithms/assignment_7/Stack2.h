//--------------------------------------------------
// Dr. Art Hanna
// STACK2.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack2.h"
#include "ADTExceptions.h"

//--------------------------------------------------
void ConstructSTACK(STACK *stack,const int capacity)
//--------------------------------------------------
{
   if ( capacity <= 0 ) RaiseADTException(STACK_CAPACITY_ERROR);

   stack->size = 0;
   stack->capacity = capacity;
   stack->elements = (int *) malloc(sizeof(int)*capacity);
   
   if ( stack->elements == NULL ) RaiseADTException(MALLOC_ERROR);
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
   if ( IsFullSTACK(stack) ) RaiseADTException(STACK_OVERFLOW);

   stack->elements[stack->size] = element;
   ++stack->size;
}

//--------------------------------------------------
void PopSTACK(STACK *stack)
//--------------------------------------------------
{
   if ( IsEmptySTACK(stack) ) RaiseADTException(STACK_UNDERFLOW);

   stack->size--;
}

//--------------------------------------------------
int PeekSTACK(const STACK *stack,const int offset)
//--------------------------------------------------
{
   if ( !((0 <= offset) && (offset <= GetSizeSTACK(stack)-1)) ) RaiseADTException(STACK_OFFSET_ERROR);

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

//--------------------------------------------------
int PeekSTACK2(const STACK *stack,const int offset,bool *exception)
//--------------------------------------------------
{
   if ( !((0 <= offset) && (offset <= GetSizeSTACK(stack)-1)) )
   {
      *exception = true;
      return( 0 );
   }
   *exception = false;
   return( stack->elements[stack->size-(offset+1)] );
}

//--------------------------------------------------
int PeekSTACK3(const STACK *stack,const int offset)
//--------------------------------------------------
{
   if ( !((0 <= offset) && (offset <= GetSizeSTACK(stack)-1)) )
   {
      fprintf(stderr,"\a\nException \"%s\"\n\n",STACK_OFFSET_ERROR);
      system("PAUSE");
      exit( 1 );
   }
   return( stack->elements[stack->size-(offset+1)] );
}

