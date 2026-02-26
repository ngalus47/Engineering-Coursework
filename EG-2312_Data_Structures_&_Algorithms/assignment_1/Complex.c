//--------------------------------------------------------------------
// Dr. Art Hanna
// COMPLEX ADT function definition file
// Complex.c
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Complex.h"

//--------------------------------------------------------------------
void ConstructComplex(COMPLEX *complex,
                      const double real,const double imaginary)
//--------------------------------------------------------------------
{
   complex->real = real;
   complex->imaginary = imaginary;
}

//--------------------------------------------------------------------
void DestructComplex(COMPLEX *complex)
//--------------------------------------------------------------------
{
   ; // do nothing
}

//--------------------------------------------------------------------
double GetReal(const COMPLEX *complex)
//--------------------------------------------------------------------
{
   return( complex->real );
}

//--------------------------------------------------------------------
void SetReal(COMPLEX *complex,const double real)
//--------------------------------------------------------------------
{
   complex->real = real;
}

//--------------------------------------------------------------------
double GetImaginary(const COMPLEX *complex)
//--------------------------------------------------------------------
{
   return( complex->imaginary );
}

//--------------------------------------------------------------------
void SetImaginary(COMPLEX *complex,const double imaginary)
//--------------------------------------------------------------------
{
   complex->imaginary = imaginary;
}

//--------------------------------------------------------------------
void DisplayComplex(const COMPLEX *complex)
//--------------------------------------------------------------------
{
   printf("%.2f%+.2fi",complex->real,complex->imaginary);
}

//--------------------------------------------------------------------
void InputComplex(COMPLEX *complex)
//--------------------------------------------------------------------
{
   printf("real? ");      scanf("%lf",&complex->real);
   printf("imaginary? "); scanf("%lf",&complex->imaginary);
}

//--------------------------------------------------------------------
void AddComplex(const COMPLEX *LHS,const COMPLEX *RHS,COMPLEX *sum)
//--------------------------------------------------------------------
{
   sum->real = LHS->real+RHS->real;
   sum->imaginary = LHS->imaginary+RHS->imaginary;
}

