TARGET = project
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
LDFLAGS = -fPIC
SRC = calculator.c add.c divide.c multiply.c subtract.c
OBJ = $(SRC:.c=.o)
OBJ_LIB = add.o divide.o multiply.o subtract.o
LIBR = libcalculator.so
HDR = calculator.h

.PHONY: all clean start

all: $(TARGET)

$(TARGET): $(OBJ) | $(LIBR)
		$(CC) $(CFLAGS) -L. $^ -o $@

%.o: %.c
		$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(LIBR): $(OBJ_LIB)
		$(CC) -shared -o $@ $^

$(OBJ): $(HDR)

clean:
		rm -f $(TARGET) $(OBJ) $(LIBR)

start:
		LD_LIBRARY_PATH="$PWD:LD_LIBRARY_PATH" ./$(TARGET)
