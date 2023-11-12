#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b);

int main() {
    int a, b;
    printf("Enter integers to look for the LCM of (separated by a space): ");
    scanf("%d %d", &a, &b);

    // Handling invalid input
    if (a <= 0 || b <= 0) {
	printf("ERROR: Invalid values entered!\n");
	// Terminate the program and return status 1 to the OS
	// if invalid values are entered for a or b.
	exit(1);
    }
    
    // Calculate least common multiple using obtained gcd
    int lcm = a * b / gcd(a, b);

    printf("The Least Common Multiple of %d and %d is %d.\n", a, b, lcm);
}

int gcd(int a, int b) {
    if (a < b) { // Swap a and b to make sure b is smaller than a
	a += b;
	b = a - b;
	a -= b;
    }

    while (a % b != 0) {
	// Euclidean algorithm
	// Swap a and b if the remainder is not 0
	a += b; // adds b to a and assigns to a
	b = a - b; // assigns the original value of a to b
	a -= b; // subtracts the original value of a from a and reassigns into a,
    // essentially making it equal to the original value of b
	b %= a; // assigns the remainder of b%a to b (because at this point b
    // contains original value of a and a contains the original value of b)
    }

    return b;
}
