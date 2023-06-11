#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <catch2/catch.hpp>

#define NUM_SEATS 25

void assignSeats(char** seats, const char* name) {
    int i = 0;
    while (seats[i] != NULL) {
        i++;
    }

    seats[i] = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(seats[i], name);
    printf("Seat %d assigned to %s.\n", i + 1, seats[i]);
}

void removePatient(char** seats, const char* name) {
    int i = 0;
    while (seats[i] != NULL) {
        if (strcmp(seats[i], name) == 0) {
            free(seats[i]);
            seats[i] = NULL;
            break;
        }
        i++;
    }
}


TEST_CASE("Assigning a seat", "[assignSeats]") {
    char* seats[NUM_SEATS + 1] = { NULL };

    SECTION("Assign a seat to a patient") {
        assignSeats(seats, "Jakob Gridl");
        REQUIRE(seats[0] != NULL);
        REQUIRE(strcmp(seats[0], "Jakob Gridl") == 0);
    }

    SECTION("Assign multiple seats to different patients") {
        assignSeats(seats, "Jakob Gridl");
        assignSeats(seats, "Samuel Bissmann");
        REQUIRE(seats[0] != NULL);
        REQUIRE(strcmp(seats[0], "Jakob Gridl") == 0);
        REQUIRE(seats[1] != NULL);
        REQUIRE(strcmp(seats[1], "Samuel Bissmann") == 0);
    }
}

TEST_CASE("Removing a patient", "[removePatient]") {
    char* seats[NUM_SEATS + 1] = { NULL };
    assignSeats(seats, "Jakob Gridl");
    assignSeats(seats, "Samuel Bissmann");

    SECTION("Remove a patient from a seat") {
        removePatient(seats, "Jakob Gridl");
        REQUIRE(seats[0] == NULL);
    }
}
