//--------------------------------------------------------------
// Nick Galus 
// Doubly-linked list (DLL) generic abstract datatype
// DLL2.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "DLL.h"
#include "ADTExceptions.h"

//--------------------------------------------------------------
void ConstructDLL(DLL *dll,
                  void (*DestructElement)(const void *element))
//--------------------------------------------------------------
{
   dll->size = 0;
   dll->head = NULL;
   dll->tail = NULL;
   dll->DestructElement = DestructElement;
}

//--------------------------------------------------------------
void DestructDLL(DLL *dll)
//--------------------------------------------------------------
{
   ClearDLL(dll);
}

//--------------------------------------------------------------
void InsertDLL(DLL *dll,const int offset,const void *element)
//--------------------------------------------------------------
{
   DLLNODE *n = (DLLNODE *) malloc(sizeof(DLLNODE));

   if ( n == NULL ) RaiseADTException(MALLOC_ERROR);

   n->element = (void *) element;

   if ( !((0 <= offset) && (offset <= GetSizeDLL(dll))) ) RaiseADTException(DLL_OFFSET_ERROR);

   // Insert new node *BEFORE* offset node except insert *AFTER* tail node when offset = size-of-list
   if ( IsEmptyDLL(dll) )                        // *dll is empty
   {
      dll->head = n;
      dll->tail = n;
      n->BLink = NULL;
      n->FLink = NULL;
   }
   else                                          // *dll contains at least 1 node
   {
      if ( offset == 0 )                         // insert new head node
      {
         n->BLink = NULL;
         n->FLink = dll->head;
         dll->head->BLink = n;
         dll->head = n;
      }
      else if ( offset == GetSizeDLL(dll) )      // insert new tail node
      {
         n->BLink = dll->tail;
         n->FLink = NULL;
         dll->tail->FLink = n;
         dll->tail = n;
      }
      else                                       // insert "middle node"
      {
         DLLNODE *p = dll->head;                 // set p to point-to node to right of inserted node
         int i;

         for (i = 1; i <= offset-1; i++)
            p = p->FLink;

         n->FLink = p;
         n->BLink = p->BLink;
         p->BLink->FLink = n;
         p->BLink = n;
      }
   }
   dll->size++;
}

//--------------------------------------------------------------
void InsertDLL2(DLL *dll,const void *element,
                bool (*InsertNow)(const void *LHS,const void *element,const void *RHS))
//--------------------------------------------------------------
{
   DLLNODE *n = (DLLNODE *) malloc(sizeof(DLLNODE));

   if ( n == NULL ) RaiseADTException(MALLOC_ERROR);

   n->element = (void *) element;

   if ( GetSizeDLL(dll) == 0 )
   {
      n->BLink = NULL;
      n->FLink = NULL;
      dll->head = n;
      dll->tail = n;
   }
   else
   {
      DLLNODE *pLHS = NULL;       void *LHS = NULL;
      DLLNODE *pRHS = dll->head;  void *RHS = pRHS->element;

      while ( (pRHS != NULL) && !InsertNow(LHS,element,RHS) )
      {
         pLHS = pRHS;        LHS = pLHS->element;
         pRHS = pRHS->FLink; RHS = (pRHS != NULL) ? pRHS->element : NULL;
      }
      if ( (pLHS == NULL) && (pRHS != NULL) )              // insert new head node
      {
         n->BLink = NULL;
         n->FLink = dll->head;
         dll->head->BLink = n;
         dll->head = n;
      }
      else if ( (pLHS != NULL) && (pRHS != NULL) )         // insert new "middle node"
      {
         n->BLink = pLHS;
         n->FLink = pRHS;
         pLHS->FLink = n;
         pRHS->BLink = n;
      }
      else if ( (pLHS != NULL) && (pRHS == NULL) )         // insert new tail node
      {
         n->BLink = dll->tail;
         n->FLink = NULL;
         dll->tail->FLink = n;
         dll->tail = n;
      }
   }
   dll->size++;
}

//--------------------------------------------------------------
void DeleteDLL(DLL *dll,const int offset)
//--------------------------------------------------------------
{
   DLLNODE *p = dll->head;
   int i;

   if ( GetSizeDLL(dll) == 0 ) RaiseADTException(DLL_UNDERFLOW);

   if ( !((0 <= offset) && (offset <= GetSizeDLL(dll)-1)) ) RaiseADTException(DLL_OFFSET_ERROR);

   for (i = 0; i <= offset-1; i++)
      p = p->FLink;

   if      ( (p->BLink == NULL) && (p->FLink == NULL) )    // delete singleton node
   {
      dll->head = NULL;
      dll->tail = NULL;
   }
   else if ( (p->BLink == NULL) && (p->FLink != NULL) )    // delete head node
   {
      dll->head = p->FLink;
      dll->head->BLink = NULL;
   }
   else if ( (p->BLink != NULL) && (p->FLink != NULL) )    // delete "middle node"
   {
      p->BLink->FLink = p->FLink;
      p->FLink->BLink = p->BLink;
   }
   else if ( (p->BLink != NULL) && (p->FLink == NULL) )    // delete tail node
   {
      dll->tail = p->BLink;
      p->BLink->FLink = NULL;
   }

   if ( dll->DestructElement != NULL ) dll->DestructElement(p->element);
   free(p);
   dll->size--;
}

//--------------------------------------------------------------
void *PeekDLL(const DLL *dll,const int offset)
//--------------------------------------------------------------
{
   DLLNODE *p = dll->head;
   int i;

   if ( !((0 <= offset) && (offset <= GetSizeDLL(dll)-1)) ) RaiseADTException(DLL_OFFSET_ERROR);

   for (i = 0; i <= offset-1; i++)
      p = p->FLink;

   return( p->element );
}

//--------------------------------------------------------------
void ClearDLL(DLL *dll)
//--------------------------------------------------------------
{
   while ( !IsEmptyDLL(dll) )
      DeleteDLL(dll,0);
}

//--------------------------------------------------------------
bool IsEmptyDLL(const DLL *dll)
//--------------------------------------------------------------
{
   return( dll->size == 0 );
}

//--------------------------------------------------------------
int GetSizeDLL(const DLL *dll)
//--------------------------------------------------------------
{
   return( dll->size );
}

//--------------------------------------------------------------
void TraverseFromHeadToTailDLL(const DLL *dll,
                               void (*ProcessElement)(void *element))
//--------------------------------------------------------------
{
   DLLNODE *p = dll->head;

   while ( p != NULL )
   {
      ProcessElement(p->element);
      p = p->FLink;
   }
}

//--------------------------------------------------------------
void TraverseFromTailToHeadDLL(const DLL *dll,
                               void (*ProcessElement)(void *element))
//--------------------------------------------------------------
{
   DLLNODE *p = dll->tail;

   while ( p != NULL )
   {
      ProcessElement(p->element);
      p = p->BLink;
   }
}

//--------------------------------------------------------------
void StoreDLL(FILE *OUT,const DLL *dll,
              void (*WriteElement)(FILE *OUT,const void *element))
//--------------------------------------------------------------
{
   DLLNODE *p = dll->head;

   fwrite(&(dll->size),sizeof(int),1,OUT);

   for (int i = 1; (i <= GetSizeDLL(dll)) && !ferror(OUT); i++)
   {
      WriteElement(OUT,p->element);
      p = p->FLink;
   }
   if ( ferror(OUT) ) RaiseADTException(IO_ERROR);
}

//--------------------------------------------------------------
void LoadDLL(FILE *IN,DLL *dll,
             void (*ReadElement)(FILE *IN,void **element),
             void (*DestructElement)(const void *element))
//--------------------------------------------------------------
{
   int size;

   DestructDLL(dll);
   ConstructDLL(dll,DestructElement);

   fread(&size,sizeof(int),1,IN);

   for (int offset = 0; (offset <= size-1) && !ferror(IN); offset++)
   {
      char *element;

      ReadElement(IN,(void **) &element);

      InsertDLL(dll,offset,element);
   }
   if ( ferror(IN) ) RaiseADTException(IO_ERROR);
}
