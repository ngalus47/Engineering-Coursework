//--------------------------------------------------
// Dr. Art Hanna
// Problem #25
// Problem25.c
//--------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <assert.h>

// #include "..\Random.h"
// Inline Random.h contents for portability:
#include <time.h>
static void SetRandomSeed() { srand((unsigned int)time(NULL)); }
static double RandomDouble() { return (double)rand() / ((double)RAND_MAX + 1.0); }

#define SIZEX 100.0
#define SIZEY 100.0

typedef struct POINT
{
   double x;
   double y;
} POINT;

typedef struct SEGMENT
{
   POINT p1;
   POINT p2;
} SEGMENT;

//--------------------------------------------------
int main()
//--------------------------------------------------
{
   void FindConvexHull(const POINT points[], const int n, SEGMENT segments[], int *s);
   void BuildOUTFile(const POINT points[], const int n, const SEGMENT segments[], const int s);

   int n, s;
   POINT *points;
   SEGMENT *segments;

   printf("n? "); scanf("%d", &n);
   points   = (POINT *)   malloc(sizeof(POINT)   * (n + 1));
   segments = (SEGMENT *) malloc(sizeof(SEGMENT) * (n + 1));

   SetRandomSeed();

   // Choose n random points
   for (int i = 1; i <= n; i++)
   {
      points[i].x = floor((RandomDouble() * SIZEX) * 10) / 10;
      points[i].y = floor((RandomDouble() * SIZEY) * 10) / 10;
   }

   // Find line segments that make up convex hull
   FindConvexHull(points, n, segments, &s);

   assert(s <= n);

   // Build output file
   BuildOUTFile(points, n, segments, s);

   free(points);
   free(segments);

   system("PAUSE");
   return (0);
}

//--------------------------------------------------
void FindConvexHull(const POINT points[], const int n, SEGMENT segments[], int *s)
//--------------------------------------------------
/*
   Algorithm (Levitin textbook, pp. 111-112):
   For every pair of points (p_i1, p_i2), form the line through them.
   The line equation is:   ax + by - c = 0
   where:
      a = points[i2].y - points[i1].y
      b = points[i1].x - points[i2].x
      c = points[i1].x * (points[i2].y - points[i1].y)
        - points[i1].y * (points[i1].x - points[i2].x)
        (i.e., a*x1 + b*y1)

   The segment (p_i1, p_i2) is part of the convex hull iff all other
   n-2 points lie entirely on one side of the line (or on it):
      - positive side count == 0  OR  negative side count == 0
*/
{
   *s = 0;

   for (int i1 = 1; i1 <= n - 1; i1++)
   {
      for (int i2 = i1 + 1; i2 <= n; i2++)
      {
         // Coefficients of the line through points[i1] and points[i2]
         double a = points[i2].y - points[i1].y;
         double b = points[i1].x - points[i2].x;
         double c = a * points[i1].x + b * points[i1].y;

         int positiveCount = 0;
         int negativeCount = 0;

         // Check all other n-2 points
         for (int i3 = 1; i3 <= n; i3++)
         {
            if ((i3 != i1) && (i3 != i2))
            {
               double val = a * points[i3].x + b * points[i3].y - c;

               if (val > 0.0)
                  positiveCount++;
               else if (val < 0.0)
                  negativeCount++;
               // val == 0.0 means collinear; ignored per the problem note
            }
         }

         // Segment is on the convex hull iff all other points are on one side
         if (positiveCount == 0 || negativeCount == 0)
         {
            (*s)++;

            // Safety assertion: s must never exceed n (segments[] has n+1 elements)
            assert(*s <= n);

            segments[*s].p1 = points[i1];
            segments[*s].p2 = points[i2];
         }
      }
   }
}

//--------------------------------------------------
void BuildOUTFile(const POINT points[], const int n, const SEGMENT segments[], const int s)
//--------------------------------------------------
{
   FILE *OUT;

   OUT = fopen("Problem25.out", "w");
   fprintf(OUT, "%5.1f %5.1f\n", SIZEX, SIZEY);
   fprintf(OUT, "%4d\n", n);
   for (int i = 1; i <= n; i++)
      fprintf(OUT, "%5.1f %5.1f\n", points[i].x, points[i].y);
   fprintf(OUT, "%4d\n", s);
   for (int i = 1; i <= s; i++)
   {
      fprintf(OUT, "%5.1f %5.1f  ", segments[i].p1.x, segments[i].p1.y);
      fprintf(OUT, "%5.1f %5.1f\n", segments[i].p2.x, segments[i].p2.y);
   }
   fclose(OUT);
}
