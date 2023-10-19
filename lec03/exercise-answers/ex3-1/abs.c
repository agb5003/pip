#include <stdio.h>

int main() {
    int n = 0;
    printf("Enter the number you would like the absolute value of:");
    scanf("%d", &n);
    if (n < 0) {
        printf("%d\n", -n);
    } else {
        printf("%d\n", n);
    }
}

