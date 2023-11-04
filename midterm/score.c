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

// Function declarations
int display_sheet(int student, float sub_avg[SUB_NUM], int score_sum[ID_NUM], int score[ID_NUM][SUB_NUM], float total_avg);
char rank(int score_sum);

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
    float sub_avg[SUB_NUM] = {0,0,0};
    int score_sum[ID_NUM] = {0,0,0,0,0,0,0,0,0,0};
    int total_avg = 0;
    for (i = 0; i < ID_NUM; i++) {
        for (int j = 0; j < SUB_NUM; j++) {
            score_sum[i] += score[i][j];
            sub_avg[j] += (float) score[i][j]/ID_NUM;
        }
        total_avg += score_sum[i]/ID_NUM;
    }
    
    
    
    // TEMPORARY - Subject Averages over all students
    for (int i=0; i<SUB_NUM; i++) {
        printf("Average score for SUB%d is %.2f\n", i+1, sub_avg[i]);
    }
    
    // Get user input
    int student;
    printf("Select student to display score sheet (0-9): ");
    scanf("%d", &student);

    // Finally, display score sheet with all information
    display_sheet(student, sub_avg, score_sum, score, total_avg);
    
    return 0;
}


// Function to display score sheet of a particular student
int display_sheet(int student, float sub_avg[SUB_NUM], int score_sum[ID_NUM], int score[ID_NUM][SUB_NUM], float total_avg) {
    printf("\n########## SCORE SHEET FOR STUDENT %d ##########\n", student);
    printf("              | SUB1  | SUB2  | SUB3  | TOTAL\n");
    printf("Student %d     | %d    | %d    | %d    | %d\n", student, score[student][0], score[student][1], score[student][2], score_sum[student]);
    printf("Class average | %.2f | %.2f | %.2f | %.2f\n", sub_avg[0], sub_avg[1], sub_avg[2], total_avg);
    printf("Rank assigned: %c\n", rank(score_sum[student]));
}

char rank(int score_sum) {
    switch (score_sum)
    {
    case 0 ... 209:
        return 'D';

    case 210 ... 239:
        return 'C';
    
    case 240 ... 269:
        return 'B';
    
    case 270 ... 300:
        return 'A';
    
    default: // ERROR
        return 'E';
    }
}