TARGET = project
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
SRC = file.c
OBJ = file.o

.PHONY: all clean start

all: $(TARGET)

$(TARGET): $(OBJ)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(TARGET) $(OBJ)

start:
		./$(TARGET) test.txt
