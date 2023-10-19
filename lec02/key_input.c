#include <stdio.h>

int main(){
    
    /**** variable declaration ****/
    float x, y;           /* float type */
    
    /**** processing contents ****/
    printf("Input two numbers: ");
    
    /* Get keyboard input */
    scanf("%f %f", &x, &y); // also change format specifiers to %f

    /* display getting value */
    printf("x=%f\n", x);
    printf("y=%f\n", y);
    
    return 0;
}
