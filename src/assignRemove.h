#ifndef ASSIGN_REMOVE_H
#define ASSIGN_REMOVE_H

extern const int NUM_SEATS;  // Declare the constant number of seats

void assignSeats(char** seats, const char* name);
void printField(char** seats);
void addToQueue(char ** queue, const char * name, int prio);
void printQueue(char ** queue);

void callPatient(char **seats, char **queue);

#endif  /* ASSIGN_REMOVE_H */


