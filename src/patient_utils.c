#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPATEINTLEN 255
#define MAXPATIENTS 25

// START 
char patientNames[MAXPATIENTS][MAXPATEINTLEN];

/**
 * @brief write_csv takes two parameters, a filehandle and a data-string and appends the data at the end of the file in a new line.
 *
 * @param patienname
 * @return int Returns the number of successful written characters.
 */

void print_menu()
{
    printf("\n--- Notaufnahme-Verwaltungsprogramm ---\n");
    printf("1. Patient hinzufuegen\n");
    printf("2. Patient entfernen\n");
    printf("3. Patientenliste anzeigen\n");
    printf("4. Sitznachbarn suchen\n");
    printf("5. Programm beenden\n");
    printf("Waehlen Sie eine Option: ");
}

void addPatientName()
{
    char new_patient[MAXPATEINTLEN];
    printf("\nBitte geben Sie den Namen des Patienten ein: ");
    fgets(new_patient, MAXPATEINTLEN, stdin);
    new_patient[strcspn(new_patient, "\n")] = '\0';
    // Copy the new patient name to the patientNames array
    size_t num_patients = sizeof(patientNames) / sizeof(patientNames[0]);
    strcpy(patientNames[num_patients + 1], new_patient);
}

char *getPatientName(int sitzplatz)
{
    if (sitzplatz >= MAXPATIENTS || sitzplatz < 0)
    {
        printf("Error: Sitzplatz gibts nicht\n");
        return NULL;
    }
    return patientNames[sitzplatz];
}

void getPatientNames()
{
    // Patienten durchloopen ausgeben
}