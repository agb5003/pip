/*
selection sort sort_select.c
*/

#include <stdio.h>

/* Macro definition */
#define NUM 10

int main()
{
    
    /**** (1) variable declaration ****/
    int A[NUM] = {8,2,7,4,5,6,9,0,1,3};
    
    
    int i, j, temp;

    
    /**** (2) processing contents ****/

    /* display array before sorting */
    printf("Array before sorting: \n");
    for (i=0;i<NUM;i++){
        printf("%d ",A[i]);
    }
    printf("\n\n");

    // Sorting algorithm (selection)
    printf("Selection sorting...\n");

    int comparisons = 0, swaps = 0;
    for (i = 0; i < NUM-1; i++) {
        int smallest_index = i;
        printf("Search %d:\n", i+1);

        for (j = i+1; j < NUM; j++) {
            comparisons++;
            printf("[%d][%d] ", comparisons, swaps);
            for (int k = 0; k < NUM; k++) {
                if (k == i) { // Element to replace
                    printf("*");
                } else if (k == j) { // Compared element
                    printf(">");
                }
                if (k == smallest_index ) {
                    printf("!");
                }
                printf("%d ", A[k]);
                // Insert new line if k reaches the end of the array
                if (k == NUM - 1) {
                    printf("\n");
                }
            }
            // If compared number is smaller than current smallest number, make it the new smallest
            if (A[j] < A[smallest_index]) {
                smallest_index = j;
            }
            
        }

        // At the end of comparisons, swap smallest with element to replace
        if (i != smallest_index) {
            temp = A[i];
            A[i] = A[smallest_index];
            A[smallest_index] = temp;
            swaps++;

        }
        printf("\n");
    }

    /* display array after sorting */
    printf("Sorted array: \n");
    for (i=0;i<NUM;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    printf("%d comparisons and %d replacements made", comparisons, swaps);
    
    return 0;
    
}
