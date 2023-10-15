#include <stdio.h>

int main() {
    char string_name[21]; // Declare an array with space for 20 characters + null terminator
    int result;

    printf("Enter a string (up to 20 characters): ");
    result = scanf("%20s", string_name);

    if (result == 1) {
        // Input was successfully read within the specified limit
        printf("You entered: %s\n", string_name);
    } else {
        // Input exceeded the limit or an error occurred
        printf("Invalid input. Please enter up to 20 characters.\n");

        // Clear any remaining input in the buffer
        while (getchar() != '\n');

        // You can choose to exit the program or take other actions here
    }

    return 0;
}
