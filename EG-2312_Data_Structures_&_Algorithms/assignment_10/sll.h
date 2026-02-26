//--------------------------------------------------------------
// Dr. Art Hanna
// Singly-linked list (SLL) abstract datatype
// SLL.h
//--------------------------------------------------------------
#ifndef SLL_H
#define SLL_H

//==============================================================
// Data model definitions
//==============================================================
typedef struct SLLNODE
{
   char *element;
   struct SLLNODE *FLink; // (F)orward Link to logically-next node
} SLLNODE;

typedef struct SLL
{
   int size;
   SLLNODE *head;         // pointer-to logically-first node
   SLLNODE *tail;         // pointer-to logically-last  node
   void (*DestructElement)(const char *element);
} SLL;

//==============================================================
// Public member function prototypes
//==============================================================
void ConstructSLL(SLL *sll,
                  void (*DestructElement)(const char *element));
void DestructSLL(SLL *sll);
void PushHeadSLL(SLL *sll,const char *element);
void PopHeadSLL(SLL *sll);
void PushTailSLL(SLL *sll,const char *element);
char *PeekSLL(const SLL *sll,const int offset);
bool IsEmptySLL(const SLL *sll);
int GetSizeSLL(const SLL *sll);

//==============================================================
// Private utility member function prototypes
//==============================================================
// (none)

#endif

