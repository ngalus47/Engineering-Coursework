//--------------------------------------------------------------
// Dr. Art Hanna
// STACK ADT: Problem #4
// Problem4.c
//--------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Random.h"

#include "Stack2.h"

typedef enum { HEAD=1,TAIL=2 } FLIP;

//--------------------------------------------------------------
int main()
//--------------------------------------------------------------
{
void RunOneTrial(const double bias,const int capacity,int *flips,int *maxSize);

   setbuf(stdout, NULL);

   double bias;

   SetRandomSeed();
   printf("bias? ");
   while ( scanf("%lf",&bias) == 1 )
   {
      int trials,capacity;
      int flipsTrials,maxSizeTrials;
      int flips,maxSize;
      int i;

      printf("capacity? ");
      if ( scanf("%d",&capacity) != 1 ) return 0;

      printf("trials? ");
      if ( scanf("%d",&trials) != 1 ) return 0;

      if ( trials <= 0 ) return 0;

      RunOneTrial(bias,capacity,&flipsTrials,&maxSizeTrials);

      for ( i = 2; i <= trials; i++ )
      {
         RunOneTrial(bias,capacity,&flips,&maxSize);
         flipsTrials += flips;
         if ( maxSize > maxSizeTrials )
            maxSizeTrials = maxSize;
      }

      printf("\nAverage flips = %8.1f, maximum size = %9d\n",
             (double)flipsTrials / trials, maxSizeTrials);

      printf("\nbias? ");
   }
}

//--------------------------------------------------------------
void RunOneTrial(const double bias,const int capacity,int *flips,int *maxSize)
//--------------------------------------------------------------
{
   FLIP CoinFlip(const double bias);
   
   STACK coinflips;
   
   ConstructSTACK(&coinflips,capacity);
   
   PushSTACK(&coinflips,HEAD);
   PushSTACK(&coinflips,TAIL);

   *flips = 0;
   *maxSize = 2;

   do
   {
      FLIP flip = CoinFlip(bias);
      (*flips)++;

      FLIP tos = (FLIP) PeekSTACK(&coinflips,0);

      if ( flip == tos )
      {
         PopSTACK(&coinflips);
      }
      else
      {
         PushSTACK(&coinflips,flip);
         if ( GetSizeSTACK(&coinflips) > *maxSize )
            *maxSize = GetSizeSTACK(&coinflips);
      }
   }
   while ( !IsEmptySTACK(&coinflips) );

   DestructSTACK(&coinflips);
}

//--------------------------------------------------------------
FLIP CoinFlip(const double bias)
//--------------------------------------------------------------
{
   return( ((double) RandomInt(1,100)/100 <= bias) ? HEAD : TAIL );
}
