#include <stdio.h>

struct Fruits {
    char name[20];
    char size[30];
    char taste[50];
};

int main() {
    int n = 0;
    printf("How many fruits are there? ");
    scanf("%d", &n);
    // Clear input buffer before proceeding with variable input
    while(getchar() != '\n');

    struct Fruits fruits_collection[n];
    // Data intake
    for (int i = 0; i < n; i++) {
        printf("Name of fruit %d: ", i+1);
        scanf("%s", fruits_collection[i].name);
        printf("Size of fruit %d: ", i+1);
        scanf("%s", fruits_collection[i].size);
        printf("Taste of fruit %d: ", i+1);
        scanf("%s", fruits_collection[i].taste);
    }

    // Print collected information
    printf("\nFruits collection: \n");
    for (int i = 0; i < n; i++) {
        printf("%s is %s-sized and tastes %s.\n", fruits_collection[i].name,
                                                fruits_collection[i].size,
                                                fruits_collection[i].taste);
    }
}