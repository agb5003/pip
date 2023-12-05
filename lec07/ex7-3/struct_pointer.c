#include <stdio.h>

#define NAME_MAX_LEN 100
#define MEMBER_NUM 3

typedef struct {
    char name[NAME_MAX_LEN];
    float height;
    float weight;
} st_person;

void print_person(int i, st_person *pointer_member);

int main() {
    // variable declaration
    st_person member[MEMBER_NUM] =
    {
        {"Ichiro", 160, 50},
        {"Jiro", 170, 60},
        {"Saburo", 180, 70}
    };

    for (int i = 0; i < MEMBER_NUM; i++) {
        print_person(i, member+i);
    }
}

void print_person(int i, st_person *pointer_member) {
    printf("%d. Name = %s\n", i+1, pointer_member->name);
    printf("   Height = %.2f\n", pointer_member->height);
    printf("   Weight = %.2f\n", pointer_member->weight);
}
