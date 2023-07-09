#ifndef TELEPHONE_DIRECTORY_H
#define TELEPHONE_DIRECTORY_H
#include <stdio.h>
#include <string.h>

#define SIZE 100


/* Программа телефонный справочник */
struct phone_directory {
    char name[50];
    char surname[100];
    char phone_number[15];
};


// Добавление абонента
void add_subscriber(struct phone_directory *group, int *count);
// Удаление абонента по номеру телефона
void delete_subscriber(struct phone_directory *group, int *count);
// поиск абонента/абонентов по имени или фамилии или номеру телефона
void find_subscriber(struct phone_directory *group, int *count);
// Вывод телефонного справочника
void output_telephone_directory(struct phone_directory *group, int *count);

#endif  // TELEPHONE_DIRECTORY_H