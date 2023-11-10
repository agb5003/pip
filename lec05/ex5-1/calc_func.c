/*
 User-defined function add_func
*/

#include <stdio.h>

// Function declarations
float add_func(float x, float y);
float sub_func(float a, float b);
float multi_func(float a, float b);
float div_func(float a, float b);

int main() {
    float result = sub_func(div_func(multi_func(add_func(2.0, 1.0), 6.0), 1.5), 3.0);
    printf("%f\n", result);

    return 0;
}

float add_func(float x, float y) {
    return x + y;
}

float sub_func(float a, float b) {
    return a - b;
}

float multi_func(float a, float b) {
    return a * b;
}

float div_func(float a, float b) {
    return a / b;
}