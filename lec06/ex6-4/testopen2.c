#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("testfolder/openedwithrelative.txt", "w");
    if (fp == NULL) {
        printf("File couldn't be opened.\n");
    } else {
        printf("File opened successfully.\n");
    }

    fclose(fp);

    return 0;
}