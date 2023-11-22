#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("sample.txt","r");
    if( fp == NULL) {
        printf("Can't open file.\n");
        return 1;
    }
    else
    printf("success\n");
    fclose(fp);
    return 0;
}