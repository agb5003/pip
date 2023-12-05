#include <stdio.h>

int main() {
    int c;
    FILE* fp = fopen("pi.txt", "r");
    int count[10]={0,0,0,0,0,0,0,0,0,0};
    
    while ((c=fgetc(fp))!=EOF) {
        // Convert character to integer type by subtracting the ASCII value of
        // 0 from the current character.
        int digit = c - '0';
        count[digit]++;
    }

    printf("Number of characters:\n");
    for (int i = 0; i < 10; i++) {
        printf("%ds: %d\n", i, count[i]);
    }
}
