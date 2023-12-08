/*
 Japanese football league ranking file ouput program
 Template：J_score_template1.c
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
void read_data(FILE *fin, SC table[]);
void calc_score(SC *team);
void rank_score(SC table[]);
void swap_SC(SC *team1, SC *team2);
void write_data(FILE *fout, SC table[]);


int main(void)
{
   /* variable declaration */
    FILE *fin; //file pointer for reading file
    FILE *fout; //file pointer for writing file
    SC table[TEAM_NUM]; /* team_score structure type array for storing data */
    int i;
    
    /* processing contents */
    /* Open reading file */
    if((fin = fopen("J_result2023.csv","r"))==NULL){ // open input file
        printf("Can't open file\n");
        exit(1);
    }
    /* Open writing file */
    fout = fopen("J_score.txt","w"); // open output file
 
 
    
    /* (1) Reading file */
    read_data(fin, table);
    
    
    /*（2）Calculating score */
    for(i=0; i< TEAM_NUM; i++){
        calc_score(&table[i]);
    }

    /* （3）Ranking based on score */
    rank_score(table);
    
    // debug
    // for (int i = 0; i < TEAM_NUM; i++) {
    //     printf("[DEBUG] %25s %4d %4d %4d %4d %4d %4d %4d\n", table[i].name, table[i].win, table[i].draw, table[i].loss, table[i].GF, table[i].GA, table[i].score, table[i].point_diff);
    // }
    // printf("[DEBUG] length of table: %lu rows.", sizeof(table)/sizeof(table[0]));


    /*（4) writing ranking file in order*/
    write_data(fout, table);

    /* closing process */
    fclose(fin);  /* close reading file */
    fclose(fout); /* close writing file */

    return(0);
}

/* Reading score file */
void read_data(FILE *fin, SC table[])
{
    /* processing contents
     Read data from the file and assign score into SC structure array table[]
     Note: array 'table' is pointer indicating SC structure type array
     */
    char buffer[DATA_LEN];  // reading buffer (size of this array is maximum of chars in 1 line of csv)
    int i = 0;
    while (fgets(buffer, sizeof(buffer), fin) != NULL) {
        sscanf(buffer, "%[^,],%d,%d,%d,%d,%d", table[i].name, &table[i].win, &table[i].draw, &table[i].loss, &table[i].GF, &table[i].GA);
        i++;
    }
}

/* Calculation of winpoints and goals difference */
void calc_score(SC *team)
{
    /* processing contents
     Argument is pointer to SC type structure．
     Reference to member of SC type struture indicated by pointer,
     calculate winpoints and goals difference, and assign them
     into the members score and point_diff of the same structure
     */
    // Points = wins * 3 + draws * 1 + losses * 0
    team->score = team->win * 3 + team->draw;
    // Point difference = Goals For - Goals Against
    team->point_diff = team->GF - team->GA;
}

/* Ranking based on score */
void rank_score(SC table[])
{
    /* processing contents
     Sorting the structure array of the argument based on the member score 
     of structure. Make the function swap_SC to exchange the contents of 
     structures. 
     Note: array name table is pointer indicating SC type structure 
     */

    // Use selection sort
    for (int i = 0; i < TEAM_NUM-1; i++) {
        int highest_rank_index = i;
        for (int j = i+1; j < TEAM_NUM; j++) {
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

/* Swaping the contents of structure */
void swap_SC(SC *team1, SC *team2)
{
    /* processing contents
     Reference to the member of structures indicated by
     pointers for two SC type structure, and swapping all 
     the members. 
     */

    // Swap places of reference team and team with current highest score
    SC temp = *team1;
    *team1 = *team2;
    *team2 = temp;
}


/* Writing ranking file */
void write_data(FILE *fout, SC table[])
{
    /* processing contents
     SC structure type array of argument has already been sorted by score
     and therefore display with format as they are.
     Note： array name table is pointer indicating SC type structure 
     */

    fprintf(fout, "| Rank | Team Name            | Wins | Draws | Losses | Goals Scored | Goals Conceded | Points | Goal Difference |\n");
    fprintf(fout, "|------|----------------------|------|-------|--------|--------------|----------------|--------|-----------------|\n");
    for (int i = 0; i < TEAM_NUM; i++) {
        fprintf(fout, "| %-4d | %-20s | %4d | %5d | %6d | %12d | %14d | %6d | %15d |\n", i+1, table[i].name, table[i].win, table[i].draw, table[i].loss, table[i].GF, table[i].GA, table[i].score, table[i].point_diff);
    }
}
