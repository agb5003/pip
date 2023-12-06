#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char b;
    int d;
    int a;
    int c;
}alignment;


int main() {
    printf("sizeof(alignment) = %lu\n", sizeof(alignment));
}