#pragma once
#include <stdio.h>

/**
 * @brief write_csv takes two parameters, a filehandle and a data-string and appends the data at the end of the file in a new line.
 *
 * @param file Filehandle of target csv-file to write to.
 * @param data Data that should be added as a new line to the csv-file.
 * @return int Returns the number of characters written successfully, -1 if an error occurred.
 */
int write_csv(void *file, char *data)
{
    int char_written = 0;

    // TODO: write to file, count characters written in char_written

    return char_written;
}

/**
 * @brief Prints the content of a given csv-file. The filehandle to the csv-file must be given in the parameter.
 * 
 * @param file Filehandle of the csv-file that should be printed.
 * @return int Returns 0 if successfully printed, -1 if an error occurred.
 */
int print_csv(void *file)
{
    //TODO: print content to stdout

    return 0;
}
