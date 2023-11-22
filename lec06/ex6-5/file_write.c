/*
file_write.c
Sample program for file output
*/
#include <stdio.h>
int main(void){
    FILE *fp;
    fp = fopen("sample_out.txt", "a");
    if(fp == NULL) {
        printf("Can't open file \n");
        return 1;
    }
    fprintf(fp, "Hello\n");
    fclose(fp);
    return 0;
}