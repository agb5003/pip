#include <stdio.h>
#include <stdlib.h>

int recursiveGCD(int a, int b);

int main() {
    int a, b;
    printf("Enter integers to look for the LCM of (separated by a space): ");
    scanf("%d %d", &a, &b);

    // Handling invalid input
    if (a <= 0 || b <= 0) {
	printf("ERROR: Invalid input!\n");
	// Terminate the program and return status 1 to the OS
	// if invalid values are entered for a or b.
	exit(1);
    }
    
    // Calculate least common multiple using obtained gcd
    int lcm = a * b / recursiveGCD(a, b);

    printf("The Least Common Multiple of %d and %d is %d.\n", a, b, lcm);
}

int recursiveGCD(int a, int b) {
    if (a < b) { // Swap a and b to make sure b is smaller than a
	a += b;
	b = a - b;
	a -= b;
    }
    
    // Euclidean algorithm
    if (a % b != 0) { // If a % b != 0, recursively call the function
    // with b as a and a%b as b
	b = recursiveGCD(b, a % b);
    }

    return b;
}
