#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("/Users/max/repos/pip/lec06/ex6-4/openedwithabsolute.txt", "w");
    if (fp == NULL) {
        printf("File couldn't be opened.\n");
    } else {
        printf("File opened successfully.\n");
    }

    return 0;
}