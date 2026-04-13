//--------------------------------------------------
// Nick Galus 
// Problem #22
// Problem22.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#define MAXFACTORS 512

typedef struct FACTORIZATION
{
   int size;
   int factor[MAXFACTORS + 1];
   int exponent[MAXFACTORS + 1];
} FACTORIZATION;

// Function prototypes
int GCD1(int m,int n);
int GCD2(const int m,const int n);
int GCD3(const int m,const int n);
int GCD4(const int m,const int n);

void FindFactorization(int x,FACTORIZATION *factorization);
void DisplayFactorization(const int x,const FACTORIZATION factorization);
int NextPrime(int x);
bool IsPrime(const int x);

//--------------------------------------------------
int main()
//--------------------------------------------------
{
   int m,n;

   printf("m? ");
   while (scanf("%d",&m) != EOF)
   {
      printf("n? ");
      scanf("%d",&n);

      // Inputs must be nonnegative
      assert((m >= 0) && (n >= 0));

      printf("GCD1(m,n) = %d\n",GCD1(m,n));

      // GCD2 and GCD3 require both values to be nonzero
      if ((m != 0) && (n != 0))
      {
         printf("GCD2(m,n) = %d\n",GCD2(m,n));
         printf("GCD3(m,n) = %d\n",GCD3(m,n));
      }
      else
      {
         printf("GCD2(m,n) = undefined for zero input\n");
         printf("GCD3(m,n) = undefined for zero input\n");
      }

      printf("GCD4(m,n) = %d\n",GCD4(m,n));
      printf("m? ");
   }

   return 0;
}

//--------------------------------------------------
int GCD1(int m,int n)
//--------------------------------------------------
{
   int r;

   // At least one value must be nonzero
   assert((m != 0) || (n != 0));

   // Iterative Euclid's Algorithm
   while (n != 0)
   {
      r = m % n;
      m = n;
      n = r;
   }

   return m;
}

//--------------------------------------------------
int GCD2(const int m,const int n)
//--------------------------------------------------
{
   int t;

   // Both values must be nonzero
   assert((m != 0) && (n != 0));

   // Start from the smaller value
   if (m < n)
      t = m;
   else
      t = n;

   // Work downward until a common divisor is found
   while (t > 0)
   {
      if ((m % t == 0) && (n % t == 0))
         return t;

      t--;
   }

   return 1;
}

//--------------------------------------------------
int GCD3(const int m,const int n)
//--------------------------------------------------
{
   FACTORIZATION mFactorization;
   FACTORIZATION nFactorization;
   int r,mi,ni;

   // Both values must be nonzero
   assert((m != 0) && (n != 0));

// Step 1.
   FindFactorization(m,&mFactorization);
   DisplayFactorization(m,mFactorization);

// Step 2.
   FindFactorization(n,&nFactorization);
   DisplayFactorization(n,nFactorization);

// Steps 3 and 4.
   r = 1;
   mi = 1;
   ni = 1;

   while ((mi <= mFactorization.size) && (ni <= nFactorization.size))
   {
      if (mFactorization.factor[mi] == nFactorization.factor[ni])
      {
         int minExponent;

         if (mFactorization.exponent[mi] < nFactorization.exponent[ni])
            minExponent = mFactorization.exponent[mi];
         else
            minExponent = nFactorization.exponent[ni];

         for (int i = 1; i <= minExponent; i++)
            r *= mFactorization.factor[mi];

         mi++;
         ni++;
      }
      else if (mFactorization.factor[mi] < nFactorization.factor[ni])
         mi++;
      else
         ni++;
   }

   return r;
}

//--------------------------------------------------
void FindFactorization(int x,FACTORIZATION *factorization)
//--------------------------------------------------
{
   int prime;

   factorization->size = 0;

   // Include 1 as shown in the example format
   factorization->size++;
   factorization->factor[factorization->size] = 1;
   factorization->exponent[factorization->size] = 1;

   prime = 2;

   // Keep dividing out prime factors until x becomes 1
   while (x > 1)
   {
      if ((x % prime) == 0)
      {
         factorization->size++;
         factorization->factor[factorization->size] = prime;
         factorization->exponent[factorization->size] = 0;

         while ((x % prime) == 0)
         {
            factorization->exponent[factorization->size]++;
            x /= prime;
         }
      }

      prime = NextPrime(prime);
   }
}

//--------------------------------------------------
void DisplayFactorization(const int x,const FACTORIZATION factorization)
//--------------------------------------------------
{
   printf("%d = ",x);

   for (int i = 1; i <= factorization.size; i++)
   {
      printf("%d",factorization.factor[i]);

      if (factorization.exponent[i] > 1)
         printf("^%d",factorization.exponent[i]);

      if (i < factorization.size)
         printf("*");
      else
         printf("\n");
   }
}

//--------------------------------------------------
int NextPrime(int x)
//--------------------------------------------------
{
   do
      x++;
   while (!IsPrime(x));

   return x;
}

//--------------------------------------------------
bool IsPrime(const int x)
//--------------------------------------------------
{
   bool r = true;

   if (x < 2)
      return false;

   for (int i = 2; (i <= (int)sqrt(x)) && r; i++)
      r = r && ((x % i) != 0);

   return r;
}

//--------------------------------------------------
int GCD4(const int m,const int n)
//--------------------------------------------------
{
   // Same precondition as GCD1
   assert((m != 0) || (n != 0));

   // Recursive Euclid's Algorithm
   if (n == 0)
      return m;

   return GCD4(n,m % n);
}
