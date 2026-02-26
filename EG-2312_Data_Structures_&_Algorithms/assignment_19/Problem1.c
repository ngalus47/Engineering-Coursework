//--------------------------------------------------------------
// Nick Galus
// PQUEUE ADT Problem #1
// Problem1.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>

#include "PQueue.h"
#include "Random.h"

typedef struct JOB
{
   int arrivalTime;
   int duration;
   char name[6+1];           // JOBXXX
} JOB;

//--------------------------------------------------------------
int main()
//--------------------------------------------------------------
{
   bool HasEarlierArrivalTime(const void *LHS,const void *job,const void *RHS);
   void DestructJob(const void *job);
   JOB *NewJob(const int jobNumber);
   void DisplayJob(void *job);

   int n;

   // Match sample dialog "sizeof(...)" lines
   printf("sizeof(JOB) = %d bytes\n", (int) sizeof(JOB));
   printf("sizeof(int) = %d bytes\n", (int) sizeof(int));
   printf("sizeof(char [6+1]) = %d\n\n", (int) sizeof(char [6+1]));

   SetRandomSeed();

   printf("n? ");
   while ( scanf("%d",&n) != EOF )
   {
      PQUEUE readyQ;

      ConstructPQUEUE(&readyQ,HasEarlierArrivalTime,DestructJob);

      // Add n jobs to an empty readyQ
      for (int jobNumber = 1; jobNumber <= n; jobNumber++)
         InsertPQUEUE(&readyQ,NewJob(jobNumber));

      // Display readyQ (matches sample: just the list)
      TraversePQUEUE(&readyQ,DisplayJob);

      DestructPQUEUE(&readyQ);
      printf("\nn? ");
   }

   system("PAUSE");
   return( 0 );
}

//--------------------------------------------------------------
JOB *NewJob(const int jobNumber)
//--------------------------------------------------------------
{
   JOB *job = (JOB *) malloc(sizeof(JOB));

   if ( job == NULL )
   {
      printf("\a\nmalloc() error\n\n");
      system("PAUSE");
      exit( 1 );
   }

   job->arrivalTime = RandomInt(0,100);
   job->duration = RandomInt(1,10);

   sprintf(job->name,"JOB%03d",jobNumber);
   return( job );
}

//--------------------------------------------------------------
void DisplayJob(void *job)
//--------------------------------------------------------------
{
   printf("[ \"%s\" (%5d,%3d) ]\n",
      ((JOB *) job)->name,
      ((JOB *) job)->arrivalTime,
      ((JOB *) job)->duration);
}

//--------------------------------------------------------------
bool HasEarlierArrivalTime (const void *LHS,const void *job,const void *RHS)
//--------------------------------------------------------------
{
   // Insert before RHS when job has earlier arrivalTime.
   // If RHS is NULL (end of list), always insert now.
   if ( RHS == NULL ) return true;

   return( ((JOB *) job)->arrivalTime < ((JOB *) RHS)->arrivalTime );
}

//--------------------------------------------------------------
void DestructJob(const void *job)
//--------------------------------------------------------------
{
   free((void *) job);
}
