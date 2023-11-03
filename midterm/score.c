/*
score.c
Practice of Information Processing Midterm Assignment
Maximilian Fernaldy
C2TB1702
*/

#include <stdio.h>
#include <string.h>

/* Macro definition */
#define ID_NUM 10
#define SUB_NUM 3

int main(){
    
    /**** (1) variable declaration ****/
    int score[ID_NUM][SUB_NUM]={{80,94,84},{70,71,60},{65,83,73},{75,80,65},{78,88,83},{92,100,98},{82,88,93},{79,85,80},{88,95,90},{66,70,72}};
    
    int i;
    
    /**** (2) processing contents ****/
    /* display scores */
    printf("ID  SUB1  SUB2  SUB3\n");
    for (i = 0; i < ID_NUM; i++){
        printf("[%d]  %3d   %3d   %3d\n", i, score[i][0], score[i][1], score[i][2]);
    }
    
    // Get total score for each student and class average for each subject
    float sub_avg[SUB_NUM]={0,0,0};
    for (i = 0; i < ID_NUM; i++) {
        int score_sum = 0;
        for (int j=0; j<SUB_NUM; j++) {
            score_sum += score[i][j];
            sub_avg[j] += (float) score[i][j]/ID_NUM;
        }
    }
    
    // TEMPORARY - Subject Averages over all students
    for (int i=0; i<SUB_NUM; i++) {
        printf("Average score for SUB%d is %.2f\n", i+1, sub_avg[i]);
    }
    
    // Get user input
    int student;
    printf("Select student to display score sheet (0-9): ");
    scanf("%d", student);
    
    return 0;
}