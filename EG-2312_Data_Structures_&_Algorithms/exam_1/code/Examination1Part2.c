//----------------------------------------------------
// Nick Galus
//----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack.h"

//----------------------------------------------------
int main()
//----------------------------------------------------
{
   void DisplayStack(const STACK *stack);
   
   int n;
   
   printf("n? ");
   while ( scanf("%d",&n) != EOF )
   {
      STACK stack;
      
      ConstructSTACK(&stack,1);
      DisplayStack(&stack);
      
      for (int i = 1; i <= n; i++)
      {
         PushSTACK2(&stack,i);
         DisplayStack(&stack);
      }
      
         DestructSTACK(&stack);
      printf("\nn? ");
   }
   return( 0 );
}

//----------------------------------------------------
void DisplayStack(const STACK *stack)
//----------------------------------------------------
{
   printf("(%3d,%3d):",GetSizeSTACK(stack),GetCapacitySTACK(stack));
   
   if ( GetSizeSTACK(stack) == 0 )
      printf(" (empty)\n");
   else
   {
      for (int offset = GetSizeSTACK(stack)-1; offset >= 0; offset--)
         printf(" %3d",PeekSTACK(stack,offset));
      printf("\n");
   }
}
