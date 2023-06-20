#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 3

/* Программа телефонный справочник */
struct phone_directory {
    char name[50];
    char surname[100];
    char phone_number[15];
};

// Добавление абонента
void add_subscriber(struct phone_directory *group, int *count);
// Удаление абонента по фамилии
void delete_subscriber(struct phone_directory *group, int *count);
// поиск абонента/абонентов по имени или фамилии или номеру телефона

// Вывод телефонного справочника
void output_telephone_directory(struct phone_directory *group, int *count);

int main(void) {
    struct phone_directory group[SIZE];
    int count = 0, number;
    while (1) {
        printf("\n\tCHOOSE WHAT YOU WANT TO DO:\n1 - Add a subscriber\n2 - Delete the subscriber\n\
3 - Find a subscriber\n4 - View the entire phone directory\n5 - Close the phone directory\n");
        scanf("%d", &number);
        switch (number) {
            case 1:
                printf("Adding a subscriber to the phone directory\n");
                add_subscriber(group, &count);
                break;
            case 2:
                printf("We remove the subscriber from the telephone directory\n");
                delete_subscriber(group, &count);
                break;
            case 3:
                printf("Pass");
                // find();
                break;
            case 4:
                printf("Viewing the entire phone directory\n");
                output_telephone_directory(group, &count);
                break;
            case 5:
                printf("The phone directory is closed\n");
                exit(0);
            default:
                printf("Repeat the input\n");
                break;
        }
    }
    return 0;
}


void add_subscriber(struct phone_directory *group, int *count) {
    if (*count == SIZE) {
        printf("\n\tThe phone directory is full\n");
    } else {
        printf("Input name subscriber:\t\t");
        scanf("%s", group[*count].name);
        printf("Input last name subscriber:\t");
        scanf("%s", group[*count].surname);
        printf("Input phone_number:\t\t");
        scanf("%s", group[*count].phone_number);
        printf("\n\tSubscriber added\nNAME\t\t %s\nLAST NAME\t %s\nPHONE NUMBER\t %s\n", group[*count].name, group[*count].surname, group[*count].phone_number);
        *count = *count + 1;
    }
}

void delete_subscriber(struct phone_directory *group, int *count) {
    char phone_number[15];
    int i, j, temp = 0;
    if (*count == 0) {
        printf("\n\tThe phone directory is empty\n");
    } else {
        printf("Enter the phone_number of the subscriber to delete:\t");
        scanf("%s", phone_number);
        for (i = 0; i < *count; i++) {
            if (strcmp(phone_number, group[i].phone_number) == 0) {
                for (j = i; j < *count - 1; j++) {
                    strcpy(group[j].name, group[j + 1].name);
                    strcpy(group[j].surname, group[j + 1].surname);
                    strcpy(group[j].phone_number, group[j + 1].phone_number);
                }
                strcpy(group[*count - 1].name, "");
                strcpy(group[*count - 1].surname, "");
                strcpy(group[*count - 1].phone_number, "");
                *count = *count - 1;
                temp = 1;
            }
        }
    }
    if (temp) {
        printf("\n\tSubscriber PHONE NUMBER\t %s delete\n", phone_number);
    } else {
        printf("\n\tSubscriber PHONE NUMBER \t%s - not in the phone directory\n", phone_number);
    }
}

void output_telephone_directory(struct phone_directory *group, int *count) {
    if (*count == 0) {
        printf("\n\tThe phone directory is empty\n");
    } else {
        printf("\t\tTELEPHONE DIRECTORY\n");
        printf("No\tNAME\t\t\tLAST NAME\t\t\t\tPHONE NUMBER\n");
        for (int i = 0; i < *count; i++) {
            printf("%d\t%-20s\t%-50s %-20s\n", i + 1, group[i].name, group[i].surname, group[i].phone_number);
        }
    }

}


