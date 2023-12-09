#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter something (press return to leave blank): ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        // Handle input error
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    if (len == 1) {
        printf("You pressed return without entering anything.\n");
        // Perform the action you want for blank input
    } else {
        printf("You entered: %s\n", input);
        // Perform the action for non-blank input
    }

    return 0;
}
