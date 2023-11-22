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
    printf("*p = %d \n", *p); //indirect reference by pointer
    printf("&x = %p \n", &x); // address for variable x
    printf(" p = %p \n", p); //value for the pointer p
    *p = 20;
    printf(" x = %d \n", x);
    // Please write here in comments why the results above obtained
    return 0;
}