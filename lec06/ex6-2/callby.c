#include <stdio.h>

int add(int v);
void addp(int *p);

int main(){
    int a,b;

    printf("Input value: ");
    scanf("%d", &a);

    b = add(a);
    printf("Call by value: %d\n", b);

    b = a; // revert changes
    addp(&b); // call addp using memory address of b
    printf("Call by reference: %d\n", b);
    return 0;
}

// Call by value
int add(int v){
    v += 10;
    return v;
}

// Call by reference
void addp(int *p){
    *p += 10;
}
