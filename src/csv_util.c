#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 255

/**
 * @brief write_csv takes two parameters, a filehandle and a data-string and appends the data at the end of the file in a new line.
 *
 * @param file Filehandle of target csv-file to write to.
 * @param data Data that should be added as a new line to the csv-file.
 * @return int Returns the number of successful written characters.
 */
int write_csv(FILE *file, char *data)
{
    char *extend_data = malloc(sizeof(data) + 2);
    if (extend_data == NULL)
    {
        printf("Erros allocating memory!\n");
        return 0;
    }
    strcpy(extend_data, data);
    strcat(extend_data, "\n");
    return fprintf(file, extend_data);
}

/**
 * @brief Prints the content of a given csv-file. The filehandle to the csv-file must be given in the parameter.
 *
 * @param file Filehandle of the csv-file that should be printed.
 * @return int Returns 0 if successfully printed, -1 if an error occurred.
 */
int print_csv(FILE *file)
{
    printf("1\n");
    char buffer[BUFFER];

    if (file == NULL)
    {
        printf("\nNo file given!\n");
        return -1;
    }
    else
    {
        printf("2\n");
        while ((fgets(buffer, BUFFER, file)) != NULL)
        {
            printf("3\n");
            char *token = strtok(buffer, ",");

            while (token != NULL)
            {
                printf("4\n");
                printf(" %s", token);
                token = strtok(NULL, ",");
            }
        }
    }
    return 0;
}
