#include <stdio.h>

int main()
{
    /**** variable declaration ****/
    int i,sum = 0;
    
    /**** processing contents ****/
    for(i=0;i<100;i++) {
        sum += i+1; // start from 1 instead of 0
    }
    
    printf("The sum is %d\n", sum);
    
    return 0;
    
}
