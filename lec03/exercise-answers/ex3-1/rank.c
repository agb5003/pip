#include <stdio.h>

int main() {
    int score = 0;
    printf("Enter student score: ");

    scanf("%d", &score);

    if (score >= 0 && score <= 59) {
        printf("D\n");
    } else if (score >= 60 && score <= 74) {
        printf("C\n");
    } else if (score >= 75 && score <= 84) {
        printf("B\n");
    } else if (score >= 85 && score <= 100) {
        printf("A\n");
    } else {
        printf("Not in range. Please enter integers from 0 to 100.\n");
    }
    return 0;
}