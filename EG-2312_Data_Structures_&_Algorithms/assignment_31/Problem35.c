//---------------------------------------------------
// Dr. Art Hanna
// Problem #35
// Problem35.c
//---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <assert.h>

// Inline Random.h for portability
#include <time.h>
static void SetRandomSeed() { srand((unsigned int)time(NULL)); }
static int RandomInt(int LB, int UB) { return LB + rand() % (UB - LB + 1); }

#define TRACE_MERGESORT

//---------------------------------------------------
int main()
//---------------------------------------------------
{
   void DoMergeSort(FILE *DATA,const int n);
   void DisplayFile(FILE *DATA,const int n);
   void DoBinarySearch(const int datum,FILE *AFILE,const int L,const int R,
                       bool *found,int *record,int *numberCompares);

   int n,LB,UB;
   FILE *AFILE;
                  
   printf("n? ");  scanf("%d",&n);
   printf("LB? "); scanf("%d",&LB);
   printf("UB? "); scanf("%d",&UB);

// Build binary file contents with n randomly-chosen integers from the interval [ LB,UB ]
   SetRandomSeed();
   AFILE = fopen("AFile.dat","w+b");

   assert( AFILE != NULL );

   for (int i = 0; i <= (n-1); i++)
   {
      int datum = RandomInt(LB,UB);
      
      fwrite(&datum,sizeof(int),1,AFILE);
   }

// Merge-sort AFILE
   printf("Unsorted: "); DisplayFile(AFILE,n);
   DoMergeSort(AFILE,n);
   printf("  Sorted: "); DisplayFile(AFILE,n);

// Use BinarySearch() algorithm to search sorted binary file for *EVERY* datum in [ LB,UB ]
   {
      for (int datum = LB; datum <= UB; datum++)
      {
         bool found;
         int record,numberCompares;

         numberCompares = 0;
         DoBinarySearch(datum,AFILE,0,n-1,&found,&record,&numberCompares);
         if ( found )
            printf("%5d compares: %5d found at record %5d\n",numberCompares,datum,record);
         else
            printf("%5d compares: %5d not found\n",numberCompares,datum);
      }
   }

   fclose(AFILE);

   system("PAUSE");
   return( 0 );
}

//---------------------------------------------------
void DoMergeSort(FILE *DATA,const int n)
//---------------------------------------------------
{
   void Merge(FILE *BFILE,const int p,FILE *CFILE,const int q,FILE *AFILE);
   void CopyFile(FILE *SFILE,const int L,const int R,FILE *TFILE);

   static int suffix = 0;

#if defined(TRACE_MERGESORT)
   printf("Sort %5d records in FILE *%p\n",n,DATA);
#endif

   if ( n > 1 )
   {
      char BFileName[80+1];
      FILE *BFILE;
      char CFileName[80+1];
      FILE *CFILE;
      int s = (int) floor(n/2);

      suffix++;
      sprintf(BFileName,"BFile%d.dat",suffix);
      BFILE = fopen(BFileName,"w+b");

      assert( BFILE != NULL );

      CopyFile(DATA,0,s-1,BFILE);
      sprintf(CFileName,"CFile%d.dat",suffix);
      CFILE = fopen(CFileName,"w+b");

      assert( CFILE != NULL );

      CopyFile(DATA,s,n-1,CFILE);

#ifdef TRACE_MERGESORT
   printf("%s (FILE *%p) contains %5d records\n",BFileName,BFILE,(s-1)-0+1);
   printf("%s (FILE *%p) contains %5d records\n",CFileName,CFILE,(n-1)-s+1);
#endif

      DoMergeSort(BFILE,(s-1)-0+1);
      DoMergeSort(CFILE,(n-1)-s+1);
      Merge(BFILE,(s-1)-0+1,CFILE,(n-1)-s+1,DATA);
      fclose(BFILE); remove(BFileName);
      fclose(CFILE); remove(CFileName);
   }
}

//---------------------------------------------------
void CopyFile(FILE *SFILE,const int L,const int R,FILE *TFILE)
//---------------------------------------------------
{
   void SET(FILE *DATA,const int record,const int datum);
   int GET(FILE *DATA,const int record);

   for (int record = L; record <= R; record++)
      SET(TFILE,record-L,GET(SFILE,record));
}

//---------------------------------------------------
void Merge(FILE *BFILE,const int p,FILE *CFILE,const int q,FILE *AFILE)
//---------------------------------------------------
/*
   Merge the p records in BFILE (indices 0..p-1) and the q records in CFILE
   (indices 0..q-1) into AFILE (indices 0..p+q-1) in ascending order.
   Based on the Merge() algorithm from textbook Section 5.2, page 172.
*/
{
   void SET(FILE *DATA,const int record,const int datum);
   int GET(FILE *DATA,const int record);

   int i = 0;   // index into BFILE
   int j = 0;   // index into CFILE
   int k = 0;   // index into AFILE

   // Main merge loop: while both halves have remaining elements
   while ( i < p && j < q )
   {
      if ( GET(BFILE,i) <= GET(CFILE,j) )
      {
         SET(AFILE,k,GET(BFILE,i));
         i++;
      }
      else
      {
         SET(AFILE,k,GET(CFILE,j));
         j++;
      }
      k++;
   }

   // Copy remaining elements from BFILE if any
   while ( i < p )
   {
      SET(AFILE,k,GET(BFILE,i));
      i++;
      k++;
   }

   // Copy remaining elements from CFILE if any
   while ( j < q )
   {
      SET(AFILE,k,GET(CFILE,j));
      j++;
      k++;
   }
}

//---------------------------------------------------
void DisplayFile(FILE *DATA,const int n)
//---------------------------------------------------
{
   int GET(FILE *DATA,const int record);

   for (int i = 0; i <= n-1; i++)
      printf("%5d",GET(DATA,i));
   printf("\n");
}

//---------------------------------------------------
void SET(FILE *DATA,const int record,const int datum)
//---------------------------------------------------
{
   fseek(DATA,record*sizeof(int),SEEK_SET);
   fwrite(&datum,sizeof(int),1,DATA);
}

//---------------------------------------------------
int GET(FILE *DATA,const int record)
//---------------------------------------------------
{
   int datum;

   fseek(DATA,record*sizeof(int),SEEK_SET);
   fread(&datum,sizeof(int),1,DATA);
   return( datum );
}

//---------------------------------------------------
void DoBinarySearch(const int datum,FILE *DATA,const int L,const int R,
                    bool *found,int *record,int *numberCompares)
//---------------------------------------------------
{
   if ( L > R )
      *found = false;
   else
   {
      *record = (L+R)/2;
      *numberCompares += 1;
      if      ( datum  < GET(DATA,*record) )  
         DoBinarySearch(datum,DATA,L,*record-1,found,record,numberCompares);
      else if ( datum == GET(DATA,*record) )
         *found = true;
      else // if ( datum > GET(DATA,*record) )
         DoBinarySearch(datum,DATA,*record+1,R,found,record,numberCompares);
   }
}
