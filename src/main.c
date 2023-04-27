#include "csv_util.h"
#include <stdlib.h>

int main()
{
    char *me = "Jakob Gridl";
    char *you = "Valerie Karner";

    add_neighbors(me, you);
    printf("Neighbors of %s:\n", me);
    print_neighbors(me);
    printf("Neighbors of %s:\n", you);
    print_neighbors(you);
    printf("Neighbors of %s:\n", "ABC");
    print_neighbors("ABC");
    return 0;
}