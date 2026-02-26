//--------------------------------------------------------------
// Dr. Art Hanna
// STACK ADT: Problem #2
// Problem2.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack2.h"
#include "ADTExceptions.h"

//--------------------------------------------------------------
int main()
//--------------------------------------------------------------
{
   int capacity;

   printf("capacity? ");
   while ( scanf("%d",&capacity) != EOF )
   {
      STACK stack;
      int i,pushN,popN,peekN;

      ConstructSTACK(&stack,capacity);
      printf("pushN? "); scanf("%d",&pushN);
      printf("peekN? "); scanf("%d",&peekN);
      printf(" popN? "); scanf("%d",&popN);
      for (i = 1; i <= pushN; i++) 
         PushSTACK(&stack,i);
/*
   Method (1) Allow ADT to RaiseADTException() which provides a uniform
      exception-handling approach for *ALL* ADT
*/
      for (i = 1; i <= peekN; i++)
         printf("%d ",PeekSTACK(&stack,i-1));
      printf("\n");
//--------------------------------------------------------------
// END Method (1)
//--------------------------------------------------------------

/* 
   Method (2) ADT returns exception status (true or false) then client code
      checks status after *EVERY* ADT exception-producing operation call
      for (i = 1; i <= peekN; i++)
      {
         bool exception;
         int x = PeekSTACK2(&stack,i-1,&exception);

         if ( exception )
         {
            fprintf(stderr,"\a\nException \"%s\"\n\n",STACK_OFFSET_ERROR);
            system("PAUSE");
            exit( 1 );
         }
         printf("% d",x);
      }
      printf("\n");
*/
//--------------------------------------------------------------
// END Method (2)
//--------------------------------------------------------------

/*
   Method (3) ADT handles the exception (identical to Method (1)
      from client’s point-of-view)
      for (i = 1; i <= peekN; i++)
         printf("%d ",PeekSTACK3(&stack,i-1));
      printf("\n");
*/
//--------------------------------------------------------------
// END Method (3)
//--------------------------------------------------------------
      for (i = 1; i <= popN; i++) 
         PopSTACK(&stack);

      DestructSTACK(&stack);
      printf("\ncapacity? ");
   }

   system("PAUSE");
   return( 0 );
}

