#include <stdio.h>
#define STRLEN 100


int main() {
    char string[STRLEN];
    char new_string[STRLEN];
    printf("Enter the string you want to reverse:");
    for(int i = 0; i < STRLEN; i++) {
        string[i] = 0;
    }
    fgets(string, sizeof(string), stdout);
    // Reverse input string

    char current_char;
    int i;
    
    while (current_char != "\0") {
        current_char = string[i];
        new_string[i] = current_char
    }

    printf("Loop is done");

    return 0;
}
