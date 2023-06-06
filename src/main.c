#include "csv_util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient_utils.h"

#define NUM_SEATS 25
#define NAME "Jakob Gridl"
#define FILENAME "Jakob Gridl.csv"

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

int main(void)
{   
    //initialisiere Feld mit den Namen der Patienten
    char** seats = malloc(NUM_SEATS * sizeof(char*));

    for (int i = 0; i < NUM_SEATS; i++) {
        seats[i] = NULL; // Initialize all seats as empty
    }

    // SERT UTIL
    // Hauptschleife des Programms
    int choice;
    do
    {
        print_menu();
        scanf("%d", &choice);
        // clear_input_buffer();

        switch (choice)
        {
        case 1:
            addPatientName();
            break;
        case 2:
            remove_patient();
            break;
        case 3:
            list_patients();
            break;
        case 4:
            find_neighbors();
            break;
        case 5:
            printf("Das Programm wird beendet.\n");
            break;
        default:
            printf("Ungueltige Eingabe. Bitte waehlen Sie erneut.\n");
            break;
        }
    } while (choice != 5);
    // END SERT UTIL

    char *patient_name = getPatientName(2);
    if (patient_name != NULL)
    {
        printf("Patient name at index 2: %s\n", patient_name);
    }
    else
    {
        printf("Failed to retrieve patient name at index 2.\n");
    }

    char *filename;
    strcpy(filename, NAME);
    strcat(filename, ".csv");
    FILE *file = fopen(filename, "a+");
    if (file == NULL)
    {
        printf("Error opening file!\n");
    }

    printf("written: %d chars\n", write_csv(file, "Vinzent,Karner"));
    fprintf(file, "Vera,Karner");

    fflush(file);

    print_csv(filename);

    fclose(file);


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
