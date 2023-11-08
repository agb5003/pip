#include <stdio.h>

#define NAME_LEN 100
#define N_PEOPLE 3

/* Definition of structure person */
struct person {
    char name[NAME_LEN];
    double height;
    double weight;
};

int main() {   
    /* (1) variable declaration */
    struct person member[N_PEOPLE];
    float avg_height = 0.0, avg_weight = 0.0;
    for (int i = 0; i < N_PEOPLE; i++) {
    	/* (2) processing contents */
    	/* data input */
    	printf("Name? ");
    	fgets(member[i].name, sizeof(member[i].name),stdin);
    	printf("Height? ");
    	scanf("%lf", &member[i].height);
	avg_height += (float) member[i].height / N_PEOPLE;

    	printf("Weight? ");
    	scanf("%lf", &member[i].weight);
	avg_weight += (float) member[i].weight / N_PEOPLE;

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
    
    return 0;
}
