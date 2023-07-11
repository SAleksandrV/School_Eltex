#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    pid_t child_pid;
    int status;
    printf("main program\n");
    child_pid = fork();
    if (child_pid == 0) {
        printf("Child pid = %d\n", getpid());
        char *args[] = {"./test", NULL}; // Аргументы программы ./test
        execvp(args[0], args); // Запуск программы ./test
        exit(5);
    } else {
        printf("Parent pid = %d\n", getpid());
        wait(&status);
        printf("Status = %d\n", WEXITSTATUS(status));
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    pid_t child_pid;
    int status;
    // аргументы для передачи программе
    // char* args[] = {"./editor", "/mnt/c/Users/Administrator/Documents/GitHub/School_Eltex/task_15", NULL};
    char* args[] = {"./editor", NULL};
    child_pid = fork();
    if (child_pid == 0) {
        execvp(args[0], args);  // запуск программы с аргументами
        exit(5);
    } else {
        wait(&status);
    }
    return 0;
}