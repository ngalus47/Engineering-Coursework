//--------------------------------------------------------------
// Dr. Art Hanna
// DLL ADT Problem #1
// Problem1.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

#include "Random.h"
#include "DLL.h"

//--------------------------------------------------------------
int main()
//--------------------------------------------------------------
{
   void DestructElement(const void *element);
   char *NewElement();
   void DisplayDLL(const DLL *dll);
   bool InsertAlwaysAtTail(const void *LHS,const void *element,const void *RHS);
   bool InsertInAscendingOrder(const void *LHS,const void *element,const void *RHS);
   
   int pushN;

   SetRandomSeed();
   
   printf("pushN? ");
   while ( scanf("%d",&pushN) != EOF )
   {
      DLL dll;

      ConstructDLL(&dll,DestructElement);
      
      printf("\nBuild list by adding 'pushN' nodes to head, then adding some nodes to tail\n");
      for (int n = 1; n <= pushN; n++) 
         InsertDLL(&dll,0,NewElement());
      for (int n = 1; n <= pushN; n++)
         if ( RandomBool(0.5) ) InsertDLL2(&dll,NewElement(),InsertAlwaysAtTail);
      DisplayDLL(&dll);

      printf("\nEmpty list by randomly-choosing node to delete one-at-a-time\n");
      while ( GetSizeDLL(&dll) != 0 )
      {
         int offset = RandomInt(0,GetSizeDLL(&dll)-1);
         
         printf("delete %3s ",(char *) PeekDLL(&dll,offset));
         DeleteDLL(&dll,offset);
         DisplayDLL(&dll);
      }
      
      printf("\nBuild list adding pushN nodes in lexicographic order\n");
      ClearDLL(&dll);
      for (int n = 1; n <= pushN; n++)
      {
         InsertDLL2(&dll,NewElement(),InsertInAscendingOrder);
         DisplayDLL(&dll);
      }
      DestructDLL(&dll);
      
      printf("\npushN? ");
   }

   system("PAUSE");
   return( 0 );
}

//--------------------------------------------------------------
char *NewElement()
//--------------------------------------------------------------
{
   const char ALPHABET[] = "ABCDEFGHIJKLM" "NOPQRSTUVWXYZ";

   int len = RandomInt(1,3);
   char *element = (char *) malloc(sizeof(char)*(len+1));

   for (int i = 0; i <= len-1; i++)
      element[i] = RandomChar(ALPHABET,26);
   element[len] = '\0';
   return( element );
}

//--------------------------------------------------------------
bool InsertAlwaysAtTail(const void *LHS,const void *element,const void *RHS)
//--------------------------------------------------------------
{
   return( RHS == NULL );

/*
   or the functional-equivalent
   return( false );
*/
}

//--------------------------------------------------------------
bool InsertInAscendingOrder(const void *LHS,const void *element,const void *RHS)
//--------------------------------------------------------------
{
/*
   Without the (const char *) casts below, student Mirsab Zar (SP2021) mentioned that
       his IDE's compiler "complained" about datatype incompatibility as follows
       
       [Error] invalid conversion from 'const void*' to 'const char*' [-fpermissive].
       
       Dr. Hanna's Dev-C++ 5.11 compiler did not diagnose a syntax error when his code
       was written without the casts. Such care on the part of the compiler is
       probably the result of software security concerns. Interesting!?
*/
   if ( RHS == NULL ) return( true );
   return ( strcmp((const char *) element,(const char *) RHS) <= 0 );

/*
   or the functional-equivalent
   return ( (RHS == NULL) || (strcmp((const char *) element,(const char *) RHS <= 0) );
*/
}

//--------------------------------------------------------------
void DisplayDLL(const DLL *dll)
//--------------------------------------------------------------
{
   printf("(%2d): ",GetSizeDLL(dll));
   
   if ( GetSizeDLL(dll) == 0 )
      printf("(empty)\n");
   else
   {
      int UB = GetSizeDLL(dll)-1;
      
      for (int offset = 0; offset <= UB; offset++)
         printf("%s%c",PeekDLL(dll,offset),(offset == UB) ? '\n' : ' ');
   }
}

//--------------------------------------------------------------
void DestructElement(const void *element)
//--------------------------------------------------------------
{
   free((void *) element);
}

