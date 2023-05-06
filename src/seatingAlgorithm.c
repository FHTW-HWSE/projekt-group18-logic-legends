#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seatingAlgorithm.h"

void assignSeats(char*** seats, int row, int col, const char* name) {
    if ((*seats)[row][col] != NULL) {
        printf("Seat %d-%d is already assigned.\n", row, col);
    } else {
        (*seats)[row][col] = malloc((strlen(name) + 1) * sizeof(char));
        strcpy((*seats)[row][col], name);
        printf("Seat %d-%d assigned to %s.\n", row, col, (*seats)[row][col]);
    }
}

void printField(char*** seats, int numRows, int numCols) {
    printf("Field:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if ((*seats)[i][j] != NULL) {
                printf("Seat %d-%d: %s\n", i, j, (*seats)[i][j]);
            } else {
                printf("Seat %d-%d: Empty\n", i, j);
            }
        }
    }
}

void freeField(char*** seats, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            free((*seats)[i][j]);
        }
        free((*seats)[i]);
    }
    free(*seats);
    *seats = NULL;
}
