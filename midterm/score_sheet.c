/*
score.c
Practice of Information Processing Midterm Assignment
Maximilian Fernaldy
C2TB1702
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Macro definition */
#define ID_NUM 10
#define SUB_NUM 3

// Function declarations
void display_sheet(int student, float sub_avg[SUB_NUM], int score_sum[ID_NUM], int score[ID_NUM][SUB_NUM], float total_avg, float deviation_values[SUB_NUM]);
char grade(int score_sum);
void judge(float sub_avg[], int score_sum, int score[], float total_avg);
int find_lowest(int score[]);
void get_tscore(int student, float sub_avg[SUB_NUM], int score[ID_NUM][SUB_NUM], float deviation_values[SUB_NUM]);
int get_rank(int student, int score_sum[ID_NUM]);

int main() {

    /**** (1) variable declaration ****/
    int score[ID_NUM][SUB_NUM]={{80,94,84},{70,71,60},{65,83,73},{75,80,65},{78,88,83},{92,100,98},{82,88,93},{79,85,80},{88,95,90},{66,70,72}};

    int i;

    /**** (2) processing contents ****/
    /* display scores */
    // printf("ID  SUB1  SUB2  SUB3\n");
    // for (i = 0; i < ID_NUM; i++){
    //     printf("[%d]  %3d   %3d   %3d\n", i, score[i][0], score[i][1], score[i][2]);
    // }

    // Get total score for each student and class average for each subject
    float sub_avg[SUB_NUM] = {0,0,0};
    int score_sum[ID_NUM] = {0,0,0,0,0,0,0,0,0,0};
    float total_avg = 0;
    for (i = 0; i < ID_NUM; i++) {
        for (int j = 0; j < SUB_NUM; j++) {
            score_sum[i] += score[i][j];
            sub_avg[j] += (float) score[i][j]/ID_NUM;
        }
        total_avg += (float) score_sum[i]/ID_NUM;
        
    }

    // Get user input
    int student = -1;
    while (student < 0 || student > 9) {
        printf("Enter student ID to display score sheet (0-9): ");
        scanf("%d", &student);
    }

    // Process data
    float deviation_values[] = {0,0,0};
    get_tscore(student, sub_avg, score, deviation_values);

    // Finally, display score sheet with all information
    display_sheet(student, sub_avg, score_sum, score, total_avg, deviation_values);
    judge(sub_avg, score_sum[student], score[student], total_avg);

    return 0;
}


// Function to display score sheet of a particular student
void display_sheet(int student, float sub_avg[SUB_NUM], int score_sum[ID_NUM], int score[ID_NUM][SUB_NUM], float total_avg, float deviation_values[SUB_NUM]) {
    printf("\n\n########### SCORE SHEET FOR STUDENT %d ###########\n", student);
    printf("                   SUB1    SUB2    SUB3    TOTAL\n");
    printf("Student %d          %d      %d      %d      %d\n", student, score[student][0], score[student][1], score[student][2], score_sum[student]);
    printf("Class average      %.2f   %.2f   %.2f   %.2f\n", sub_avg[0], sub_avg[1], sub_avg[2], total_avg);
    printf("T-score            %.2f   %.2f   %.2f     -\n", deviation_values[0], deviation_values[1], deviation_values[2]);
    printf("Rank: %d\n", get_rank(student, score_sum));
    printf("Grade assigned: %c\n\n", grade(score_sum[student]));
}

char grade(int score_sum) {
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

void judge(float sub_avg[], int score_sum, int score[], float total_avg) {
    // Print introduction of comments
    printf("Comments: ");
    // Difference between student's sum of scores and the class average
    float total_difference = (float) score_sum - total_avg;
    printf("Overall, ");
    if (total_difference >= -10 && total_difference < 0) {
        printf("you place slightly below the class average. ");
    } else if (total_difference >= -20 && total_difference < -10) {
        printf("you place below the class average. ");
    } else if (total_difference >= -30 && total_difference < -20) {
        printf("you place considerably below the class average. ");
    } else if (total_difference < -30) {
        printf("you place severely below the class average. ");
    } else {
        if (total_difference >= 0 && total_difference <= 10) {
            printf("you place slightly above the class average. ");
        } else if (total_difference > 10 && total_difference <= 20) {
            printf("you place above the class average. ");
        } else if (total_difference > 20 && total_difference <= 30) {
            printf("you place considerably above the class average. ");
        } else if (total_difference > 30) {
            printf("you place much higher than the class average. ");
        }
    }

    char student_grade = grade(score_sum);
    switch(student_grade) {
        case 'A':
            printf("Keep up the good work.\n");
            break;
        case 'B':
            printf("You still have room to improve, ");
            break;
        case 'C':
            printf("You have much room to improve, ");
            break;
        case 'D':
            printf("You need to improve fast in order to pass, ");
            break;
    }

    if (student_grade != 'A') { // No need for additional comments if student has grade A
        // Find subject with lowest grade
        int lowest_index = find_lowest(score);
        // Encourage improvement in the worst subject
        printf("especially in SUB%d.\n", lowest_index+1);
    }
}

int find_lowest(int score[]) {
    int smallest_index = 0;
    for (int i = 0; i < SUB_NUM; i++) {
        if (score[i] < score[smallest_index]) {
            smallest_index = i;
        }
    }
    return smallest_index;
}

void get_tscore(int student, float sub_avg[SUB_NUM], int score[ID_NUM][SUB_NUM], float deviation_values[SUB_NUM]) {
    float std_dev[] = {0,0,0};
    for (int i = 0; i < SUB_NUM; i++) {
        float squared_difference_sum = 0;
        for (int j = 0; j < ID_NUM; j++) {
            squared_difference_sum += pow(score[j][i] - sub_avg[i], 2);
        }
        std_dev[i] = sqrt(squared_difference_sum / ID_NUM);

        deviation_values[i] = 10 * (score[student][i] - sub_avg[i]) / std_dev[i] + 50;
    }
}

int get_rank(int student, int score_sum[ID_NUM]) {
    int rank = 1; // Initialize as rank 1
    for (int i = 0; i < ID_NUM; i++) {
        if (score_sum[i] > score_sum[student]) {
            rank++; // If there is someone who scores higher, add 1 to rank
        }
    }
    return rank;
}
// This ranking method will result in multiple people getting the same rank
// if they have the same exact total score (a tie).