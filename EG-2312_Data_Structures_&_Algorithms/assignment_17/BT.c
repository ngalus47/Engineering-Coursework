//--------------------------------------------------------------
// Dr. Art Hanna
// Generic BT (binary tree) abstract data type
// BT.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "BT.h"
#include "ADTExceptions.h"

//--------------------------------------------------------------
void ConstructBT(BT *bt,void (*DestructElement)(const void *element))
//--------------------------------------------------------------
{
   bt->root = NULL;
   bt->DestructElement = DestructElement;
}

//--------------------------------------------------------------
void DestructBT(BT *bt)
//--------------------------------------------------------------
{
// Do post-order traversal of *bt to destruct tree nodes
   DestructBT2(bt,bt->root);
}

//--------------------------------------------------------------
static void DestructBT2(BT *bt,BTNODE *node)
//--------------------------------------------------------------
{
   if ( node != NULL )
   {
      DestructBT2(bt,node->LLink);
      DestructBT2(bt,node->RLink);
      if ( bt->DestructElement != NULL )
         bt->DestructElement(node->element);
      free(node);
   }
}

//--------------------------------------------------------------
bool IsEmptyBT(const BT *bt)
//--------------------------------------------------------------
{
   return( bt->root == NULL );
}

//--------------------------------------------------------------
void SetRootBT(BT *bt,const BTNODE *node)
//--------------------------------------------------------------
{
   bt->root = (BTNODE *) node;
}

//--------------------------------------------------------------
BTNODE *GetRootBT(const BT *bt)
//--------------------------------------------------------------
{
   return( bt->root );
}

//--------------------------------------------------------------
void PreOrderBT(BT *bt,void (*ProcessElement)(BTNODE *node))
//--------------------------------------------------------------
{
   PreOrderBT2(bt->root,ProcessElement);
}

//--------------------------------------------------------------
static void PreOrderBT2(BTNODE *node,void (*ProcessElement)(BTNODE *node))
//--------------------------------------------------------------
{
   if ( node != NULL )
   {
      (*ProcessElement)(node);
      PreOrderBT2((BTNODE *) node->LLink,ProcessElement);
      PreOrderBT2((BTNODE *) node->RLink,ProcessElement);
   }
}

//--------------------------------------------------------------
void InOrderBT(BT *bt,void (*ProcessElement)(BTNODE *node))
//--------------------------------------------------------------
{
   InOrderBT2(bt->root,ProcessElement);
}

//--------------------------------------------------------------
static void InOrderBT2(BTNODE *node,void (*ProcessElement)(BTNODE *node))
//--------------------------------------------------------------
{
   if ( node != NULL )
   {
      InOrderBT2(node->LLink,ProcessElement);
      ProcessElement(node);
      InOrderBT2(node->RLink,ProcessElement);
   }
}

//--------------------------------------------------------------
void PostOrderBT(BT *bt,void (*ProcessElement)(BTNODE *node))
//--------------------------------------------------------------
{
   PostOrderBT2(bt->root,ProcessElement);
}

//--------------------------------------------------------------
static void PostOrderBT2(BTNODE *node,void (*ProcessElement)(BTNODE *node))
//--------------------------------------------------------------
{
   if ( node != NULL )
   {
      PostOrderBT2(node->LLink,ProcessElement);
      PostOrderBT2(node->RLink,ProcessElement);
      ProcessElement(node);
   }
}

//--------------------------------------------------------------
BTNODE *NewBTNODE(const void *element)
//--------------------------------------------------------------
{
   BTNODE *node;

   node = (BTNODE *) malloc(sizeof(BTNODE));

   if ( node == NULL ) RaiseADTException(MALLOC_ERROR);   

   node->element = (void *) element;
   node->LLink = node->RLink = NULL;
   return( node );
}

//--------------------------------------------------------------
void SetElementBTNODE(BTNODE *node,const void *element)
//--------------------------------------------------------------
{
   if ( node == NULL ) RaiseADTException(BT_NULL_POINTER_ERROR);
   
   node->element = (void *) element;
}

//--------------------------------------------------------------
void SetLLinkBTNODE(BTNODE *node,const BTNODE *LLink)
//--------------------------------------------------------------
{
   if ( node == NULL ) RaiseADTException(BT_NULL_POINTER_ERROR);
   
   node->LLink = (BTNODE *) LLink;
}

//--------------------------------------------------------------
void SetRLinkBTNODE(BTNODE *node,const BTNODE *RLink)
//--------------------------------------------------------------
{
   if ( node == NULL ) RaiseADTException(BT_NULL_POINTER_ERROR);

   node->RLink = (BTNODE *) RLink;
}

//--------------------------------------------------------------
void *GetElementBTNODE(const BTNODE *node)
//--------------------------------------------------------------
{
   if ( node == NULL ) RaiseADTException(BT_NULL_POINTER_ERROR);

   return( node->element );
}

//--------------------------------------------------------------
BTNODE *GetLLinkBTNode(const BTNODE *node)
//--------------------------------------------------------------
{
   if ( node == NULL ) RaiseADTException(BT_NULL_POINTER_ERROR);

   return( node->LLink );
}

//--------------------------------------------------------------
BTNODE *GetRLinkBTNode(const BTNODE *node)
//--------------------------------------------------------------
{
   if ( node == NULL ) RaiseADTException(BT_NULL_POINTER_ERROR);

   return( node->RLink );
}

