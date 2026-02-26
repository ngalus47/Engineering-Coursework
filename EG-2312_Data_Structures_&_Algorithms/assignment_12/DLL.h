//--------------------------------------------------------------
// Dr. Art Hanna
// Doubly-linked list (DLL) generic abstract datatype
// DLL.h
//--------------------------------------------------------------
#ifndef DLL_H
#define DLL_H

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

//==============================================================
// Private utility member function prototypes
//==============================================================
// (none)

#endif

