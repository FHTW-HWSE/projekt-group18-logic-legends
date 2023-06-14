#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "csv_util.h"

#define NUM_SEATS 25

void assignSeats(char** seats, const char* name) {
    int i = 0;
    while (seats[i] != NULL) {
        i++;
    }

    seats[i] = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(seats[i], name);
    printf("Seat %d assigned to %s.\n", i + 1, seats[i]);

    int temp = i % 5;
    switch (temp)
    {
    case 0:
        if (seats[i + 1] != NULL)
        {
            add_neighbors(seats[i], seats[i + 1]);
        }
        break;

    case 4:
        if (seats[i - 1] != NULL)
        {
            add_neighbors(seats[i], seats[i - 1]);
        }
        break;
    
    case 1:
    case 2:
    case 3:
        if (seats[i - 1] != NULL)
        {
            add_neighbors(seats[i], seats[i - 1]);
        }
        if (seats[i + 1] != NULL)
        {
            add_neighbors(seats[i], seats[i + 1]);
        }
        break;
        
    default:
        break;
    }
}

void removePatient(char** seats, const char* name) {
    int i = 0;
    while (seats[i] != NULL) {
        if (strcmp(seats[i], name) == 0) {
            free(seats[i]);  // Free memory for the removed patient
            seats[i] = NULL; // Set the seat as empty
            break;           // Exit the loop after removing the first occurrence
        }
        i++;
    }
}


void printField(char** seats) {
    printf("Field:\n");
    int row = 0;
    int col = 0;
    for (int i = 0; i < NUM_SEATS; i++) {
        if (seats[i] != NULL) {
            printf("%-12s", seats[i]);
        } else {
            printf("%-12s", "Empty");
        }

        col++;
        if (col == 5) {
            printf("\n");
            col = 0;
            row++;
        }
    }
    printf("\n");
}
