//--------------------------------------------------------------
// Dr. Art Hanna
// Understanding the comma operator
// UnderstandingCommaOperator.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
   int x,y,xs[3];

   printf("----------------------------------------------------\n");
   printf("\"Playing\" with the comma operator\n");
   printf("----------------------------------------------------\n");

   x = 1,2;
   printf("After x = 1,2; x = %d\n",x);
   printf("(x = 1,2) = %d\n\n",(x = 1,2));

   x = (1,2);
   printf("After x = (1,2); x = %d\n",x);
   printf("(x = (1,2)) = %d\n\n",(x = (1,2)));
   
   x = 1,x++;
   printf("After x = 1,x++; x = %d\n",x);
   printf("(x = 1,x++) = %d\n\n",(x = 1,x++));

   printf("(x = 1,++x) = %d\n\n",(x = 1,++x));

   xs[0] = 0, xs[1] = 1, xs[2] = 2;
   printf("After xs[0] = 0, xs[1] = 1, xs[2] = 2; xs = [ %d,%d,%d ]\n\n",xs[0],xs[1],xs[2]);

   y = 0, xs[y++,y] = 5;
   printf("After y = 0, xs[y++,y] = 5; xs = [ %d,%d,%d ]\n\n",xs[0],xs[1],xs[2]);

   y = 0, xs[++y,y] = 6;
   printf("After y = 0, xs[++y,y] = 6; xs = [ %d,%d,%d ]\n\n",xs[0],xs[1],xs[2]);

   system("PAUSE");
   return( 0 );
}
