#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter size of array: ");
    scanf("%d", &N);

    // Allocate memory for N integers
    int *arr = (int *)calloc(N, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    // Free allocated memory
    free(arr);

    return 0;
}
