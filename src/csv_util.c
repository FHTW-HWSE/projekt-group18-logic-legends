#include <stdio.h>
#include <string.h>

#define BUFFER 255

//fwrite und fread fseek für Speichergröße

/**
 * @brief write_csv takes two parameters, a filehandle and a data-string and appends the data at the end of the file in a new line.
 *
 * @param file Filehandle of target csv-file to write to.
 * @param data Data that should be added as a new line to the csv-file.
 * @return int Returns 0 if written successfully, -1 if an error occurred.
 */
int write_csv(FILE *file, char *data)
{
    fprintf(file, data);

    return 0;
}

/**
 * @brief Prints the content of a given csv-file. The filehandle to the csv-file must be given in the parameter.
 *
 * @param file Filehandle of the csv-file that should be printed.
 * @return int Returns 0 if successfully printed, -1 if an error occurred.
 */
int print_csv(FILE *file)
{
    char buffer[BUFFER];

    if (file == NULL)
    {
        printf("\nNo file given!\n");
        return -1;
    }
    else
    {
        while ((fgets(buffer, BUFFER, file)) != NULL)
        {
            char *token = strtok(buffer, ",");

            while (token != NULL)
            {
                printf(" %s", token);
                token = strtok(NULL, ",");
            }
        }
    }
    return 0;
}
