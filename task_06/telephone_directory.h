
#ifndef TELEPHONE_DIRECTORY_H
#define TELEPHONE_DIRECTORY_H
#include <malloc.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Программа телефонный справочник */
struct phone_directory {
    char name[50];
    char surname[100];
    char phone_number[15];
    struct phone_directory *next;
};

extern struct phone_directory *head;

// Добавление абонента
void add_subscriber();
// Удаление абонента по номеру телефона
void delete_subscriber(struct phone_directory **head, char *phone_number);
// поиск абонента/абонентов по имени или фамилии или номеру телефона
void find_subscriber();
// Вывод телефонного справочника
void output_telephone_directory();

#endif  // TELEPHONE_DIRECTORY_H

