TARGET = project
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
SRC = telephone_directory.c add.c delete.c find.c output.c
OBJ = telephone_directory.o add.o delete.o find.o output.o
HDR = telephone_directory.h

.PHONE: all clean start

all: $(TARGET)

$(TARGET): $(OBJ)
		$(CC) $(CFLAGS)  $^ -o $@

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): $(HDR)

clean:
		rm -f $(TARGET) $(OBJ)

start:
		./$(TARGET)
