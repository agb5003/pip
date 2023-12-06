#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    int array[10];
    int *ptr;  // even though it doesn't look like it, ptr can be treated like an array.
    // This is because we can treat it as the pointer to the first element of an array.
    // After allocating memory, we can then assign values directly with subscripts.

    printf("Number of Data? ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);        
    }

    ptr = malloc(sizeof(int)*num);
    if (ptr == NULL) {
        printf("memory allocation error.\n");
        return 1;
    }
    for (int i = 0; i < num; i++) {
        printf("ptr[%d]: ", i);
        scanf("%d", &ptr[i]);
    }

    for (int i = 0; i < num; i++) {
        printf("array[%d] = %d, ptr[%d] = %d\n", i, array[i], i, ptr[i]);
    }

    printf("\n--- Memory Usage ---\n");
    printf("Array: %lu [bytes]\n", sizeof(array));
    printf("Malloc: %lu [bytes]\n", num*sizeof(int));

    free(ptr);
    return 0;
}
