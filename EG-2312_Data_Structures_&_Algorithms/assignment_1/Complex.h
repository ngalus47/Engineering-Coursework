//--------------------------------------------------------------------
// Dr. Art Hanna
// COMPLEX ADT header file
// Complex.h
//--------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef COMPLEX_H
#define COMPLEX_H

//===============================================
// data model
//===============================================
typedef struct COMPLEX
{
   double real;
   double imaginary;
} COMPLEX;

//===============================================
// public member functions
//===============================================
void ConstructComplex(COMPLEX *complex,
                      const double real,const double imaginary);
void DestructComplex(COMPLEX *complex);
double GetReal(const COMPLEX *complex);
void SetReal(COMPLEX *complex,const double real);
double GetImaginary(const COMPLEX *complex);
void SetImaginary(COMPLEX *complex,const double imaginary);
void DisplayComplex(const COMPLEX *complex);
void InputComplex(COMPLEX *complex);
void AddComplex(const COMPLEX *LHS,const COMPLEX *RHS,COMPLEX *sum);

//===============================================
// Private utility member function prototypes
//===============================================
//(none)

#endif

