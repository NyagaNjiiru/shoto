#include <string.h>
#include <stdio.h>
#include <time.h>
#include "shoto.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: shoto <command> [args]\n");
        return 1;
    }
    if (strcmp(argv[1], "focus") == 0) {
        if (argc < 3) {
            printf("shoto focus: what are you focusing on?\n");
            return 1;
        }

        // Store focus intent and get current timestamp
        char *intent = argv[2];
        time_t start_time = time(NULL);

        // Open file
        FILE *file = fopen(".shoto_active", "w");
        if (file == NULL) {
            printf("Error: couldn't create session fiel\n");
            return 1;
        }

        fprintf(file, "%ld|%s\n", start_time, intent);
        fclose(file);

        // Confirmation message to user
        printf("Focusing on: %s\n", intent);
    }
}
