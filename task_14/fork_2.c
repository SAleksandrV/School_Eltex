
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void first_child();
void second_child();

int main() {
    pid_t pid_01, pid_02;
    pid_01 = fork();
    if (pid_01 == 0) {
        first_child();
    } else if (pid_01 > 0) {
        pid_02 = fork();
        if (pid_02 == 0) {
            second_child();
        } else if (pid_02 > 0) {
            printf("I am the parent process, my PID: %d\n", getpid());
            waitpid(pid_02, NULL, 0);
        } else {
            printf("Error when creating the second child process\n");
        }
    } else {
        printf("Error when creating the first child process\n");
    }
return 0;
}

void first_child() {
    pid_t pid_011;
    int status;
    printf("I am the first child main process, my PID: %d\n", getpid());
    pid_011 = fork();
    if (pid_011 == 0) {
        printf("I am the first child of the first child main process, my PID: %d\n", getpid());
        exit(11);
    } else if (pid_011 > 0) {
        wait(&status);
        printf("Status = %d\n", WEXITSTATUS(status));
    } else {
        printf("Error when creating the first child's child process\n");
    }
}

void second_child() {
    pid_t pid_021, pid_022;
    int status;
    printf("I am the second child main process, my PID: %d\n", getpid());
    pid_021 = fork();
    if (pid_021 == 0) {
        printf("I am the first child of the second child main process, my PID: %d\n", getpid());
    } else if (pid_021 > 0) {
        pid_022 = fork();
        if (pid_022 == 0) {
            printf("I am the second child of the second child main process, my PID: %d\n", getpid());
            exit(22);
        } else if (pid_022 > 0) {
            waitpid(pid_022, &status, 0);
            printf("Status = %d\n", WEXITSTATUS(status));
        } else {
            printf("Error when creating the second child's second child process\n");
        }
    } else {
        printf("Error when creating the first child's first child process\n");
    }
}