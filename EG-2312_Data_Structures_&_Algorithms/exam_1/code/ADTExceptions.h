//--------------------------------------------------------------
// Nick Galus
//--------------------------------------------------------------
#ifndef ADTEXCEPTIONS_H
#define ADTEXCEPTIONS_H

// ADT exception definitions
#define MALLOC_ERROR                "malloc() error"
#define DATE_ERROR                  "DATE error"
#define STACK_CAPACITY_ERROR        "STACK capacity error"
#define STACK_UNDERFLOW             "STACK underflow"
#define STACK_OVERFLOW              "STACK overflow"
#define STACK_OFFSET_ERROR          "STACK offset error"

// ADT exception-handler prototype
void RaiseADTException(const char exception[]);

#endif
