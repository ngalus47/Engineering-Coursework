//----------------------------------------------------
// Dr. Art Hanna
// STACK ADT: Problem #1
// Menu-based "driver" program used to test the STACK
//    abstract data type member functions
// Problem1.c
//----------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Stack.h"

#define ILLEGALOPERATION "\a\n***Illegal operation!***\n\n"

typedef struct MENUITEM
{
   char menuString[50];
   void (*menuFunction)(STACK *stack,bool *isConstructed);
} MENUITEM;

//----------------------------------------------------
int main()
//----------------------------------------------------
{
   void DoMenu(const MENUITEM menu[],const int MENUSIZE);
   void DoMenu1(STACK *stack,bool *isConstructed);
   void DoMenu2(STACK *stack,bool *isConstructed);
   void DoMenu3(STACK *stack,bool *isConstructed);
   void DoMenu4(STACK *stack,bool *isConstructed);
   void DoMenu5(STACK *stack,bool *isConstructed);
   void DoMenu6(STACK *stack,bool *isConstructed);
   void DoMenu7(STACK *stack,bool *isConstructed);
   void DoMenu8(STACK *stack,bool *isConstructed);
   void DoMenu9(STACK *stack,bool *isConstructed);

   const MENUITEM menu[] =
   {
      { "Construct Stack               ", DoMenu1  },
      { "Destruct Stack                ", DoMenu2  },
      { "Push Stack                    ", DoMenu3  },
      { "Pop Stack                     ", DoMenu4  },
      { "Peek Stack                    ", DoMenu5  },
      { "Get Size Stack                ", DoMenu6  },
      { "Get Capacity Stack            ", DoMenu7  },
      { "Is Full Stack                 ", DoMenu8  },
      { "Is Empty Stack                ", DoMenu9  }
   };

   const int MENUSIZE = sizeof(menu)/sizeof(MENUITEM);

   DoMenu(menu,MENUSIZE);
   
   //system("PAUSE"); windows only command
   return( 0 );
}

//----------------------------------------------------
void DoMenu(const MENUITEM menu[],const int MENUSIZE)
//----------------------------------------------------
{
   void DisplaySTACK(const STACK stack);

   STACK stack;
   bool isConstructed = false;
   int menuNumber;

   do
   {
      do
      {
         int i;
      
         printf("==================================================\n");
         for (i = 0; i <= MENUSIZE-1; i++)
            printf("%2d %s\n",i+1,menu[i].menuString);
         printf("%2d End\n",MENUSIZE+1);
         printf("==================================================\n");
         printf("menuNumber? "); scanf("%d",&menuNumber);
      } while ( !((1 <= menuNumber) && (menuNumber <= MENUSIZE+1)) );
      if ( menuNumber != MENUSIZE+1 )
         (*menu[menuNumber-1].menuFunction)(&stack,&isConstructed);
      if ( isConstructed && (menuNumber != MENUSIZE+1) ) DisplaySTACK(stack);
   } while ( menuNumber != MENUSIZE+1 );
   if ( isConstructed ) DestructSTACK(&stack);
}

//----------------------------------------------------
void DisplaySTACK(const STACK stack)
//----------------------------------------------------
{
   printf("\nTOS = ");
   if ( IsEmptySTACK(&stack) )
      printf("(empty)\n");
   else
   {
      int LB = 0;
      int UB = GetSizeSTACK(&stack)-1;
      
      for (int offset = LB; offset <= UB; offset++)
         printf("%d%c",PeekSTACK(&stack,offset),((offset == UB) ? '\n' : ' '));
   }
   printf("\n");
}

//----------------------------------------------------
void DoMenu1(STACK *stack,bool *isConstructed)
//----------------------------------------------------
{
   if ( *isConstructed )
      printf(ILLEGALOPERATION);
   else
   {
      int capacity;
      
      printf("capacity? "); scanf("%d",&capacity);
      ConstructSTACK(stack,capacity);
      *isConstructed = true;
   }
}

//----------------------------------------------------
void DoMenu2(STACK *stack,bool *isConstructed)
//----------------------------------------------------
{
   if ( !*isConstructed )
      printf(ILLEGALOPERATION);
   else
   {
      DestructSTACK(stack);
      *isConstructed = false;
   }
}

//----------------------------------------------------
void DoMenu3(STACK *stack,bool *isConstructed)
//----------------------------------------------------
{
   if ( !*isConstructed || IsFullSTACK(stack) )
      printf(ILLEGALOPERATION);
   else
   {
      int element;
      
      printf("element? ");
      while ( scanf("%d",&element) != EOF )
      {
         if ( IsFullSTACK(stack) )
            printf(ILLEGALOPERATION);
         else
            PushSTACK(stack,element);
         printf("element? ");
      }
      clearerr(stdin); // needed to add cause EOF escape operator did not clear the buffer
   }
}

//----------------------------------------------------
void DoMenu4(STACK *stack,bool *isConstructed)
//----------------------------------------------------
{
   if ( !*isConstructed || IsEmptySTACK(stack) )
      printf(ILLEGALOPERATION);
   else
      PopSTACK(stack);
}

//----------------------------------------------------
void DoMenu5(STACK *stack,bool *isConstructed)
//----------------------------------------------------
{
   if ( !*isConstructed )
      printf(ILLEGALOPERATION);
   else
   {
      int offset;
      
      printf("offset [0,%d]? ",GetSizeSTACK(stack)-1); scanf("%d",&offset);
      if ( (offset >= 0) && (offset <= GetSizeSTACK(stack)-1) )
         printf("Peek stack = %d\n",PeekSTACK(stack,offset));
      else
         printf(ILLEGALOPERATION);
   }
}

//----------------------------------------------------
void DoMenu6(STACK *stack,bool *isConstructed)
//----------------------------------------------------
{
   if ( !*isConstructed )
      printf(ILLEGALOPERATION);
   else
      printf("Stack size = %d\n",GetSizeSTACK(stack));
}

//----------------------------------------------------
void DoMenu7(STACK *stack,bool *isConstructed)
//----------------------------------------------------
{
   if ( !*isConstructed )
      printf(ILLEGALOPERATION);
   else
      printf("Stack capacity = %d\n",GetCapacitySTACK(stack));
}

//----------------------------------------------------
void DoMenu8(STACK *stack,bool *isConstructed)
//----------------------------------------------------
{
   if ( !*isConstructed )
      printf(ILLEGALOPERATION);
   else
      printf("Stack %s full\n",(IsFullSTACK(stack) ? "is" : "is not"));
}

//----------------------------------------------------
void DoMenu9(STACK *stack,bool *isConstructed)
//----------------------------------------------------
{
   if ( !*isConstructed )
      printf(ILLEGALOPERATION);
   else
      printf("Stack %s empty\n",(IsEmptySTACK(stack) ? "is" : "is not"));
}
