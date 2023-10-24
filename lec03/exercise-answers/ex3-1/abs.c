#include <stdio.h>

int main() {
    float n = 0;
    printf("Enter the number you would like the absolute value of: ");
    scanf("%f", &n);
    if (n < 0) { // if n is negative, reverse the sign
        n = -n;
    }
    printf("%f\n", n);
}