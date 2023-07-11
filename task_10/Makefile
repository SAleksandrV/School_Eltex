TARGET = project
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
LDFLAGS = -fPIC
SRC = calculator.c add.c divide.c multiply.c subtract.c
OBJ = $(SRC:.c=.o)
ADD = libadd.so
DIVIDE = libdivide.so
MULTIPLY = libmultiply.so
SUBTRACT = libsubtract.so
HDR = calculator.h

.PHONY: all clean start

all: $(TARGET)

$(TARGET): $(OBJ) $(ADD) $(DIVIDE) $(MULTIPLY) $(SUBTRACT)
		$(CC) $(CFLAGS) -L. $^ -o $@

%.o: %.c
		$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(ADD): add.o
		$(CC) -shared -o $(ADD) add.o

$(DIVIDE): divide.o
		$(CC) -shared -o $(DIVIDE) divide.o

$(MULTIPLY): multiply.o
		$(CC) -shared -o $(MULTIPLY) multiply.o

$(SUBTRACT): subtract.o
		$(CC) -shared -o $(SUBTRACT) subtract.o

$(OBJ): $(HDR)

clean:
		rm -f $(TARGET) $(OBJ) $(ADD) $(DIVIDE) $(MULTIPLY) $(SUBTRACT)

start:
		LD_LIBRARY_PATH="$PWD:$LD_LIBRARY_PATH" ./$(TARGET)


# Пытался уменьшить код, объеденить создание библиотек
# TARGET = project
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -std=c99
# LDFLAGS = -fPIC
# SRC = calculator.c add.c divide.c multiply.c subtract.c
# OBJ = $(SRC:.c=.o)
# LIBS = libadd.so libdivide.so libmultiply.so libsubtract.so
# HDR = calculator.h

# .PHONY: all clean start

# all: $(TARGET)
# $(TARGET): $(OBJ) $(LIBS)
# 		$(CC) $(CFLAGS) -L. $^ -o $@

# %.o: %.c
# 		$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

# $(LIBS): %.so: %.o
# 		$(CC) -shared -o $@ $<

# $(OBJ): $(HDR)

# clean:
# 		rm -f $(TARGET) $(OBJ) $(LIBS)

# start:
# 		LD_LIBRARY_PATH="$PWD:$LD_LIBRARY_PATH" ./$(TARGET)
