//--------------------------------------------------------------
// Dr. Art Hanna
// Singly-linked list (SLL) abstract datatype
// SLL.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "SLL.h"
#include "ADTExceptions.h"

//--------------------------------------------------------------
void ConstructSLL(SLL *sll,
                  void (*DestructElement)(const char *element))
//--------------------------------------------------------------
{
   sll->size = 0;
   sll->head = NULL;
   sll->tail = NULL;
   sll->DestructElement = DestructElement;
}

//--------------------------------------------------------------
void DestructSLL(SLL *sll)
//--------------------------------------------------------------
{
   while ( !IsEmptySLL(sll) )
   {
      PopHeadSLL(sll);
   }
}

//--------------------------------------------------------------
void PushHeadSLL(SLL *sll,const char *element)
//--------------------------------------------------------------
{
   SLLNODE *n = (SLLNODE *) malloc(sizeof(SLLNODE));

   if ( n == NULL ) RaiseADTException(MALLOC_ERROR);

   n->element = (char *) element;
   if ( IsEmptySLL(sll) )
   {
      n->FLink = NULL;
      sll->head = n;
      sll->tail = n;
   }
   else
   {
      n->FLink = sll->head;
      sll->head = n;
   }
   sll->size++;
}

//--------------------------------------------------------------
void PopHeadSLL(SLL *sll)
//--------------------------------------------------------------
{
   SLLNODE *p = sll->head;

   if ( GetSizeSLL(sll) == 0 ) RaiseADTException(SLL_UNDERFLOW);

   if ( GetSizeSLL(sll) == 1 )
   {
      sll->head = NULL;
      sll->tail = NULL;
   }
   else
   {
      sll->head = p->FLink;
   }
   if ( sll->DestructElement != NULL ) sll->DestructElement(p->element);
   free(p);
   sll->size--;
}

//--------------------------------------------------------------
void PushTailSLL(SLL *sll,const char *element)
//--------------------------------------------------------------
{
   SLLNODE *n = (SLLNODE *) malloc(sizeof(SLLNODE));

   if ( n == NULL ) RaiseADTException(MALLOC_ERROR);

   n->element = (char *) element;
   n->FLink = NULL;
   if ( IsEmptySLL(sll) )
   {
      sll->head = n;
      sll->tail = n;
   }
   else
   {
      sll->tail->FLink = n;
      sll->tail = n;
   }
   sll->size++;
}

//--------------------------------------------------------------
char *PeekSLL(const SLL *sll,const int offset)
//--------------------------------------------------------------
{
   SLLNODE *p = sll->head;
   int i;

   if ( !((0 <= offset) && (offset <= GetSizeSLL(sll)-1)) ) RaiseADTException(SLL_OFFSET_ERROR);

   for (i = 0; i <= offset-1; i++)
      p = p->FLink;
   return( p->element );
}

//--------------------------------------------------------------
bool IsEmptySLL(const SLL *sll)
//--------------------------------------------------------------
{
   return( sll->size == 0 );
}

//--------------------------------------------------------------
int GetSizeSLL(const SLL *sll)
//--------------------------------------------------------------
{
   return( sll->size );
}

