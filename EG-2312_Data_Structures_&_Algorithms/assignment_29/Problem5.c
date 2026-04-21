//--------------------------------------------------
// Dr. Art Hanna
// Problem #5
// Problem5.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// Inline Random.h for portability
#include <time.h>
static void SetRandomSeed() { srand((unsigned int)time(NULL)); }
static int RandomInt(int LB, int UB) { return LB + rand() % (UB - LB + 1); }

//--------------------------------------------------
int main()
//--------------------------------------------------
{
   void BuildRandomArray(int A[],const int n);
   void CopyArray(int copyA[],const int A[],const int n);
   void DisplayArraySlice(const char label[],const int A[],const int n,const int L,const int R);
   int NumberOfInversions(const int A[],const int n,bool (*AreInverted)(const int LHS,const int RHS));
   void DoBubbleSort(int A[],const int n,
                     bool (*ShouldSwap)(const int LHS,const int RHS),
                     int *numberCompares,
                     int *numberMoves);
   void DoSelectionSort(int *A,const int n,
                        bool (*ShouldSelect)(const int LHS,const int RHS),
                        int *numberCompares,
                        int *numberMoves);
   void DoInsertionSort(int *A,const int n,
                        bool (*ShouldInsert)(const int LHS,const int RHS),
                        int *numberCompares,
                        int *numberMoves);
   bool Ascending(const int LHS,const int RHS);
   bool Descending(const int LHS,const int RHS);

   int n;

   SetRandomSeed();
   printf("n? ");
   while ( scanf("%d",&n) != EOF )
   {
      int *A     = (int *) malloc(sizeof(int)*n);
      int copyA[n];
      int numberCompares;
      int numberMoves;

      BuildRandomArray(A,n);
      DisplayArraySlice("Unsorted",A,n,0,n-1);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(A,n,Ascending));
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(A,n,Descending));

      CopyArray(copyA,A,n);
      DoBubbleSort(copyA,n,Ascending,&numberCompares,&numberMoves);
      DisplayArraySlice("Bubble Sort (Ascending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Ascending));

      CopyArray(copyA,A,n);
      DoBubbleSort(copyA,n,Descending,&numberCompares,&numberMoves);
      DisplayArraySlice("Bubble Sort (Descending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Descending));

      CopyArray(copyA,A,n);
      DoSelectionSort(copyA,n,Ascending,&numberCompares,&numberMoves);
      DisplayArraySlice("Selection Sort (Ascending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Ascending));

      CopyArray(copyA,A,n);
      DoSelectionSort(copyA,n,Descending,&numberCompares,&numberMoves);
      DisplayArraySlice("Selection Sort (Descending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Descending));

      CopyArray(copyA,A,n);
      DoInsertionSort(copyA,n,Ascending,&numberCompares,&numberMoves);
      DisplayArraySlice("Insertion Sort (Ascending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of  ascending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Ascending));

      CopyArray(copyA,A,n);
      DoInsertionSort(copyA,n,Descending,&numberCompares,&numberMoves);
      DisplayArraySlice("Insertion Sort (Descending)",copyA,n,0,n-1);
      printf("# of compares is %d\n",numberCompares);
      printf("# of moves    is %d\n",numberMoves);
      printf("# of descending-order inversions is %d\n",
         NumberOfInversions(copyA,n,Descending));

      free(A);
      printf("\nn? ");
   }

   system("PAUSE");
   return( 0 );
}

//--------------------------------------------------
void BuildRandomArray(int A[],const int n)
//--------------------------------------------------
{
   int i;

   for (i = 0; i <= n-1; i++)
      A[i] = RandomInt(1,10*n);
}

//--------------------------------------------------
void CopyArray(int copyA[],const int A[],const int n)
//--------------------------------------------------
{
   int i;

// for (int i = 0; i <= n-1; i++)
   i = 0;
FOR1:
   if ( !(i <= n-1) ) goto endFOR1;
      copyA[i] = A[i];
   i++;
   goto FOR1;
endFOR1:
   ; // Do nothing
}

//--------------------------------------------------
void DisplayArraySlice(const char label[],const int A[],const int n,const int L,const int R)
//--------------------------------------------------
{
   printf("\n%s\n",label);
   for (int i = 1; i <= (int) strlen(label); i++)
      printf("=");
   printf("\n");
   for (int i = 0; i <= n-1; i++)
   {
      if ( (i % 10) == 0 )
      {
         if (i != 0) printf("\n");
         printf("%5d: ",i);
      }
      if ( (L <= i) && (i <= R) )
         printf("%5d",A[i]);
      else
         printf("%5c",' ');
   }
   printf("\n");
}

//--------------------------------------------------
int NumberOfInversions(const int A[],const int n,bool (*AreInverted)(const int LHS,const int RHS))
//--------------------------------------------------
{
   int i,r;

   i = 0; r = 0;
FOR1:
   if ( !(i <= n-2) ) goto endFOR1;
      int j = i+1;
FOR2:
      if ( !(j <= n-1) ) goto endFOR2;
         if ( !AreInverted(A[i],A[j]) ) goto endIF1;
            r++;
endIF1:
      j++;
      goto FOR2;
endFOR2:
   i++;
   goto FOR1;
endFOR1:

   return( r );
}

//--------------------------------------------------
bool Ascending(const int LHS,const int RHS)
//--------------------------------------------------
{
   return( (LHS > RHS) ? true : false );
}

//--------------------------------------------------
bool Descending(const int LHS,const int RHS)
//--------------------------------------------------
{
   return( LHS < RHS );
}

//--------------------------------------------------
void DoBubbleSort(int A[],const int n,
                  bool (*ShouldSwap)(const int LHS,const int RHS),
                  int *numberCompares,
                  int *numberMoves)
//--------------------------------------------------
{
/*
   Original structured version (from textbook p.101):

   int pass;
   bool swapMade;

   pass = 1;
   *numberCompares = 0;
   *numberMoves = 0;
   do
   {
      swapMade = false;
      for (int i = 0; i <= n-(pass+1); i++)
      {
         *numberCompares += 1;
         if ( ShouldSwap(A[i],A[i+1]) )
         {
            int T = A[i]; A[i] = A[i+1]; A[i+1] = T;
            *numberMoves += 3;
            swapMade = true;
         }
      }
      pass++;
   } while ( swapMade );
*/

   int pass;
   bool swapMade;
   int i;

   pass = 1;
   *numberCompares = 0;
   *numberMoves = 0;

// do { ... } while ( swapMade );
DOWHILE1:
      swapMade = false;

//    for (int i = 0; i <= n-(pass+1); i++)
      i = 0;
FOR1:
      if ( !(i <= n-(pass+1)) ) goto endFOR1;
         *numberCompares += 1;
//       if ( ShouldSwap(A[i],A[i+1]) )
         if ( !ShouldSwap(A[i],A[i+1]) ) goto endIF1;
            int T = A[i]; A[i] = A[i+1]; A[i+1] = T;
            *numberMoves += 3;
            swapMade = true;
endIF1:
      i++;
      goto FOR1;
endFOR1:
      pass++;
   if ( swapMade ) goto DOWHILE1;
// end do/while
}

//--------------------------------------------------
void DoSelectionSort(int *A,const int n,
                     bool (*ShouldSelect)(const int LHS,const int RHS),
                     int *numberCompares,
                     int *numberMoves)
//--------------------------------------------------
{
/*
   Original structured version (from textbook p.99):

   *numberCompares = 0;
   *numberMoves = 0;
   for (int i = 0; i <= n-2; i++)
   {
      int T,select = i;

      for (int j = i+1; j <= n-1; j++)
      {
         if ( (*ShouldSelect)(A[select],A[j]) ) select = j;
         *numberCompares += 1;
      }
      T = A[i]; A[i] = A[select]; A[select] = T;
      ++*numberMoves, *numberMoves += 1, (*numberMoves)++;
   }
*/

   int i,j;

   *numberCompares = 0;
   *numberMoves = 0;

// for (int i = 0; i <= n-2; i++)
   i = 0;
FOR1:
   if ( !(i <= n-2) ) goto endFOR1;
      int T, select = i;

//    for (int j = i+1; j <= n-1; j++)
      j = i+1;
FOR2:
      if ( !(j <= n-1) ) goto endFOR2;
//       if ( (*ShouldSelect)(A[select],A[j]) ) select = j;
         if ( !(*ShouldSelect)(A[select],A[j]) ) goto endIF1;
            select = j;
endIF1:
         *numberCompares += 1;
      j++;
      goto FOR2;
endFOR2:
      T = A[i]; A[i] = A[select]; A[select] = T;
      ++*numberMoves, *numberMoves += 1, (*numberMoves)++;
   i++;
   goto FOR1;
endFOR1:
   ; // Do nothing
}

//--------------------------------------------------
void DoInsertionSort(int A[1],const int n,
                     bool (*ShouldInsert)(const int LHS,const int RHS),
                     int *numberCompares,
                     int *numberMoves)
//--------------------------------------------------
{
/*
   Original structured version (from textbook p.134):

   *numberCompares = 0;
   *numberMoves = 0;
   for (i = 1; i <= n-1; i++)
   {
      int v = A[i];
      int j = i-1;

      *numberMoves += 1;
      while ( (j >= 0) && (*ShouldInsert)(A[j],v) )
      {
         *numberCompares += 1;
         A[j+1] = A[j];
         *numberMoves += 1;
         j--;
      }
      *numberCompares += 1;
      A[j+1] = v;
      *numberMoves += 1;
   }
*/

   int i, j;

   *numberCompares = 0;
   *numberMoves = 0;

// for (i = 1; i <= n-1; i++)
   i = 1;
FOR1:
   if ( !(i <= n-1) ) goto endFOR1;
      int v = A[i];
      j = i-1;
      *numberMoves += 1;

//    while ( (j >= 0) && (*ShouldInsert)(A[j],v) )
WHILE1:
      if ( !(j >= 0) ) goto endWHILE1;
      if ( !(*ShouldInsert)(A[j],v) ) goto endWHILE1;
         *numberCompares += 1;
         A[j+1] = A[j];
         *numberMoves += 1;
         j--;
         goto WHILE1;
endWHILE1:
      *numberCompares += 1;
      A[j+1] = v;
      *numberMoves += 1;
   i++;
   goto FOR1;
endFOR1:
   ; // Do nothing
}
