//---------------------------------------------------------
// Nicholas Galus
// Problem #40
// Problem40.c
//---------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Permutations.h"

//---------------------------------------------------------
bool IsSolution(const int P[]);
//---------------------------------------------------------
void DisplaySolution(const int P[]);

//---------------------------------------------------------
int main()
//---------------------------------------------------------
{
   PERMUTATIONS object;
   int countPermutations,countSolutions;

   int P[10+1];   // P[1..10]

   ConstructPermutations(&object,10,USE_LEXICOGRAPHIC_PERMUTE);
   FindFirstPermutation(&object);

   countPermutations = 0;
   countSolutions = 0;

   //--------------------------------------------------
   // Generate all permutations
   //--------------------------------------------------
   while ( !AtEndOfPermutations(&object) )
   {
      //--------------------------------------------------
      // Map permutation → P[1..10]
      // ADT uses 1..10 → convert to 0..9
      //--------------------------------------------------
      for (int i = 1; i <= 10; i++)
         P[i] = GetPermutationsElement(&object,i) - 1;

      //--------------------------------------------------
      // Count every permutation
      //--------------------------------------------------
      countPermutations++;

      //--------------------------------------------------
      // Check if it works
      //--------------------------------------------------
      if ( IsSolution(P) )
      {
         countSolutions++;
         DisplaySolution(P);
      }

      //--------------------------------------------------
      // Move to next permutation
      //--------------------------------------------------
      FindNextPermutation(&object);
   }

   printf("\n%10d permutations checked, %10d solutions found (%9.5f%%)\n",
      countPermutations,
      countSolutions,
      100*((double) countSolutions/countPermutations));

   DestructPermutations(&object);

   return 0;
}

//---------------------------------------------------------
bool IsSolution(const int P[])
//---------------------------------------------------------
{
   int R1,R2,R3;

   /*
      Mapping:

         P[7]    5 P[3] P[1]
     +   P[8] P[6] P[4]    5
     =======================
   P[10] P[9]    6 P[5] P[2]
   */

   //--------------------------------------------------
   // Build each row as integers
   //--------------------------------------------------
   R1 = P[7]*1000 + 5*100 + P[3]*10 + P[1];
   R2 = P[8]*1000 + P[6]*100 + P[4]*10 + 5;
   R3 = P[10]*10000 + P[9]*1000 + 6*100 + P[5]*10 + P[2];

   //--------------------------------------------------
   // Check equation
   //--------------------------------------------------
   return ( (R1 + R2) == R3 );
}

//---------------------------------------------------------
void DisplaySolution(const int P[])
//---------------------------------------------------------
{
   printf("%d%d%d%d",          P[7],   5,P[3],P[1]);
   printf(" + %d%d%d%d",       P[8],P[6],P[4],   5);
   printf(" = ");
   printf("%d%d%d%d%d\n",P[10],P[9],   6,P[5],P[2]);
}
