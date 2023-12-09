#include <dirent.h>
#include <fnmatch.h>
#include <stdio.h>
#include <stdlib.h>

int match_pattern(const char *filename) {
    // Pattern to match "J_resultYYYY.csv" where YYYY is a 4-digit year
    const char *pattern = "J_result[0-9][0-9][0-9][0-9].csv";

    return fnmatch(pattern, filename, 0) == 0;
}

int main() {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(".")) != NULL) {
        printf("Matching files:\n");

        while ((ent = readdir(dir)) != NULL) {
            if (match_pattern(ent->d_name)) {
                printf("%s\n", ent->d_name);
            }
        }

        printf("%d", EXIT_SUCCESS);
        closedir(dir);
    } else {
        perror("Error opening directory");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}