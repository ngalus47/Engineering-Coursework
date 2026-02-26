//--------------------------------------------------------------
// Dr. Art Hanna
// Generic BT (binary tree) abstract data type
// BT.h
//--------------------------------------------------------------
#ifndef BT_H
#define BT_H

#include <stdbool.h>

//==============================================================
// Data model definitions
//==============================================================
typedef struct BTNODE
{
   void *element;
   struct BTNODE *LLink;          // pointer-to (L)eft  child node
   struct BTNODE *RLink;          // pointer-to (R)ight child node
} BTNODE;

typedef struct BT
{
   BTNODE *root;
   void (*DestructElement)(const void *element);
} BT;

//==============================================================
// Public member function prototypes
//==============================================================
void ConstructBT(BT *bt,void (*DestructElement)(const void *element));
void DestructBT(BT *bt);
bool IsEmptyBT(const BT *bt);
void SetRootBT(BT *bt,const BTNODE *node);
BTNODE *GetRootBT(const BT *bt);
void PreOrderBT(BT *bt,void (*ProcessElement)(BTNODE *node));
void InOrderBT(BT *bt,void (*ProcessElement)(BTNODE *node));
void PostOrderBT(BT *bt,void (*ProcessElement)(BTNODE *node));

BTNODE *NewBTNODE(const void *element);
void SetElementBTNODE(BTNODE *node,const void *element);
void SetLLinkBTNODE(BTNODE *node,const BTNODE *LLink);
void SetRLinkBTNODE(BTNODE *node,const BTNODE *RLink);
void *GetElementBTNODE(const BTNODE *node);
BTNODE *GetLLinkBTNODE(const BTNODE *node);
BTNODE *GetRLinkBTNODE(const BTNODE *node);

//==============================================================
// Private utility member function prototypes
//==============================================================
static void DestructBT2(BT *bt,BTNODE *node);
static void PreOrderBT2(BTNODE *node,void (*ProcessElement)(BTNODE *node));
static void InOrderBT2(BTNODE *node,void (*ProcessElement)(BTNODE *node));
static void PostOrderBT2(BTNODE *node,void (*ProcessElement)(BTNODE *node));

#endif

