#include <stdio.h>

int main() {
    int x;
    int *p = &x;

    *p = 1;

    printf("%d\n", x);
}

