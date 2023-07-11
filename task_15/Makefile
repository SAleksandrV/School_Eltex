TARGET = project
CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lncurses
OBJ = manager.o display.o
SRC = manager.c display.c
HDR = manager.h

.PHONE: all clean start

all: $(TARGET)

$(TARGET): $(OBJ)
		$(CC) $(CFLAGS)  $^ -o $@ $(LDFLAGS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): $(HDR)

clean:
		rm -f $(TARGET) $(OBJ)

start:
		./$(TARGET)
