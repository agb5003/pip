#include <stdio.h>
/* prototype declaration */
int add(int v);
void addp(int *p);

int main(){
    int a,b;

    printf("Input value: ");
    scanf("%d", &a);

    b = add(a);
    printf("Call by value: %d\n", b);
    b = a;
    addp(&b);
    printf("Call by reference: %d\n", b);
    return 0;
    }
    /* call by value function */
    int add(int v){
    v += 10; // add 10
    return v;
    }
    /* call by reference(pointer)*/
    void addp(int *p){
    *p += 10; // add 10
}