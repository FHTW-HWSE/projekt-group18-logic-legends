#include "csv_util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME "Jakob Gridl"
#define FILENAME "Jakob Gridl.csv"

int main(void) {
    
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