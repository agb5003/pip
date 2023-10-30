/*
 bubble sort sort_bubble.c
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
    

    // Sorting algorithm (bubble, reversed)
    int comparisons = 0, swaps = 0;
    printf("Bubble sorting...\n");
    for (i = 0; i < NUM-1; i++) {
        printf("Loop %d:\n", i+1);
        
        for (j = NUM-1; j > i; j--) {
            comparisons++;
            printf("[%d][%d] ", comparisons, swaps);
            for (int k = 0; k < NUM; k++) {
                if (k == j) {
                    printf("*%d ", A[k]);
                } else if (k == j - 1) {
                    printf("<%d ", A[k]);
                } else {
                    printf("%d ", A[k]);
                }
                
                // Insert new line if k reaches the end of the array
                if (k == NUM - 1) {
                    printf("\n");
                }
            }
            
            // If compared number is greater than reference number, swap them
            if (A[j-1] > A[j]) {
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;

                swaps++;
            }
        }
        printf("\n");
    }

    /* display array after sorting */
    printf("Sorted array: \n");
    for (i=0;i<NUM;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    printf("%d comparisons, %d replacements made\n", comparisons, swaps);
    
    return 0;
    
}
