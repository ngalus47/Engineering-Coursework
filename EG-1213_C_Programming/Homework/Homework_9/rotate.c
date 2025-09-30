#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n) {
    return (i << n) | (i >> (32 - n));
}

unsigned int rotate_right(unsigned int i, int n) {
    return (i >> n) | (i << (32 - n));
}

int main() {
    unsigned int num;
    int n;
    
    printf("Enter an unsigned integer (in hexadecimal): ");
    scanf("%x", &num);
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &n);
    
    unsigned int left_rotated = rotate_left(num, n);
    unsigned int right_rotated = rotate_right(num, n);
    
    printf("Left rotated: 0x%x\n", left_rotated);
    printf("Right rotated: 0x%x\n", right_rotated);

    return 0;
}
