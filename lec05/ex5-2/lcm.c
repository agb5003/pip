#include <stdio.h>

int gcd(int a, int b) {
    if (a < b) { // Swap a and b to make sure b is smaller than a
	a += b;
	b = a - b;
	a -= b;
    }

    if (b == 0) {
	return a;
    }

    while (a % b != 0) {
	// Euclidean algorithm
	// Swap a and b if the remainder is not 0
	a += b; // adds b to a and assigns to a
	b = a - b; // assigns the original value of a to b
	a -= b; // subtracts the original value of a from a and reassigns into a, essentially making it equal to the original value of b
	b %= a; // assigns the remainder of b%a to b (because at this point b contains original value of a and a contains the original value of b)
    }

    return b;
}

int main() {
    int a, b;
    printf("Enter numbers to look for the LCM of: ");
    scanf("%d %d", &a, &b);

    int lcm = a * b / gcd(a, b);

    printf("The Least Common Multiple of %d and %d is %d.\n", a, b, lcm);
}
