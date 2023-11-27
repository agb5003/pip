#include <stdio.h>
/* prototype declaration */
void swap(int *x, int *y);

int main() {
    int a, b;
    // Input
    printf("Enter 2 integers separated by a space: ");
    scanf("%d %d", &a, &b);
    // Exchange the contents
    swap(&a, &b);
    // Display results
    printf("%d %d\n", a, b);
    return 0;
}

// Use method explained in report 5-2 to swap values
void swap(int *x, int *y) {
    *x += *y;
    *y = *x - *y;
    *x -= *y;
}

