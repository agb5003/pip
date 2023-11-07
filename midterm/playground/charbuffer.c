// C Code to explain why not
// clearing the input buffer
// causes undesired outputs
#include <stdio.h>
int main()
{
	char str[80], ch;

	// Scan input from user -
	// GeeksforGeeks for example
	scanf("%s", str);

    // Clear input buffer
    while(getchar() != '\n');
    // if the above line is uncommented, the program reads the newline
    // as the character to get by getchar(), which means it will print
    // whatever is input into scanf(), then print a new line, and end 
    // the program, without taking the second input with getchar().

	// Scan character from user-
	// 'a' for example
	ch = getchar();

	// Printing character array,
	// prints “GeeksforGeeks”)
	printf("%s\n", str);

	// This does not print
	// character 'a'
	printf("%c", ch);

	return 0;
}
