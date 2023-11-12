#include <stdio.h>
#include <string.h>

#define NAME_LEN 100
#define N_PEOPLE 3

/* Definition of structure person */
typedef struct {
    char name[NAME_LEN];
    double height;
    double weight;
} person;

int write_to_file(person member[N_PEOPLE], double avg_height, double avg_weight);

int main() {   
    /* (1) variable declaration */
    person member[N_PEOPLE];
    double avg_height = 0.0, avg_weight = 0.0;
    for (int i = 0; i < N_PEOPLE; i++) {
    	/* (2) processing contents */
    	/* data input */
		printf("Input data for member %d:\n", i+1);
    	printf("Name? ");
    	fgets(member[i].name, sizeof(member[i].name),stdin);
		// Delete newline character at the end of name
		member[i].name[strcspn(member[i].name, "\n")] = 0;

    	printf("Height? ");
    	scanf("%lf", &member[i].height);
		avg_height += member[i].height / N_PEOPLE;

    	printf("Weight? ");
    	scanf("%lf", &member[i].weight);
		avg_weight += member[i].weight / N_PEOPLE;

		// Clear input buffer
		while(getchar() != '\n');
    }
    
    /* data display */
    for (int i = 0; i < N_PEOPLE; i++) {
		printf("----------------------------\n");
		printf("Name:   %s\n",member[i].name);
		printf("Height: %.1f\n",member[i].height);
		printf("Weight: %.1f\n",member[i].weight);
    }

    printf("----------------------------\n");
    printf("Average height of %d people is %f.\n", N_PEOPLE, avg_height);
    printf("Average weight of %d people is %f.\n", N_PEOPLE, avg_weight);

	// Write to file for saving
	write_to_file(member, avg_height, avg_weight);
    
    return 0;
}

int write_to_file(person member[N_PEOPLE], double avg_height, double avg_weight) {
	FILE *file; // declare file

	file = fopen("./members.csv", "w"); // file is a file POINTER, not the file itself.
	// It points to the file for reading or writing purposes, but it doesn't store
	// the data inside the file as its value.

	if (file == NULL) { // fopen returns NULL if it can't open the file.
		printf("Error opening the file for writing data.");
		return 1;
	}

	// Print headers
	fprintf(file, "Name,Height,Weight\n");

	for (int i = 0; i < N_PEOPLE; i++) {
		fprintf(file, "%s,%lf,%lf\n", member[i].name, member[i].height, member[i].weight);
	}

	// Print averages
	fprintf(file, "AVERAGE,%lf,%lf",avg_height,avg_weight);

	if (ferror(file)) {
		printf("Error writing to csv file.\n");
		return 1;
	} else {
		printf("Data written to .csv file!\n");
	}

	fclose(file);

	return 0;
}