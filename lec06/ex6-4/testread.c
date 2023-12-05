#include <stdio.h>

int main() {
    FILE *fp = fopen("nonexistent.txt", "r");
    if (fp == NULL) {
        printf("Could not read file\n");
    } else {
        printf("Success\n");
    }
}