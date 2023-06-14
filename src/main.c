#include "csv_util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient_utils.h"
#include "assignRemove.h"

#define NUM_SEATS 25
#define NAME_LENGTH 255




int main(void)
{   
    //initialisiere Feld mit den Namen der Patienten
    char** seats = malloc(NUM_SEATS * sizeof(char*));
    int choice;

    for (int i = 0; i < NUM_SEATS; i++) {
        seats[i] = NULL; // Initialize all seats as empty
    }

    // Hauptschleife des Programms

do {
        print_menu();
        scanf("%d", &choice);
        // clear_input_buffer();

        switch (choice) {
            case 1:
                {
                    char name[NAME_LENGTH];
                    printf("\nEnter the patient's name: ");
                    scanf("%s", name);
                    assignSeats(seats, name);
                    break;
                }
            case 2:
                {
                    char name[NAME_LENGTH];
                    printf("\nEnter the patient's name to remove: ");
                    scanf("%s", name);
                    removePatient(seats, name);
                    break;
                }
            case 3:
                {
                    printField(seats);
                    break;
                }
            case 4:
                {
                    char name[NAME_LENGTH];
                    printf("\nEnter the patient's name whos neighbors should be printed: ");
                    scanf("%s", name);
                    printf("\nSitznachbarn von %s:\n\n", name);
                    print_neighbors(name);
                    break;
                }
            case 5:
                {
                    printf("\nThe program will be ended.\n");
                    break;
                }
            default:
                {
                    printf("\nInvalid input. Please choose again.\n");
                    break;
                }
        }
    } while (choice != 5);

    // Free the allocated memory
    for (int i = 0; i < NUM_SEATS; i++) {
        free(seats[i]);
    }
    free(seats);

    return 0;

}
