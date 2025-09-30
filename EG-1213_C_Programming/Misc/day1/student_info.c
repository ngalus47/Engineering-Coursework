#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student *s1 = (struct Student *)malloc(sizeof(struct Student));

    if (s1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Take user input
    printf("Enter student name: ");
    scanf("%s", s1->name);
    printf("Enter age: ");
    scanf("%d", &s1->age);
    printf("Enter GPA: ");
    scanf("%f", &s1->gpa);

    // Print student details
    printf("\nStudent Info:\n");
    printf("Name: %s\n", s1->name);
    printf("Age: %d\n", s1->age);
    printf("GPA: %.2f\n", s1->gpa);

    // Free allocated memory
    free(s1);

    return 0;
}
