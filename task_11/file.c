#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

# define BUFFER_SIZE 64

/* Программа открывает файл передаваемый программе (если его нет, создаёт) в текущей дирректории
    читает данные из файла и допысывает данные в файл
*/

int main(int argc, char *argv[])
{
    char buffer[BUFFER_SIZE + 1];
    int file, flags = O_RDWR | O_CREAT;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    ssize_t read_bytes, write_bytes;

    if (argc < 2)
    {
        printf("Not enough command line arguments\n");
        exit(EXIT_FAILURE);
    }

    file = open(argv[1], flags, mode);
    if (file < 0)
    {
        printf("The file did not open\n");
        exit(EXIT_FAILURE);
    }

    while ((read_bytes = read (file, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[read_bytes] = '\0';
        printf("%s\n", buffer);
    }
    if (read_bytes < 0)
    {
        printf("Cannot read file\n");
        close(file);
        exit(EXIT_FAILURE);
    }

    strcpy(buffer, "Training and work!\n");
    write_bytes = write(file, buffer, strlen(buffer));
    if (write_bytes < 0)
    {
        printf("Error when writing to a file\n");
        close(file);
        exit(EXIT_FAILURE);
    }

    if (write_bytes < strlen(buffer))
    {
        printf("Error when writing to a file\n");
        close(file);
    } else {
        printf("Successfully written %ld bytes\n", write_bytes);
    }
    close(file);
    if (close(file) != 0)
    {
        printf("Cannot close file (descriptor = %d)\n", file);
        exit(EXIT_FAILURE);
    }
    return 0;
}
