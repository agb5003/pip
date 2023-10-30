/*
calculation of polynomials poly.c
*/

#include <stdio.h>
#include <math.h>

#define N 4

int factorial(int number) {
    if (number < 1) {
        return 1;
    }
    for (int i = number-1; i > 1; i--) {
        number *= i;
    }
    return number;
}

int main()
{
    /**** (1) variable declaration ****/
    /* set coefficients */
    double	c[N] = {sin(0)/factorial(0), cos(0)/factorial(1), -sin(0)/factorial(2), -cos(0)/factorial(3)};
    
    double	x, y;
    int	i ;
    
    /**** (2) processing contents ****/
    printf("x values:\n");
    for(x = -M_PI; x <= M_PI; x += M_PI/100){
        printf("%f, ", x);
    }
    printf("\ny values:\n");
    for(x = -M_PI; x <= M_PI; x += M_PI/100){
        for(y = c[N-1], i = N-2; i >= 0; --i) {
            y = y * x + c[i];
        }
        printf("%f, ", y);
    }
    return 0;
}
