#include "csv_util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient_utils.h"
#include "assignRemove.h"
#define NUM_SEATS 25




int main(void)
{   
    //initialisiere Feld mit den Namen der Patienten
    char** seats = malloc(NUM_SEATS * sizeof(char*));
    char* test= "SAMUel";
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
                    char name[100];
                    printf("Enter the patient's name: ");
                    scanf("%s", name);
                    assignSeats(seats, name);
                    break;
                }
            case 2:
                {
                    char name[100];
                    printf("Enter the patient's name to remove: ");
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
                    // Implement the logic to show seat neighbors
                    break;
                }
            case 5:
                {
                    printf("The program will be ended.\n");
                    break;
                }
            default:
                {
                    printf("Invalid input. Please choose again.\n");
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

   
    // END SERT UTIL

  /*  char *patient_name = getPatientName(2);
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
*/



}