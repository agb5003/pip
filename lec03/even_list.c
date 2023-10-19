#include <stdio.h>

int main() {
    int a = 0, n = 0;
    printf("Display even numbers up to: ");
    scanf("%d", &a);

    while (n <= a) {
        printf("%d\n", n);
        n+=2;
    }
}

