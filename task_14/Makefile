TARGETS = project1 project2
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
SRC = fork_1.c fork_2.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean

all: $(TARGETS)

project1: fork_1.o
	$(CC) $(CFLAGS) $< -o $@

project2: fork_2.o
	$(CC) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGETS)










# TARGETS = project1 project2
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -std=c99
# # Список исходных файлов
# SRC = fork_1.c fork_2.c
# # Список объектных файлов
# OBJ = fork_1.o fork_2.o

# .PHONY: all clean start

# all: $(TARGETS)

# project1: fork_1.o
# 		$(CC) $(CFLAGS) $< -o $@

# project2: fork_2.o
# 		$(CC) $(CFLAGS) $< -o $@

# %.o: %.c
# 		$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 		rm -f *.o $(TARGETS)

# start:
# 		./project1 ./project2
