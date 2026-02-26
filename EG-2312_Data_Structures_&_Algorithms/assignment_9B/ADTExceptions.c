//--------------------------------------------------------------
// Dr. Art Hanna
// ADTExceptions.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ADTExceptions.h"

//--------------------------------------------------------------
void RaiseADTException(const char exception[])
//--------------------------------------------------------------
{
   fprintf(stderr,"\a\nException \"%s\"\n\n",exception);

#ifdef _WIN32
   system("PAUSE");
#else
   getchar();
#endif

   exit( 1 );
}
