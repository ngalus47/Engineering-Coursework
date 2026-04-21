//---------------------------------------------------------
// Dr. Art Hanna
// Problem #67
// Problem67.c
//---------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//=========================================================
// The C99 standard added a boolean (true/false) type named "_Bool" which is defined
//    in <stdbool.h>. C99 requires a macro to alias the type as "bool" and also
//    requires macros for the literal bool constants "true" and "false". You should
//    check the header file out!
//=========================================================
#include <stdbool.h>

#include <ctype.h>

//=========================================================
// Parameterized macro (*NOTE* Clearly, parameter names do not make a difference!)
//=========================================================
#define DISPLAYPATH(ABCD,Z)           \
{                                     \
   if ( Z == 0 )                      \
      printf("(empty)\n");            \
   else                               \
   {                                  \
      printf("( (root),");            \
      for (int i = 1; i <= Z-1; i++)  \
         printf("%d,",ABCD[i]);       \
      printf("%d )\n",ABCD[Z]);       \
   }                                  \
}
//=========================================================

//---------------------------------------------------------
int main()
//---------------------------------------------------------
{
   void BuildPSST(const int n,int path[],const int m,int *count,
                   const bool displayPartialPaths);

   int n;
   char YOrN;
   
   printf("n? ");
   while ( scanf("%d",&n) != EOF )
   {
      int count = 0;
      int path[n+1];
      
      printf("Display partial paths [Y,N]? "); scanf(" %c",&YOrN);
      BuildPSST(n,path,0,&count,(toupper(YOrN)== 'Y'));
      printf("count = %4d\n",count);
      printf("n? ");
   }
   
   system("PAUSE");
   return( 0 );
}

//---------------------------------------------------------
void BuildPSST(const int n,int path[],const int m,int *count,
               const bool displayPartialPaths)
//---------------------------------------------------------
{
   void DisplayFullPath(const int m,const int path[],const bool displayPartialPaths);
   
   if ( m == n )
   {
      DisplayFullPath(m,path,displayPartialPaths);
      *count += 1;
   }
   else
   {
      if ( displayPartialPaths )
      {
         printf("%*c>m = %d ",2*m+1,' ',m); DISPLAYPATH(path,m)
      }
      for (int i = 1; i <= n; i++)
      {
         path[m+1] = i;
         BuildPSST(n,path,(m+1),count,displayPartialPaths);
      }
   }
}

//---------------------------------------------------------
void DisplayFullPath(const int m,const int path[],const bool displayPartialPaths)
//---------------------------------------------------------
{
   if ( displayPartialPaths ) printf("%*c m = %d ",2*m+1,' ',m);
   printf("[ (root),");
   for (int i = 1; i <= m-1; i++)
      printf("%d,",path[i]);
   printf("%d ]\n",path[m]);
}
