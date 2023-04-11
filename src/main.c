#include "csv_util.h"
#include <stdio.h>

int main(void) {
    
    FILE *file = fopen("Jakob_Gridl.csv", "a+");

    write_csv(file, "\nVinzent,Karner");
    fprintf(file, "\nVera,Karner");

    fclose(file);

    FILE *file2 = fopen("Jakob_Gridl.csv", "r");

    print_csv(file2);

    fclose(file2);

    return 0;
}