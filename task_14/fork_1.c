#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    // first variant program
    pid_t child_pid;
    int status;
    child_pid = fork();
    if (child_pid == 0) {
        printf("Child pid = %d. Parent pid = %d\n", getpid(), getppid());
        exit(5);
    } else {
        printf("Parent pid = %d. Parent pid = %d\n", getpid(), getppid());
        wait(&status);
        printf("Status = %d\n\n", WEXITSTATUS(status));
    }

    // second variant program
    int new_pid = fork();
    switch (new_pid) {
        case -1:
            perror("fork");
            return -1;
        case 0:
            printf("Child my pid = %i, returned pid = %i. Parent pid = %d\n", getpid(), new_pid, getppid());
            exit(7);
            break;
        default:
            wait(&status);
            printf("Parent my pid = %i, returned pid = %i status = %d. Parent pid = %d\n", getpid(), new_pid, WEXITSTATUS(status), getppid());
            break;
    }
    return 0;
}

