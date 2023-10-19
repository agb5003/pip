#include <stdio.h>

int main() {
    int a = 0, b = 0;
    printf("Input 2 integers A and B separated by a space: ");
    scanf("%d %d", &a, &b);
    if (a % b == 0) {
        printf("B is a divisor of A\n");
    } else {
        printf("B is not a divisor of A\n");
    }
}
