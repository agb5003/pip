#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "henlo i am string";
    string[4] = '\0'; // single quote will assign the character 0, while 0 without the quotes will assign null and end the string. As an alternative you can also use '\0' (BUT NOT "\0", that is a string literal) as a null marker.
    printf("%s", string);
}