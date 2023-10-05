#include <stdio.h>

int main()
{    
    /**** variable declaration ****/
    float x, y, avg, sum, diff, prod, quot, xsquared, ysquared, squaresum;   /* float type */
    
    /**** processing contents ****/
    
    /* assignment */
    printf("Enter x and y separated by a space:\n");
    scanf("%f %f", &x, &y); /* scans input from user, with the specified format inside brackets */
    /* for example, here we have "%f %f" which has a space between the 2 floats. The user will have to input 2 floats */
    /* separated by a space for the scanf to work as intended here. */
    
    /* sum */
    sum = x + y;
    printf("sum=%f\n", sum);
    
    /* diff */
    diff = x - y;
    printf("diff=%f\n", diff);
    
    /* prod */
    prod = x * y;
    printf("production=%f\n", prod);

    /* avg */
    avg = sum / 2.0; /* both side of operation needs to be a float for the result to return a float */
    printf("average=%f\n", avg);
    
    /* quot */
    if (y == 0){
        printf("quotient is not available\n");
    }else{
        quot = (float)x/y;
        printf("quotient=%f\n", quot);
    }

    /* sum of squares */
    xsquared = x*x; /*since C doesn't have a built in power operator, multiplying manually is needed to perform power operations.*/
    ysquared = y*y;
    squaresum = xsquared + ysquared;
    printf("squaresum = %f", squaresum);
    
    return 0;
}
