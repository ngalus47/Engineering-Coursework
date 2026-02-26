//--------------------------------------------------------------
// Nick Galus 
// Doubly-linked list (DLL) generic abstract datatype
// DLL2.h
//--------------------------------------------------------------
#ifndef DLL2_H
#define DLL2_H

#include <stdio.h>
#include <stdbool.h>

//==============================================================
// Data model definitions
//==============================================================
typedef struct DLLNODE
{
   void *element;         // generic pointer-to element "contained" in node
   struct DLLNODE *BLink; // (B)ackward Link to logically-previous node
   struct DLLNODE *FLink; // (F)orward Link to logically-next node
} DLLNODE;

typedef struct DLL
{
   int size;              // number of nodes in list
   DLLNODE *head;         // pointer-to logically-first node
   DLLNODE *tail;         // pointer-to logically-last  node
   void (*DestructElement)(const void *element);
} DLL;

//==============================================================
// Public member function prototypes
//==============================================================
void ConstructDLL(DLL *dll,
                  void (*DestructElement)(const void *element));
void DestructDLL(DLL *dll);

void InsertDLL(DLL *dll,const int offset,const void *element);
void InsertDLL2(DLL *dll,const void *element,
                bool (*InsertNow)(const void *LHS,const void *element,const void *RHS));

void DeleteDLL(DLL *dll,const int offset);
void *PeekDLL(const DLL *dll,const int offset);
void ClearDLL(DLL *dll);
bool IsEmptyDLL(const DLL *dll);
int GetSizeDLL(const DLL *dll);

void TraverseFromHeadToTailDLL(const DLL *dll,
                               void (*ProcessElement)(void *element));
void TraverseFromTailToHeadDLL(const DLL *dll,
                               void (*ProcessElement)(void *element));

void StoreDLL(FILE *OUT,const DLL *dll,
              void (*WriteElement)(FILE *OUT,const void *element));
void LoadDLL(FILE *IN,DLL *dll,
             void (*ReadElement)(FILE *IN,void **element),
             void (*DestructElement)(const void *element));

//==============================================================
// Private utility member function prototypes
//==============================================================
// (none)

#endif
