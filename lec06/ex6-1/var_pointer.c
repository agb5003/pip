#include <stdio.h>
int main(){
    /**** variable declaration****/
    int x;
    int *p;
    /**** processing contents****/
    printf("Input variable: ");
    scanf("%d", &x);
    p = &x;
    printf(" x = %d \n", x);
    printf("*p = %d \n", *p); // indirect reference by pointer
    printf("&x = %p \n", &x); // address for variable x
    printf(" p = %p \n", p); // value for the pointer p
    *p = 20;
    printf(" x = %d \n", x);
    // The first and second printf shows the value that is entered by the user.
    // The third and fourth printf shows the pointer to x.
    // Since the value 20 is reassigned to the variable pointed to by p (which is
    // x), when x is printed again, its value will change to 20.
    return 0;
}
