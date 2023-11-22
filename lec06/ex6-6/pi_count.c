#include <stdio.h>

int main() {
    int c;
    FILE* fp = fopen("pi.txt", "r");
    int count[10]={0,0,0,0,0,0,0,0,0,0};
    
    while ((c=fgetc(fp))!=EOF) {
        switch (c) {
            case '0':
                count[0]++;
                break;
            case '1':
                count[1]++;
                break;
            case '2':
                count[2]++;
                break;
            case '3':
                count[3]++;
                break;
            case '4':
                count[4]++;
                break;
            case '5':
                count[5]++;
                break;
            case '6':
                count[6]++;
                break;
            case '7':
                count[7]++;
                break;
            case '8':
                count[8]++;
                break;
            case '9':
                count[9]++;
                break;
        }
    }

    printf("Number of characters:\n%d 0s, %d 1s, %d 2s, %d 3s, %d 4s, %d 5s, %d 6s, %d 7s, %d 8s and %d 9s.\n",
           count[0],
           count[1],
           count[2],
           count[3],
           count[4],
           count[5],
           count[6],
           count[7],
           count[8],
           count[9]);
}
