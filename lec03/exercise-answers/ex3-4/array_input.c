#include <stdio.h>

#define ARRAY_LENGTH 5

int main() {
    int arr[ARRAY_LENGTH], sum = 0, new_entry;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("Enter new number into array: ");
        scanf("%d", &new_entry);
        arr[i] = new_entry;
        sum += arr[i];
    }
    
    printf("Your inputs are:\n");
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    printf("Sum is %d\n", sum);
}
