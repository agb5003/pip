/*
calculation of polynomials poly.c
*/

#include <stdio.h>
#include <math.h>

#define N  6

int main()
{
    /**** (1) variable declaration ****/
    /* set coefficients */
    double	c[N] = {sin(0), cos(0)/1, -sin(0)/2, -cos(0)/6, sin(0)/24, cos(0)/120};
    
    double	x, y;
    int	i ;
    
    /**** (2) processing contents ****/
    printf("x: \n");
    for(x = -3*M_PI; x <= 3*M_PI + 0.005; x += M_PI/12){ // add 0.005 so the program can reach 3.141593
        for(y = c[N-1], i = N-2; i >= 0; --i) {
            y = y * x + c[i];
        }
        printf("%f ", x);
    }
    printf("\ny: \n");
    for(x = -3*M_PI; x <= 3*M_PI + 0.005; x += M_PI/12){ // add 0.005 so the program can reach 3.141593
        for(y = c[N-1], i = N-2; i >= 0; --i) {
            y = y * x + c[i];
        }
        printf("%f ", y);
    }
    printf("\n");
    return 0;
}
