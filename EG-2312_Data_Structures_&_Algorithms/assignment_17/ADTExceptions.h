
//--------------------------------------------------------------
// Dr. Art Hanna
// ADTExceptions.h
//--------------------------------------------------------------
#ifndef ADTEXCEPTIONS_H
#define ADTEXCEPTIONS_H
// ADT exception definitions
#define MALLOC_ERROR "malloc() error"
#define IO_ERROR "IO error"
#define CALLBACK_FUNCTION_ERROR "Call-back function pointer may not be NULL"
#define DATE_ERROR "DATE error"
#define STACK_CAPACITY_ERROR "STACK capacity error"
#define STACK_UNDERFLOW "STACK underflow"
#define STACK_OVERFLOW "STACK overflow"
#define STACK_OFFSET_ERROR "STACK offset error"
#define SLL_UNDERFLOW "SLL underflow"
#define SLL_OFFSET_ERROR "SLL offset error"
#define VECTOR_BOUNDS_ERROR "VECTOR bounds error"
#define VECTOR_INDEX_ERROR "VECTOR index error"
#define DLL_UNDERFLOW "DLL underflow"
#define DLL_OFFSET_ERROR "DLL offset error"
#define QUEUE_UNDERFLOW "QUEUE underflow"
#define BT_NULL_POINTER_ERROR "BT NULL pointer error"
#define DIGRAPH_VERTEXID_ERROR "DIGRAPH vertex ID error"
#define VECTOR_BOUNDS_ERROR         "VECTOR bounds error"
#define VECTOR_INDEX_ERROR          "VECTOR index error"
#define IO_ERROR                    "IO error"
#define BT_NULL_POINTER_ERROR       "BT NULL pointer error"
// ADT exception-handler prototype
void RaiseADTException(const char exception[]);
#endif

