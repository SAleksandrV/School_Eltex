
TARGET = project
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
SRC = calculator.c add.c divide.c multiply.c subtract.c
OBJ = $(SRC:.c=.o)
OBJ_LIB = add.o divide.o multiply.o subtract.o
LIBR = libcalculator.a
HDR = calculator.h

.PHONY: all clean start

all: $(TARGET)

$(TARGET): $(OBJ) | $(LIBR)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HDR)
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBR): $(OBJ_LIB)
		ar rcs $@ $^

clean:
		rm -f $(TARGET) $(OBJ) $(LIBR)

start:
		./$(TARGET)