#include <stdio.h>
#include <stdlib.h>

void stack_allocation() {
    int stack_var = 42;  // Allocated on the stack
    printf("Stack variable: %d at %p\n", stack_var, &stack_var);
}

void heap_allocation() {
    int *heap_var = (int *)malloc(sizeof(int));  // Allocated on the heap
    *heap_var = 99;
    printf("Heap variable: %d at %p\n", *heap_var, heap_var);
    free(heap_var);  // Don't forget to free!
}

int main() {
    stack_allocation();
    heap_allocation();
    return 0;
}
