#include <stdio.h>

unsigned short swap_bytes(unsigned short i) {
    return (i >> 8) | (i << 8);
}

int main() {
    unsigned short num;
    
    // Read a hexadecimal number (up to four digits)
    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &num);
    
    // Swap bytes and print the result
    unsigned short swapped = swap_bytes(num);
    printf("Number with bytes swapped: %hx\n", swapped);

    return 0;
}