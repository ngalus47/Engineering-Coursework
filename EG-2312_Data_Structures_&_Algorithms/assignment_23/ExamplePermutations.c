//---------------------------------------------------------
// Dr. Art Hanna
// CS2315 Algorithms
// ExamplePermutations.c
//---------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Permutations.h"

//---------------------------------------------------------
int main()
//---------------------------------------------------------
{
   int n;
   
   printf("n? ");
   while ( scanf("%d",&n) != EOF )
   {
      PERMUTATIONS object1,object2;
      int permutation[n+1];
      int count;
      
      ConstructPermutations(&object1,n,USE_JOHNSON_TROTTER);
      ConstructPermutations(&object2,n,USE_LEXICOGRAPHIC_PERMUTE);
      FindFirstPermutation(&object1);
      FindFirstPermutation(&object2);
      count = 0;
      do
      {
         printf("%5d: ",++count);
         for (int i = 1; i <= n; i++)
            printf("%d%s",GetPermutationsElement(&object1,i),((i < n) ? "," : " - "));
         FindNextPermutation(&object1);

         GetPermutation(&object2,permutation);
         for (int i = 1; i <= n; i++)
            printf("%d%c",permutation[i],((i < n) ? ',' : '\n'));
         FindNextPermutation(&object2);

      } while ( !AtEndOfPermutations(&object1) || !AtEndOfPermutations(&object2) );
      DestructPermutations(&object1);
      DestructPermutations(&object2);
      printf("\nn? ");
   }
   
   system("PAUSE");
   return( 0 );
}
