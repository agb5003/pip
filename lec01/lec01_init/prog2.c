#include <stdio.h>
#include <string.h>

/* Hospital Patient Tracker */
int main() {
    char first_name[21];
    char last_name[21];
    int yob, age, name_length;

    const int current_year = 2023;

    printf("To begin, please enter your last name.\n");
    scanf("%20s", last_name);
    printf("Next, please enter your first name.\n");
    scanf("%20s", first_name);

    printf("Your name is %s %s, which is %lu characters long (including the space). What year were you born in?\n", first_name, last_name, strlen(first_name) + strlen(last_name) + 1);
    scanf("%d", &yob);

    age = current_year - yob;
    printf("You are %d years old.\n", age);
}