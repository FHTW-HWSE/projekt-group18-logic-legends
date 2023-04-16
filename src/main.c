#include "csv_util.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    
    char *filename = strcat("Jakob Gridl", ".csv");

    FILE *file = fopen(filename, "a+");

    write_csv(file, "\nVinzent,Karner");
    fprintf(file, "\nVera,Karner");

    print_csv(file);

    fclose(file);

    return 0;
}