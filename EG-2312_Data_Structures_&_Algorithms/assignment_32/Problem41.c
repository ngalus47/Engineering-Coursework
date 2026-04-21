//--------------------------------------------------
// Dr. Art Hanna
// Problem #41: The Integer(or Discrete) Knapsack Problem (Dynamic Programming)
// Problem41.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

// Inline Random.h (not needed here but keeping consistent)
#include <time.h>

#define F(i,j) *(table + (i)*(W+1) + (j))

#define MAXIMUM(LHS,RHS) ( ((LHS) < (RHS)) ? (RHS) : (LHS) )

#define SHOWTABLE

//--------------------------------------------------
int main()
//--------------------------------------------------
{
   void GetProblemInputs(FILE *IN,char description[],int *W,int *n,int **w,int **v);
   void FindExactSolutionUsingDynamicProgrammingAlgorithm(const int W,const int n,
                                                          const int w[],const int v[],bool knapsack[]);
   void DisplaySolution(const int W,const int n,const int w[],const int v[],const bool knapsack[]);

// problem inputs
   char description[80+1];
   int W;
   int n;
   int *w;
   int *v;
// problem output
   bool *knapsack;

   char fileName[80+1];
   FILE *IN;

   printf("Data fileName (.ikp)? ");
   while ( gets(fileName) != NULL )
   {
      strcat(fileName,".ikp");
      if ( (IN = fopen(fileName,"r")) == NULL )
      {
         printf("Error opening data file %s! Please try again...\n",fileName);
         printf("\nData fileName (.ikp)? ");
         continue;
      }
      GetProblemInputs(IN,description,&W,&n,&w,&v);
      fclose(IN);
      knapsack = (bool *) malloc((n+1)*sizeof(bool));

      FindExactSolutionUsingDynamicProgrammingAlgorithm(W,n,w,v,knapsack);
      printf("Dynamic Programming algorithm's exact solution of %s\n",description);
      DisplaySolution(W,n,w,v,knapsack);

      free(w); free(v);
      free(knapsack);
      printf("\nData fileName (.ikp)? ");
   }

   system("PAUSE");
   return( 0 );
}

//--------------------------------------------------
void GetProblemInputs(FILE *IN,char description[],int *W,int *n,int **w,int **v)
//--------------------------------------------------
{
   fgets(description,80,IN); description[ (int) strlen(description)-1 ] = '\0';
   fscanf(IN,"%d",W);
   fscanf(IN,"%d",n);
   *w = (int *) malloc((*n+1)*sizeof(int));
   *v = (int *) malloc((*n+1)*sizeof(int));
   for (int i = 1; i <= *n; i++)
      fscanf(IN,"%d%d",(*w+i),&(*v)[i]);
}

//--------------------------------------------------
void FindExactSolutionUsingDynamicProgrammingAlgorithm(const int W,const int n,
                                                       const int w[],const int v[],bool knapsack[])
//--------------------------------------------------
{
   int *table = (int *) malloc(((W+1)*(n+1))*sizeof(int));

   // Base cases: F[0,j] = 0 for all j, F[i,0] = 0 for all i
   for (int i = 0; i <= n; i++)
      F(i,0) = 0;
   for (int j = 0; j <= W; j++)
      F(0,j) = 0;

   // Fill table row by row using Equation (8.6) from the textbook:
   //   F(i,j) = max{ F(i-1,j), v[i]+F(i-1,j-w[i]) }  if j-w[i] >= 0
   //   F(i,j) = F(i-1,j)                               if j-w[i] < 0
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= W; j++)
      {
         if ( j - w[i] >= 0 )
            F(i,j) = MAXIMUM(F(i-1,j), v[i] + F(i-1,j-w[i]));
         else
            F(i,j) = F(i-1,j);
      }
   }

#ifdef SHOWTABLE
   for (int i = 0; i <= n; i++)
   {
      for (int j = 0; j <= W; j++)
         printf("%3d ",F(i,j));
      printf("\n");
   }
#endif

   // Traceback: find which items are in the optimal solution
   // Start at F(n,W) and work upward
   int j = W;
   for (int i = n; i >= 1; i--)
   {
      if ( F(i,j) != F(i-1,j) )
      {
         knapsack[i] = true;
         j = j - w[i];
      }
      else
         knapsack[i] = false;
   }
   free(table);
}

//--------------------------------------------------
void DisplaySolution(const int W,const int n,const int w[],const int v[],const bool knapsack[])
//--------------------------------------------------
{
   int Value(const int n,const bool knapsack[],const int v[]);
   int UnusedWeight(const int W,const int n,const int w[],const bool knapsack[]);

   printf("knapsack = [ ");
   for (int i = 1; i <= n; i++)
      if ( knapsack[i] ) printf("%d:(%d,%d) ",i,w[i],v[i]);
   printf("], total value = %d, unused weight %d\n",
      Value(n,knapsack,v),UnusedWeight(W,n,w,knapsack));
}

//--------------------------------------------------
int Value(const int n,const bool knapsack[],const int v[])
//--------------------------------------------------
{
   int r;

   r = 0;
   for (int i = 1; i <= n; i++)
      if ( knapsack[i] ) r += v[i];
   return( r );
}

//--------------------------------------------------
int UnusedWeight(const int W,const int n,const int w[],const bool knapsack[])
//--------------------------------------------------
{
   int r;

   r = W;
   for (int i = 1; i <= n; i++)
      if ( knapsack[i] ) r -= w[i];
   return( r );
}
