//--------------------------------------------------------------------
// Dr. Art Hanna
// Driver to demonstrate COMPLEX ADT
// DriverComplex.c
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Complex.h"

//--------------------------------------------------------------------
int main()
//--------------------------------------------------------------------
{
   COMPLEX c1,c2,sum;
   
   ConstructComplex(&c1,1.5,-2.7);
   ConstructComplex(&c2,-3.3,4.6);
   
   AddComplex(&c1,&c2,&sum);
   
   printf("c1+c2 = ");
   DisplayComplex(&sum);
   printf("\n");
   
   printf("c1.real = %.2f\n",c1.real);
   DisplayComplex(&sum);
   printf("\n");

   DestructComplex(&c1);
   DestructComplex(&c2);
   
   printf("Press Enter to continue...");
   getchar();
}

