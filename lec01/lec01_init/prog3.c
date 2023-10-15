/* Familiarizing myself with random generation in C as it is quite different
from the random.random() in Python or randn() (and various other random functions)
in MATLAB/Octave that I am used to */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int ans;
	time_t t1;

	printf("Select which random program you would like to run:\n1. Dice roll\n2. Coin flip\n3. Random number generator\n");
	scanf("%d", &ans);

	srand( (unsigned) time (&t1)); // Initialize rand() with seed obtained from time
	/* NOTE: This means that the random numbers generated aren't actually random. While it is debatable if true random exists,
	the numbers generated with this method is quite far from non-deterministic. */

	if (ans == 1) { // If the user picks the dice roller
		printf("Rolling a dice...\n");
		int dice_result = rand() % 6 + 1; // mod 6 to get numbers 0 to 5, then add 1 so the number is between 1 and 6, inclusive.
		printf("The dice shows a %d!", dice_result);
	}

	else if (ans == 2) { // If the user picks coin flipper
		printf("Flipping a coin...\n");
		int coin_result = rand() % 2 + 1; // same concept with dice roll, but since it's binary we assign 1 as heads and 2 as tails
		if (coin_result == 1) {
			printf("It's heads!\n");
		}
		else if (coin_result == 2) {
			printf("It's tails!\n");
		}

		// NOTE: I am not quite sure why, but for some reason, this coin flipper has a tendency to show heads. Will investigate more.
	}

	else if (ans == 3) { // If the user picks the random number generator
		int start_number, end_number, to_generate;

		printf("Enter the smallest and largest possible number to be generated, separated with a space:\n");
		scanf("%d %d", &start_number, &end_number);
		printf("Now enter how many numbers you want to generate.\n");
		scanf("%d", &to_generate); // to_generate is the amount of random numbers to be generated.

		printf("Result:\n");
		for (int i = 0; i < to_generate; i++) {
			printf("%d\n", rand() % (end_number - start_number + 1) + start_number);
			// +1 is added because without it, the random space will not include the largest number as a possible outcome.
		}
	}

	else {
		printf("Invalid answer! Please enter 1, 2 or 3 as your answer.");
	}
}