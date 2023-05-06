CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TARGET = seating

.PHONY: all clean

all: $(TARGET)

$(TARGET): main.o assignSeats.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

assignSeats.o: assignSeats.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o

	