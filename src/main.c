#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_SEATS 25

void assignSeats(char** seats, const char* name) {
    int i = 0;
    while (seats[i] != NULL) {
        i++;
    }

    seats[i] = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(seats[i], name);
    printf("Seat %d assigned to %s.\n", i + 1, seats[i]);
}

void printField(char** seats) {
    printf("Field:\n");
    int i = 0;
    while (seats[i] != NULL) {
        printf("%-12s", seats[i]);
        i++;
        if (i % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void removePatient(char** seats, const char* name) {
    int i = 0;
    while (seats[i] != NULL) {
        if (strcmp(seats[i], name) == 0) {
            free(seats[i]);  // Free memory for the removed patient
            // Shift the remaining seats to fill the gap
            for (int j = i; seats[j] != NULL; j++) {
                seats[j] = seats[j + 1];
            }
        } else {
            i++;
        }
    }
}

int main() {
    char** seats = malloc(NUM_SEATS * sizeof(char*));

    for (int i = 0; i < NUM_SEATS; i++) {
        seats[i] = NULL; // Initialize all seats as empty
    }

    assignSeats(seats, "Samuel");
    assignSeats(seats, "Samuel1");
    assignSeats(seats, "Samuel2");
    assignSeats(seats, "Samuel3");
    assignSeats(seats, "Samuel4");
    assignSeats(seats, "Samuel5");
    assignSeats(seats, "Samuel6");
    assignSeats(seats, "Samuel7");

    printField(seats);

    removePatient(seats, "Samuel");

    printField(seats);
    assignSeats(seats, "Samuel");

    // Reallocate memory to fit the remaining seats
    int numRemainingSeats = 0;
    while (seats[numRemainingSeats] != NULL) {
        numRemainingSeats++;
    }
    seats = realloc(seats, (numRemainingSeats + 1) * sizeof(char*));

    // Free the allocated memory
    for (int i = 0; i <= numRemainingSeats; i++) {
        free(seats[i]);
    }
    free(seats);

    return 0;
}
