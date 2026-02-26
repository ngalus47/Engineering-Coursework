//--------------------------------------------------------------
// Dr. Art Hanna
// DLL ADT Problem #2
// Problem2.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

#include "Random.h"
#include "DLL2.h"

#define MAXLEN 3

//--------------------------------------------------------------
int main()
//--------------------------------------------------------------
{
   void DestructElement(const void *element);
   char *NewElement();
   void DisplayDLL(const DLL *dll,const bool headToTail);
   void WriteDLLToDiskFile(const DLL *dll);   
   void ReadDLLFromDiskFile(DLL *dll);

   int pushN;

   SetRandomSeed();
   
   printf("pushN? ");
   while ( scanf("%d",&pushN) != EOF )
   {
      DLL dll;

      ConstructDLL(&dll,DestructElement);
      
      printf("\nBuild list by adding 'pushN' nodes to head\n");
      for (int n = 1; n <= pushN; n++) InsertDLL(&dll,0,NewElement());
      DisplayDLL(&dll,true);

      printf("\nStore list in file \"Problem2.dll\"\n");
      WriteDLLToDiskFile(&dll);

      printf("\nLoad list from file \"Problem2.dll\"\n");
      ReadDLLFromDiskFile(&dll);
      DisplayDLL(&dll,true);
      DisplayDLL(&dll,false);

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

   int len = RandomInt(1,MAXLEN);
   char *element = (char *) malloc(sizeof(char)*(MAXLEN+1));

   for (int i = 0; i <= len-1; i++)
      element[i] = RandomChar((char *) ALPHABET,26);
   element[len] = '\0';
   return( element );
}

//--------------------------------------------------------------
void DisplayDLL(const DLL *dll,const bool headToTail)
//--------------------------------------------------------------
{
   void DisplayElement(void *element);
   
   printf("%s (%2d): ",(headToTail) ? "HtoT" : "TtoH",GetSizeDLL(dll));
   
   if ( GetSizeDLL(dll) == 0 )
      printf("(empty)");
   else
      if ( headToTail )
         TraverseFromHeadToTailDLL(dll,DisplayElement);
      else
         TraverseFromTailToHeadDLL(dll,DisplayElement);
   printf("\n");
}

//--------------------------------------------------------------
void DisplayElement(void *element)
//--------------------------------------------------------------
{
   printf("%s ",(char *) element);
}

//--------------------------------------------------------------
void WriteDLLToDiskFile(const DLL *dll)
//--------------------------------------------------------------
{
   void WriteElement(FILE *OUT,const void *element);

   FILE *OUT;

   if ( (OUT = fopen("Problem2.dll","wb")) == NULL )
   {
      printf("Unable to open file!\n");
      system("PAUSE");
      exit( 1 );
   }
   StoreDLL(OUT,dll,WriteElement);
   fclose(OUT);
}

//--------------------------------------------------------------
void WriteElement(FILE *OUT,const void *element)
//--------------------------------------------------------------
{
   fwrite(element,sizeof(char)*(MAXLEN+1),1,OUT);
}

//--------------------------------------------------------------
void ReadDLLFromDiskFile(DLL *dll)
//--------------------------------------------------------------
{
   void ReadElement(FILE *IN,void **element);
   void DestructElement(const void *element);

   FILE *IN;

   if ( (IN = fopen("Problem2.dll","rb")) == NULL )
   {
      printf("Unable to open file!\n");
      system("PAUSE");
      abort();
   }
   LoadDLL(IN,dll,ReadElement,DestructElement);
   fclose( IN);
}

//--------------------------------------------------------------
void ReadElement(FILE *IN,void **element)
//--------------------------------------------------------------
{
   *element = (void *) malloc(sizeof(char)*4);
   
   if ( *element == NULL )
   {
      printf("\a\nmalloc() error\n\n");
      system("PAUSE");
      exit( 1 );
   }
   fread(*element,sizeof(char)*(MAXLEN+1),1,IN);
}

//--------------------------------------------------------------
void DestructElement(const void *element)
//--------------------------------------------------------------
{
   free((void *) element);
}

