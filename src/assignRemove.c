#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "assignRemove.h"
#include "csv_util.h"

#define NUM_SEATS 25

void addToQueue(char **queue, const char *name, int prio)
{
    if (prio == 1)
    {
        // adding prio queue
        // Queue empty?
        if (queue[0] == NULL)
        {
            queue[0] = malloc((strlen(name) + 1) * sizeof(char));
            strcpy(queue[0], name);
            // Terminate the string in the queue
            queue[0][strlen(name)] = '\0';
        }
        else
        {
            // Shifting the patients by 1
            int i = 0;
            while (queue[i] != NULL)
            {
                i++;
            }
            for (i; i >= 1; i--)
            {
                queue[i] = realloc(queue[i], (strlen(queue[i - 1])));
                strcpy(queue[i], queue[i - 1]);
            }
            strcpy(queue[0], name);
            // Terminate the string in the queue
            queue[0][strlen(name)] = '\0';
        }
    }
    else
    {
        //normal patient
        int i = 0;

        while (queue[i] != NULL && i < 25)
        {
            i++;
        
        }
        queue[i] = malloc((strlen(name) + 1) * sizeof(char));
        strcpy(queue[i], name);
        queue[i][strlen(name)] = '\0';
    }
}

void printQueue(char **queue)
{
    printf("nextinLine:\n");

    for ( int i = 0; i < 25; i++)
    {
       printf("%-12s\n", queue[i]);
    }
    

    /*int i=0;
    while (queue[i]!=NULL)
    {
        printf("%-12s\n", queue[i]);
        i++;
        if (queue[i]=NULL)
        {
           puts("no patients");
        }
    }

*/

}

void assignSeats(char **seats, const char *name)
{
    int i = 0;
    while (seats[i] != NULL)
    {
        i++;
    }

    seats[i] = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(seats[i], name);
    // Terminate the string
    seats[0][strlen(name)] = '\0';
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

void callPatient(char **seats, char **queue)
{
    // remove the patient also from the queue

    // Check if the queue is empty
    if (queue[0] != NULL) {
        printf("Calling patient: %s\n", queue[0]);

        // Find the matching name in the seats array and set it to NULL
        for (int i = 0; i<NUM_SEATS; i++) {
            if (strcmp(seats[i], queue[0]) == 0) {
                seats[i] = NULL;
                free(seats[i]);
                break;
            }
        }
        

        // Shift the remaining patients in the queue
        int i = 0;
        
        while (queue[i] != NULL && queue[i+1] != NULL){

            
            queue[i]=realloc(queue[i],strlen(queue[i+1]));
            strcpy(queue[i], queue[i + 1]);
            i++;
            
        }
        

        // Clear the last element of the queue
        queue[i] = NULL;
        free(queue[i]);
    }

}

void printField(char **seats)
{
    printf("Field:\n");
    int row = 0;
    int col = 0;
    for (int i = 0; i < NUM_SEATS; i++)
    {
        if (seats[i] != NULL)
        {
            printf("%-12s", seats[i]);
        }
        else
        {
            printf("%-12s", "Empty");
        }

        col++;
        if (col == 5)
        {
            printf("\n");
            col = 0;
            row++;
        }
    }
    printf("\n");
}
