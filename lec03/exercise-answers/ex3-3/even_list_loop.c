#include <stdio.h>

int main () {
    int i = 1;

    while (i>0) {
        printf("Enter a positive integer: ");
        scanf("%d", &i);
    }
    return 0;
}