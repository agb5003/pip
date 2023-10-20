#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "\"henlo i am string\"";
    string[4] = '0'; // 0 surrounded by single quotes will assign the character 0, while 0 without the quotes will assign null and end the string. As an alternative '\0' can also be used (BUT NOT "\0", that is a string literal) as a null marker.
    printf("%s", string);
}