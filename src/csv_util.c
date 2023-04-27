#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief The add_csv_fileextension function takes a given string, adds the ".csv" file extension to it and returns the new string/filename. There will be memory allocated which has to be freed after usage.
 *
 * @param name Name of the file without the file extension.
 * @return char* Returns the filename with the appended ".csv" file extension.
 */
char *add_csv_fileextension(char *name)
{
    /* Allocating memory for new string */
    char *filename = calloc(strlen(name) + 5, sizeof(char));

    /* Copy the name into the new string and append the ".csv" file extension to it */
    strcpy(filename, name);
    strcat(filename, ".csv");

    return filename;
}

/**
 * @brief The write_to_csv function appends given data to a given file.
 *
 * @param filename The name of the file to write to.
 * @param data The data that should be written.
 * @return size_t Returns the number of characters written including the new line character written at the end of the data.
 */
size_t write_to_csv(char *filename, char *data)
{
    /* Open the file */
    FILE *file = fopen(filename, "a");
    if (!file)
    {
        // printf("Error: An error occured while opening file \"%s\"!\n", filename);
        return 0;
    }

    /* Counter of written data */
    size_t cnt = 0;

    /* Write data to file */
    cnt = fwrite(data, sizeof(char), strlen(data), file);
    cnt += fwrite("\n", sizeof(char), 1, file);

    /* Close the file */
    fclose(file);

    return cnt;
}

/**
 * @brief The print_file function prints the content of a file with a given name to the stdout.
 *
 * @param filename The name of the file which should be printed.
 * @return size_t Returns the number of characters read and printed from the file.
 */
size_t print_file(char *filename)
{
    /* Open the file */
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        // printf("Error: An error occured while opening file \"%s\"!\n", filename);
        return 0;
    }

    /* Get the size of the file */
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    /* Allocate buffer */
    char *buffer = calloc(1, file_size);

    /* Read the data from file */
    fread(buffer, file_size, 1, file);

    /* Print the data */
    printf("%s", buffer);

    /* Close the file */
    fclose(file);

    return file_size;
}

/**
 * @brief Adds the first person to the list of neighbors of the second person and vice versa.
 *
 * @param first_person Name of the first person.
 * @param sec_person Name of the second person.
 * 
 * @return int Returns 0 if successful, -1 if neighbors could not be added.
 */
int add_neighbors(char *first_person, char *sec_person)
{
    /* Add file extensions */
    char *new_first = add_csv_fileextension(first_person);
    char *new_sec = add_csv_fileextension(sec_person);

    /* Write neighbors in both directions */
    if (!write_to_csv(new_first, new_sec) || !write_to_csv(new_sec, new_first))
    {
        return -1;
    }

    /* Free allocated memory */
    free(new_first);
    free(new_sec);

    return 0;
}

void print_neighbors(char *name)
{
    /* Add file extension */
    char *filename = add_csv_fileextension(name);

    if (!print_file(filename))
    {
        printf("%s had no neighbors.\n", name);
    }
}