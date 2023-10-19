#include <stdio.h>

int main() {
    float a = 0, b = 0;
    char opr;
    printf("Enter operation: ");
    scanf("%f%c%f", &a, &opr, &b);

    switch (opr) {
        case '+':
            printf("%f\n", a + b);
            break;
        case '-':
            printf("%f\n", a - b);
            break;
        case '*':
            printf("%f\n", a * b);
            break;
        case '/':
            printf("%f\n", a / b);
    }
}
