#ifndef ASSIGN_REMOVE_H
#define ASSIGN_REMOVE_H

extern const int NUM_SEATS;  // Declare the constant number of seats

void assignSeats(char** seats, const char* name);
void removePatient(char** seats, const char* name);
void printField(char** seats);

#endif  /* ASSIGN_REMOVE_H */
