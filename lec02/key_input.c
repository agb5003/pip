#include <stdio.h>

int main(){
    
    /**** variable declaration ****/
    float x, y;           /* integer type */
    
    /**** processing contents ****/
    printf("Input two numbers: ");
    
    /* Get keyboard input */
    scanf("%f %f", &x, &y);

    /* display getting value */
    printf("x=%f\n", x);
    printf("y=%f\n", y);
    
    return 0;
}
