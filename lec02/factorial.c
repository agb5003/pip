#include <stdio.h>

int main()
{
    /**** variable declaration ****/
    int n,factorial;

    scanf("%d", &n);
    
    /**** processing contents ****/
    for(;n>1;n--) {
        factorial*=n;
    }
    
    printf("The factorial is %d\n", factorial);
    
    return 0;
}
