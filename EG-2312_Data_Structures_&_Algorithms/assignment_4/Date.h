//-------------------------------------------------
// Dr. Art Hanna
// Date.h
//-------------------------------------------------
#ifndef DATE_H
#define DATE_H

//==============================================================
// Data model definitions
//==============================================================
typedef struct DATE
{
   int MM;
   int DD;
   int YYYY;
   char epoch;
} DATE;

//==============================================================
// Public member function prototypes
//==============================================================
void ConstructDATE(DATE *date);
void DestructDATE(DATE *date);
void InputDATE(DATE *date,FILE *IN);
int InputDATE2(DATE *date, FILE *IN);
void OutputDATE(const DATE *date,FILE *OUT);
void OutputDATE2(const DATE *date, const char separator, FILE *OUT);
void SetMMDATE(DATE *date,const int MM);
void SetDDDATE(DATE *date,const int DD);
void SetYYYYDATE(DATE *date,const int YYYY);
void SetEpochDATE(DATE *date,const char epoch);
int GetMMDATE(const DATE *date);
int GetDDDATE(const DATE *date);
int GetYYYYDATE(const DATE *date);
char GetEpochDATE(const DATE *date);
void ConvertToStringDATE(const DATE *date,char string[]);
int IsLeapYearDATE(const DATE *date);

//===============================================
// Private utility member function prototypes
//===============================================
//(none)

#endif

