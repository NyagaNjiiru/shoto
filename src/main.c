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
    if (strcmp(argv[1], "done") == 0) {
        FILE *file = fopen(".shoto_active", "r");
        if (file == NULL) {
            printf("No active focus session\n");
            return 1;
        }

        long start_time;
        char intent[256];

        fscanf(file, "%ld|%255[^\n]", &start_time, intent);
        fclose(file);

        time_t end_time = time(NULL);
        long duration = end_time - start_time;

        FILE *log = fopen("shoto_sessions.log", "a");
        if (log == NULL) {
            printf("Error: couldn't write to log\n");
            return 1;
        }

        fprintf(log, "%ld|%s|%ld\n", start_time, intent, duration);
        fclose(log);

        remove(".shoto_active");

        long minutes = duration / 60;
        printf("Session complete: %s\n", intent);
        printf("Duration: %ld minutes\n", minutes);
    }
}
