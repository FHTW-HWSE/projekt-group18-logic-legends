#pragma once

#include <stdio.h>

char *add_csv_fileextension(char *name);
size_t write_to_csv(char *filename, char *data);
size_t print_file(char *filename);
void add_neighbors(char *first_person, char *sec_person);
void print_neighbors(char *name);
