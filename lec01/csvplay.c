#include <stdio.h>

int main() {
    FILE *csvFile = fopen("data.csv", "w");
    if (csvFile == NULL) {
        perror("Error opening the file");
        return 1;
    }

    // Write the headers (optional)
    fprintf(csvFile, "X, Y\n");

    // Write data to the CSV file for multiple records
    for (int i = 0; i < 5; i++) {
        int x = i;
        double y = 2.0 * i;

        fprintf(csvFile, "%d, %lf\n", x, y);
        printf("Printed\n");
    }

    fclose(csvFile);

    return 0;
}