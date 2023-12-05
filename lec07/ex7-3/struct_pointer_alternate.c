/*
    We can also pass the pointer to the struct array and
    loop in the print function instead of the main function.
*/

#include <stdio.h>

#define NAME_MAX_LEN 100
#define MEMBER_NUM 3

typedef struct {
    char name[NAME_MAX_LEN];
    float height;
    float weight;
} st_person;

void print_person(st_person *pointer_member);

int main() {
    // variable declaration
    st_person member[MEMBER_NUM] =
    {
        {"Ichiro", 160, 50},
        {"Jiro", 170, 60},
        {"Saburo", 180, 70}
    };

    print_person(member);

    return 0;
}

void print_person(st_person *pointer_member) {
    for (int i = 0; i < MEMBER_NUM; i++) {
        printf("%d. Name = %s\n", i+1, pointer_member[i].name);  
        printf("   Height = %.2f\n", pointer_member[i].height);
        printf("   Weight = %.2f\n", pointer_member[i].weight);
        // Another way of doing this is (pointer_member+i)->member
        // C is actually quite flexible!
    }
}
