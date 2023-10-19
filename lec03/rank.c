#include <stdio.h>

int main() {
    int score = 0;
    printf("Enter student score: ");

    scanf("%d", &score);

    if (score >= 0 && score < 60) {
        printf("D");
    } else if (score >= 60 && score < 75) {
        printf("C");
    } else if (score >= 75 && score < 85) {
        printf("B");
    } else if (score >= 85 && score <= 100) {
        printf("A");
    } else {
        printf("Not in range. Please enter integers from 0 to 100.");
    }
}
