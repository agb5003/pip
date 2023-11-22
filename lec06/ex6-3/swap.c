#include <stdio.h>
/* prototype declaration */
void swap(int *x, int *y);

int main(void) {
    int a,b;
    /* Input 2 integers */
    printf("Enter 2 integers separated by a space: ");
    scanf("%d %d", &a, &b);
    /* Exchange the contents */
    swap(&a, &b);
    /* Display results */
    printf("%d %d\n", a, b);
    return 0;
}

void swap(int *x, int *y) {
    *x += *y;
    *y = *x - *y;
    *x -= *y;
}