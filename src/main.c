#include "csv_util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "patient_utils.h"

#define NAME "Jakob Gridl"
#define FILENAME "Jakob Gridl.csv"

int main(void)
{
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
    return 0;
}