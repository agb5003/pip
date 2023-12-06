#include <stdio.h>

#define NAME_MAX_LEN 100
#define MEMBER_NUM 3

typedef struct {
    char name[NAME_MAX_LEN];
    float height;
    float weight;
} st_person;

void print_person(st_person *pointer_member, int member_ID);

int main() {
    // variable declaration
    st_person member[MEMBER_NUM] =
    {
        {"Ichiro", 160, 50},
        {"Jiro", 170, 60},
        {"Saburo", 180, 70}
    };

    int member_ID = -1;  // Initialize member ID as something invalid
    // while (member_ID < 0 || member_ID >= MEMBER_NUM) {
    //     printf("Enter member ID to access information: ");
    //     scanf("%d", &member_ID);
    //     if (member_ID < 0 || member_ID >= MEMBER_NUM) {
    //         printf("Please enter a valid member ID.\n");
    //     }
    // }
    printf("Enter member ID to access information: ");
    scanf("%d", &member_ID);

    print_person(member, member_ID);
    // Pass memory address of the right member to print function

    return 0;
}

void print_person(st_person pointer_member[], int member_ID) {
    printf("\n##### INFORMATION FOR MEMBER ID #%d #####\n", member_ID);
    printf("Name = %s\n", (pointer_member+member_ID)->name);  
    printf("Height = %.2f\n", (pointer_member+member_ID)->height);
    printf("Weight = %.2f\n", (pointer_member+member_ID)->weight);
}
