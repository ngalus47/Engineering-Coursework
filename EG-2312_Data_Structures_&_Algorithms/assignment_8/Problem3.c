//--------------------------------------------------------------
// Dr. Art Hanna
// STACK ADT: Problem #3
// Problem3.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack3.h"
#include "ADTExceptions.h"

//--------------------------------------------------------------
int main()
//--------------------------------------------------------------
{
   int capacity;
   STACK stack1,stack2;
   int i,pushN;

   printf("capacity? "); scanf("%d",&capacity);
   printf("pushN? "); scanf("%d",&pushN);

   ConstructSTACK(&stack1,capacity);
   ConstructSTACK(&stack2,capacity+3);
   printf("\nAfter constructing stack1 and stack2\n");
   printf("stack1 = "); OutputSTACK(&stack1,stdout); printf("\n");
   printf("stack2 = "); OutputSTACK(&stack2,stdout); printf("\n");

   for (i = 1; i <= pushN; i++) 
      PushSTACK(&stack1,i);
   printf("\nAfter pushing %d-to-%d on stack1\n",1,pushN);
   printf("stack1 = "); OutputSTACK(&stack1,stdout); printf("\n");

   CopySTACK(&stack2,&stack1);
   printf("\nAfter copying stack1 to stack2\n");
   printf("stack1 = "); OutputSTACK(&stack1,stdout); printf("\n");
   printf("stack2 = "); OutputSTACK(&stack2,stdout); printf("\n");
   printf("stack1 %s stack2\n",EQSTACK(&stack1,&stack2) ? "==" : "!=");

   PushSTACK(&stack1,pushN+1);
   printf("\nAfter pushing %d on stack1\n",pushN+1);
   printf("stack1 = "); OutputSTACK(&stack1,stdout); printf("\n");
   PushSTACK(&stack2,pushN+2);
   printf("After pushing %d on stack2\n",pushN+2);
   printf("stack2 = "); OutputSTACK(&stack2,stdout); printf("\n");
   printf("stack1 %s stack2\n",EQSTACK(&stack1,&stack2) ? "==" : "!=");

   printf("\nAfter popping %d off and ",PeekSTACK(&stack2,0));
   PopSTACK(&stack2);
   PushSTACK(&stack2,pushN+1);
   PushSTACK(&stack2,pushN+2);
   printf("pushing %d, %d on stack2\n",pushN+1,pushN+2);
   printf("stack1 = "); OutputSTACK(&stack1,stdout); printf("\n");
   printf("stack2 = "); OutputSTACK(&stack2,stdout); printf("\n");
   printf("stack1 %s stack2\n",EQSTACK(&stack1,&stack2) ? "==" : "!=");
   printf("\n");

   DestructSTACK(&stack1);
   DestructSTACK(&stack2);

   system("PAUSE");
   return( 0 );
}

