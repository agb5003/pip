/*
 matrix_multiple.c
*/

#include <stdio.h>

int main()
{
    
    /**** (1) variable declaration ****/
    int A[4][3] = {{1,2,3},{4,5,6},{1,2,3},{4,5,6}};
    int B[3][4] = {{1,2,3,4},{5,6,7,8},{1,2,3,4}};
    int C[4][4] = {{}};
    
    
    /**** (2) processing contents ****/
    
    /* A*B */
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    /* Display results */
    // Dropdown
    printf("Dropdown view:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("C[%d][%d] = %d\n", i, j, C[i][j]);
        }
    }
    
    // Visual
    printf("Visual view:\n");
    for (int i = 0; i < 4; i++) {
        printf("| ");
        for (int j = 0; j < 4; j++) {
            printf(" %d ", C[i][j]);
        }
        printf(" |\n");
    }

    return 0;
    
}



