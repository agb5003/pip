/* 
J_score1.c
Score display & txt output program for J-League result
Practice of Information Processing, Fall 2023
Final Report

Maximilian Fernaldy
C2TB1702
*/

#include <stdio.h>  // Standard input/output
#include <stdlib.h>  // Library for memory allocation and program control

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

typedef struct team_score SC; /*struct team_score is aliased as "SC" */

/* prototype declaration of functions */
SC *read_data(const char *file_path, int *number_of_teams);
void calc_score(SC *team);
void rank_score(SC table[], int number_of_teams);
void swap_SC(SC *team1, SC *team2);
void write_data(FILE *fout, SC table[], int number_of_teams);
int get_number_of_teams(FILE *fin);

int main(void)
{
    /* variable declaration */
    FILE *fout;
    /* (1) Reading file */
    int number_of_teams;
    SC *table = read_data("J_result2023.csv", &number_of_teams);

    int i;
    
    /* Open reading file */
    /* Open writing file */
    fout = fopen("J_score1.txt","w"); // open output file
    
    
    /* （2）Calculating score */
    for(i=0; i< number_of_teams; i++) {
        calc_score(&table[i]);
    }

    /* （3）Ranking based on score */
    rank_score(table, number_of_teams);
    
    /* （4) Writing ranking file in order*/
    write_data(fout, table, number_of_teams);

    /* closing process */
    fclose(fout); /* close writing file */

    return(0);
}

SC *read_data(const char *file_path, int *number_of_teams)
{
    // Read data from csv file and store in table[]
    // Declare table to store data
    SC *table;

    // Open file for reading
    FILE *fin;
    if((fin = fopen(file_path,"r"))==NULL){ // open input file
        printf("Can't open result file. Make sure the csv file is in the working directory and formatted as \"J_resultYYYY.csv\".\n");
        exit(1);
    } else {
        printf("Reading file \"%s\"...\n", file_path);
    }

    // Dynamically allocate memory for table
    int i = 0;
    *number_of_teams = get_number_of_teams(fin);
    table = malloc(sizeof(SC) * *number_of_teams);

    // Store data in array
    char buffer[DATA_LEN];
    while (fgets(buffer, sizeof(buffer), fin) != NULL) {
        sscanf(buffer, "%[^,],%d,%d,%d,%d,%d",
                table[i].name,
                &table[i].win,
                &table[i].draw,
                &table[i].loss,
                &table[i].GF,
                &table[i].GA);
        i++;
    }

    // Close file and return storage table
    fclose(fin);
    return table;
}

int get_number_of_teams(FILE *fin) {
    // This function gets the selected file and returns how many lines are in the file.
    char buffer[DATA_LEN];
    int number_of_teams = 0;
    while (fgets(buffer, sizeof(buffer), fin) != NULL) {
        number_of_teams++;
    }
    fseek(fin, 0, SEEK_SET);  // return fgets to the first line
    return number_of_teams;
}

void calc_score(SC *team)
{
    // Points = wins * 3 + draws * 1 + losses * 0
    team->score = team->win * 3 + team->draw;
    // Point difference = Goals For - Goals Against
    team->point_diff = team->GF - team->GA;
}

void rank_score(SC table[], int number_of_teams)
{
    // Use selection sort
    for (int i = 0; i < number_of_teams-1; i++) {
        int highest_rank_index = i;
        for (int j = i+1; j < number_of_teams; j++) {
            if (table[j].score > table[highest_rank_index].score) {
                highest_rank_index = j;
            } else if (table[j].score == table[highest_rank_index].score) {
                // Case if a score tie is encountered
                if (table[j].point_diff > table[highest_rank_index].point_diff) {
                    // If compared team has larger point difference
                    highest_rank_index = j;
                } else if (table[j].point_diff == table[highest_rank_index].point_diff) {
                    // If the point difference is still the same
                    if (table[j].GF > table[highest_rank_index].GF) {
                        // If the compared team has more goals scored.
                        highest_rank_index = j;
                    }
                }
            }
        }
        if (highest_rank_index != i) {
            swap_SC(&table[i], &table[highest_rank_index]);
        }
    }
}

void swap_SC(SC *team1, SC *team2)
{
    // Swap places of reference team and team with current highest score
    SC temp = *team1;
    *team1 = *team2;
    *team2 = temp;
}

void write_data(FILE *fout, SC table[], int number_of_teams)
{
    fprintf(fout, "| Rank | Team Name            | Wins | Draws | Losses | Goals Scored | Goals Conceded | Points | Goal Difference |\n");
    fprintf(fout, "|------|----------------------|------|-------|--------|--------------|----------------|--------|-----------------|\n");
    for (int i = 0; i < number_of_teams; i++) {
        fprintf(fout, "| %-4d | %-20s | %4d | %5d | %6d | %12d | %14d | %6d | %15d |\n",
                i+1,
                table[i].name,
                table[i].win,
                table[i].draw,
                table[i].loss,
                table[i].GF,
                table[i].GA,
                table[i].score,
                table[i].point_diff);
    }
}
