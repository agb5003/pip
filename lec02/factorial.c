#include <stdio.h>

int main()
{
    /**** variable declaration ****/
    int n,factorial = 1; // Initialize factorial as 1 so that it defaults to 1 when 0 or 1 is entered

    printf("Enter number to get the factorial of: ");
    scanf("%d", &n); // get user input for the desired factorial
    if (n < 0 || n > 12) {
        printf("Integers smaller than 0 or larger than 12 are not supported.\n");
    }
    else {
        /**** processing contents ****/
        for(;n>1;n--) {
            factorial *= n;
        }
        
        printf("The factorial is %d\n", factorial);
    }
    return 0;
}