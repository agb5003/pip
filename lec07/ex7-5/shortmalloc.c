#include <stdio.h>

typedef struct {
    short int integer;
} shortint;

int main() {
    printf("short int size = %lu bytes.\n", sizeof(shortint));
}