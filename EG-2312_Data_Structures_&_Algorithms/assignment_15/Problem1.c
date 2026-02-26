//--------------------------------------------------------------
// Dr. Art Hanna
// VECTOR ADT Problem #1
// Problem1.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Vector.h"

//--------------------------------------------------------------
int main()
//--------------------------------------------------------------
{
   void DestructDouble(const void *element);
   void DisplayVector(const VECTOR *vector);

   int LB,UB;

   printf("LB? ");
   while ( scanf("%d",&LB) != EOF )
   {
      VECTOR vector;
      int index;

      printf("UB? "); scanf("%d",&UB);
      ConstructVECTOR(&vector,LB,UB,DestructDouble);
      DisplayVector(&vector);

      printf("\nSet VECTOR elements...\n");
      printf("   index? ");
      while ( scanf("%d",&index) != EOF )
      {
         double *element = (double *) malloc(sizeof(double));

         printf("   vector[%3d]? ",index); scanf("%lf",element);
         SetVECTOR(&vector,index,element);
         printf("   index? ");
      }
      DisplayVector(&vector);

      printf("\nGet VECTOR elements...\n");
      printf("   index? ");
      while ( scanf("%d",&index) != EOF )
      {
         if ( GetVECTOR(&vector,index) == NOOBJECT )
            printf("   vector[%3d] = NOOBJECT\n",index);
         else
            printf("   vector[%3d] = %lf\n",index,*((double *) GetVECTOR(&vector,index)));
         printf("   index? ");
      }

      DestructVECTOR(&vector);
      printf("\nLB? ");
   }
   system("PAUSE");
   return( 0 );
}

//--------------------------------------------------------------
void DestructDouble(const void *element)
//--------------------------------------------------------------
{
   free((double *) element);
}

//--------------------------------------------------------------
void DisplayVector(const VECTOR *vector)
//--------------------------------------------------------------
{
   int index;

   printf("LB = %3d, UB = %3d, size = %d\n",
      GetLBVECTOR(vector),GetUBVECTOR(vector),GetSizeVECTOR(vector));
   for (index = GetLBVECTOR(vector); index <= GetUBVECTOR(vector); index++)
      if ( GetVECTOR(vector,index) == NOOBJECT )
         printf("vector[%3d] = NOOBJECT\n",index);
      else
         printf("vector[%3d] = %lf\n",index,*((double *) GetVECTOR(vector,index)));
}

