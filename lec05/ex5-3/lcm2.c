#include <stdio.h>

int recursiveGCD(int a, int b) {
    if (a < b) {
	a += b;
	b = a - b;
	a -= b;
    }

    if (b == 0) return a;

    if (a % b != 0) {
	b = recursiveGCD(b, a % b);
    }

    return b;
}

int main() {
    int a, b;
    printf("Enter numbers to look for the LCM of: ");
    scanf("%d %d", &a, &b);

    int lcm = a * b / recursiveGCD(a, b);

    printf("The Least Common Multiple of %d and %d is %d.\n", a, b, lcm);
}
