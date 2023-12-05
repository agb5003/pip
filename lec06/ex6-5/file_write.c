#include <stdio.h>
int main(void) {
    FILE *fp;
    fp = fopen("sample_out.txt", "w");
    if (fp == NULL) {
        printf("Can't open file \n");
        return 1;
    }
    fprintf(fp, "Hello\n");
    fclose(fp);
    return 0;
}
