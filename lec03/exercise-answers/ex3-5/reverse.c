#include <stdio.h>
#include <string.h>

void reverse(char *string);

int main() {
    char string[1001];

    // Get string from user
    printf("Enter string (1000 character limit): ");
    fgets(string, sizeof(string), stdin);
    // NOTE: this fgets also gets newline character from pressing enter.
    // To remove this trailing newline, we use strcspn() function to index the string and remove the newline.
    string[strcspn(string, "\n")] = 0;

    reverse(string);
}

void reverse(char *string) {
    // get string length and midpoint
    int length = strlen(string);
    int midpoint = length / 2;

    for(int i = 0; i < midpoint; i ++) {
        char temporary = string[i];
        string[i] = string[length -i -1];
        string[length - i - 1] = temporary;
    }

    printf("Reversed: %s\n", string);
}