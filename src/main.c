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
    // initialisiere Feld mit den Namen der Patienten
    char **seats = malloc(NUM_SEATS * sizeof(char *));
    char **queue = malloc(NUM_SEATS * sizeof(char *));

    int choice;

    for (int i = 0; i < NUM_SEATS; i++)
    {
        seats[i] = NULL; // Initialize all seats as empty
    }

    // Hauptschleife des Programms

    do
    {
        print_menu();
        scanf("%d", &choice);
        // clear_input_buffer();

        switch (choice)
        {
        case 1:
        {
            char name[100];
            printf("Enter the patient's name: ");
            scanf("%s", name);

            char answer;
            printf("Ambulance patient? Y/N\n");
            scanf(" %c", &answer);

            if (answer == 'Y')
            {
                // Adding high priority patient
                addToQueue(queue, name, 1);
                printf("added emergency patient %s",name);
            }
            else
            {
                // Adding normal patient + seating
                addToQueue(queue, name, 0);
                assignSeats(seats, name);
            }

            break;
        }
        case 2:
        {

            callPatient(seats, queue);
            break;
        }
        case 3:
        {
            printField(seats);
            printQueue(queue);
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
    for (int i = 0; i < NUM_SEATS; i++)
    {
        free(seats[i]);
    }
    free(seats);

    // Free the allocated memory
    for (int i = 0; i < NUM_SEATS; i++)
    {
        free(queue[i]);
    }
    free(queue);

    return 0;
}