#include <stdio.h>
#include <pthread.h>


#define SIZE 1000

void *increment(void* args);

long int number = 100000;

int main(void) {
    int i, array[SIZE], *s;
    pthread_t thread[SIZE];

    for (int i = 0; i < SIZE; i++) {
        array[i] = i;
        pthread_create(&thread[i], NULL, increment, (void *) &array[i]);
    }

    for (int i = 0; i < SIZE; i++) {
        pthread_join(thread[i], (void **)&s);
    }
    printf("%ld\n", number);
    return 0;
}



void *increment(void* args) {
    number += 100000;
    printf("%ld\n", number);
    return NULL;
}
