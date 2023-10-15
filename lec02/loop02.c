#include <stdio.h>

int main()
{
    /**** variable declaration ****/
    int i,sum = 0;
    
    /**** processing contents ****/
    for(i=3;i<=1000;i+=3) {
        sum += i;
    }
    
    printf("The sum is %d\n", sum);
    
    return 0;
}