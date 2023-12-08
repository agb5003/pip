/* 
J_score2.c
Score display & txt output program for J-League result
Practice of Information Processing, Fall 2023
Final Report

Maximilian Fernaldy
C2TB1702
*/

#include <stdio.h>
#include <stdlib.h>

#define TEAM_NUM 18
#define NAME_LENGTH 20
#define DATA_LEN 100

/* team score structure */
struct team_score{
    char name[NAME_LENGTH]; /* team name */
    int win;  /* number of win */
    int draw; /* number of draw */
    int loss; /* number of lose */
    int GF;   /* goals for (scored)*/
    int GA;   /* goals against (conceded)*/
    int score; /* win points */
    int point_diff; /* goals difference */
};

typedef struct team_score SC; /*strcut team_score is aliased as "SC" */

/* prototype declaration of functions */
SC *read_data(const char *file_path);
void calc_score(SC *team);
void rank_score(SC table[],SC *rank_array[]);
void write_data(FILE *fout, SC *rank_array[]);
void heapify(SC *rank_array[], int n, int i);
void swap_pointers(SC **pointerA, SC **pointerB);
int number_of_teams(FILE *fin);

int main(void)
{
    /* variable declaration */
    FILE *fout;
    /* (1) Reading file */
    const char *file_path = "J_result2023.csv";
    SC *table = read_data(file_path);

    SC *rank_array[TEAM_NUM]; /* pointer array for sorting */
    int i;
    
    /* Open reading file */
    /* Open writing file */
    fout = fopen("J_score2.txt","w"); // open output file
    
    
    /* （2）Calculating score */
    for(i=0; i< TEAM_NUM; i++){
        calc_score(&table[i]);
    }

    /* （3）Ranking based on score */
    rank_score(table, rank_array);
    
    // Display results
    for (int i = 0; i < TEAM_NUM; i++) {
        printf("%25s %4d %4d %4d %4d %4d %4d %4d\n", rank_array[i]->name, rank_array[i]->win, rank_array[i]->draw, rank_array[i]->loss, rank_array[i]->GF, rank_array[i]->GA, rank_array[i]->score, rank_array[i]->point_diff);
    }
    
    /* （4) Writing ranking file in order*/
    write_data(fout, rank_array);

    /* closing process */
    fclose(fout); /* close writing file */

    return(0);
}

/* Reading score file */
SC *read_data(const char *file_path)
{
    // Read data from csv file and store in table[]
    // Declare table to store data
    SC *table;

    // Open file for reading
    FILE *fin;
    if((fin = fopen(file_path,"r"))==NULL){ // open input file
        printf("Can't open file. Make sure the csv file is in the working directory.\n");
        exit(1);
    }

    // Dynamically allocate memory for table
    int i = 0;
    table = malloc(sizeof(SC) * number_of_teams(fin));
    char buffer[DATA_LEN];
    while (fgets(buffer, sizeof(buffer), fin) != NULL) {
        sscanf(buffer, "%[^,],%d,%d,%d,%d,%d", table[i].name, &table[i].win, &table[i].draw, &table[i].loss, &table[i].GF, &table[i].GA);
        printf("[DEBUG] %s, %d, %d, %d, %d, %d\n", table[i].name, table[i].win, table[i].draw, table[i].loss, table[i].GF, table[i].GA);
        i++;
    }

    fclose(fin);

    return table;
}

int number_of_teams(FILE *fin) {
    char buffer[DATA_LEN];
    int number_of_teams = 0;
    while (fgets(buffer, sizeof(buffer), fin) !=NULL) {
        number_of_teams++;
    }
    fseek(fin, 0, SEEK_SET);
    return number_of_teams;
}

/* Calculation of winpoints and goals difference */
void calc_score(SC *team)
{
    // Points = wins * 3 + draws * 1 + losses * 0
    team->score = team->win * 3 + team->draw;
    // Point difference = Goals For - Goals Against
    team->point_diff = team->GF - team->GA;
}

/* Ranking based on score */
void rank_score(SC table[], SC *rank_array[])
{
    // Create array of pointers
    for (int i = 0; i < TEAM_NUM; i++) {
        rank_array[i] = &table[i];
    }

    // Build max heap
    for (int i = TEAM_NUM/2 - 1; i >= 0; i--) {
        heapify(rank_array, TEAM_NUM, i);
    }
    /*
    At this point in the code, we have built a min heap, which means
    the smallest element is at the top of the heap, and no child node is
    smaller than the parent. However, in each level of the heap, the order
    is still jumbled.
    */

    // Heap sort
    for (int i = TEAM_NUM - 1; i >= 0; i--) {
        /*
        Remove root node from heap by swapping with last element
        Then, heapify at root to get the highest element at the root again
        Repeat until the heap is gone.
        */
        swap_pointers(&rank_array[0], &rank_array[i]);

        heapify(rank_array, i, 0);
    }
}

void heapify(SC *rank_array[], int n, int i) {
    int lowest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if (left < n) {
        if (rank_array[left]->score < rank_array[lowest]->score)
        {
            lowest = left;
        } else if (rank_array[left]->score == rank_array[lowest]->score)
        {
            if (rank_array[left]->point_diff < rank_array[lowest]->point_diff)
            {
                lowest = left;
            } else if (rank_array[left]->point_diff == rank_array[lowest]->point_diff)
            {
                if (rank_array[left]->GF < rank_array[lowest]->GF) {
                    lowest = left;
                }
            }
        }
    }
    if (right < n) {
        if (rank_array[right]->score < rank_array[lowest]->score)
        {
            lowest = right;
        } else if (rank_array[right]->score == rank_array[lowest]->score)
        {
            if (rank_array[right]->point_diff < rank_array[lowest]->point_diff)
            {
                lowest = right;
            } else if (rank_array[right]->point_diff == rank_array[lowest]->point_diff)
            {
                if (rank_array[right]->GF < rank_array[lowest]->GF) {
                    lowest = right;
                }
            }
        }
    }
    if (right < n && rank_array[right]->score < rank_array[lowest]->score)
    {
        lowest = right;
    }
    
    // Swap if root is not the largest element, then continue heapify
    if (lowest != i) {
        // Swapping pointers around
        swap_pointers(&rank_array[lowest], &rank_array[i]);
        heapify(rank_array, n, lowest);
    }
}

void swap_pointers(SC **pointerA, SC **pointerB) {
    // this function swaps pointers. To do that, we pass in the pointer to the pointer.
    SC *temp = *pointerA;
    *pointerA = *pointerB;
    *pointerB = temp;
}

/* Writing ranking file */
void write_data(FILE *fout, SC *rank_array[])
{
    fprintf(fout, "| Rank | Team Name            | Wins | Draws | Losses | Goals Scored | Goals Conceded | Points | Goal Difference |\n");
    fprintf(fout, "|------|----------------------|------|-------|--------|--------------|----------------|--------|-----------------|\n");
    for (int i = 0; i < TEAM_NUM; i++) {
        fprintf(fout, "| %-4d | %-20s | %4d | %5d | %6d | %12d | %14d | %6d | %15d |\n", i+1,
                rank_array[i]->name,
                rank_array[i]->win,
                rank_array[i]->draw,
                rank_array[i]->loss,
                rank_array[i]->GF,
                rank_array[i]->GA,
                rank_array[i]->score,
                rank_array[i]->point_diff);
    }
}
