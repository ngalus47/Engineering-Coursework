//--------------------------------------------------
// Dr. Art Hanna
// STACK3.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack3.h"
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
void OutputSTACK(const STACK *stack,FILE *OUT)
//--------------------------------------------------
{
   fprintf(OUT,"[%d:%d] ",GetSizeSTACK(stack),GetCapacitySTACK(stack));
   if ( IsEmptySTACK(stack) )
      fprintf(OUT,"(empty)");
   else
   {
      int offset;
      int UB = GetSizeSTACK(stack)-1;

      for (offset = 0; offset <= UB; offset++)
         fprintf(OUT,"%d%c",PeekSTACK(stack,offset),((offset == UB) ? '.' : ' '));
   }
}

//--------------------------------------------------
void CopySTACK(STACK *LHS,const STACK *RHS)
//--------------------------------------------------
{
   if ( LHS != RHS )
   {
      int offset;

            for (offset = GetSizeSTACK(RHS) - 1; offset >= 0; offset--)
		    PushSTACK(LHS, PeekSTACK(RHS, offset));

   }
}


//--------------------------------------------------
bool EQSTACK(const STACK *LHS,const STACK *RHS)
//--------------------------------------------------
{
   bool r;
   int offset;

   if ( LHS->size != RHS->size ) return( false );

   r = true;
   for (offset = 0; offset <= LHS->size - 1; offset++)
   {
      if ( PeekSTACK(LHS,offset) != PeekSTACK(RHS,offset) )
      {
         r = false;
         break;
      }
   }

   return( r );
}

