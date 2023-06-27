#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/* Программа телефонный справочник */
struct phone_directory {
    char name[50];
    char surname[100];
    char phone_number[15];
    struct phone_directory *next;
};

struct phone_directory *head = NULL;

// Добавление абонента
void add_subscriber();
// Удаление абонента по номеру телефона
void delete_subscriber(struct phone_directory **head, char *phone_number);
// поиск абонента/абонентов по имени или фамилии или номеру телефона
void find_subscriber();
// Вывод телефонного справочника
void output_telephone_directory();

int main(void) {
    char phone_number[15];
    int number;
    while (1) {
        printf("\n\tCHOOSE WHAT YOU WANT TO DO:\n1 - Add a subscriber\n2 - Delete the subscriber\n\
3 - Find a subscriber\n4 - View the entire phone directory\n5 - Close the phone directory\n");
        scanf("%d", &number);
        switch (number) {
            case 1:
                add_subscriber();
                break;
            case 2:
                printf("Enter the phone_number of the subscriber to delete:\t");
                scanf("%s", phone_number);
                delete_subscriber(&head, phone_number);
                break;
            case 3:
                find_subscriber();
                break;
            case 4:
                output_telephone_directory();
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


void add_subscriber() {
    struct phone_directory *temp = (struct phone_directory*) malloc(sizeof(struct phone_directory));
    printf("Input name subscriber:\t\t");
    scanf("%s", temp->name);
    printf("Input last name subscriber:\t");
    scanf("%s", temp->surname);
    printf("Input phone_number:\t\t");
    scanf("%s", temp->phone_number);

    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        struct phone_directory *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    printf("\n%s added successfully!\n", temp->name);
}

void delete_subscriber(struct phone_directory **head, char *phone_number) {
    struct phone_directory *current = *head;
    struct phone_directory *previous = NULL;
    if (current != NULL && strcmp(current->phone_number, phone_number) == 0) {
        *head = current->next;
        free(current);
        printf("\n\tSubscriber PHONE NUMBER\t %s delete\n", phone_number);
        return;
    }
    while (current != NULL && strcmp(current->phone_number, phone_number) != 0) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        previous->next = current->next;
        free(current);
        printf("\n\tSubscriber PHONE NUMBER\t %s delete\n", phone_number);
    } else {
        printf("\n\tSubscriber PHONE NUMBER \t%s - not in the phone directory\n", phone_number);
    }
}

void find_subscriber() {
    char name[50], surname[100], phone_number[15];
    struct phone_directory *ptr = head;
     if (head == NULL) {
        printf("\n\tThe phone directory is empty\n");
    } else {
        printf("\tChoose how to search for a subscriber:\n1 - by name\n2 - by surname\n3 - by phone number\n");
        int temp, flag = 0;
        scanf("%d", &temp);
        if (temp == 1) {
            printf("Enter the subscriber's name:\n");
            scanf("%s", name);
            while (ptr != NULL) {
                if (strcmp(name, ptr->name) == 0) {
                    printf("\n\tSubscriber\nNAME\t\t %s\nLAST NAME\t %s\nPHONE NUMBER\t %s\n", ptr->name, ptr->surname, ptr->phone_number);
                    flag++;
                }
                ptr = ptr->next;
            }
            if (flag == 0) {
                printf("There is no such subscriber %s in the telephone directory\n", name);
            }
        } else if (temp == 2) {
            printf("Enter the subscriber's last name:\n");
            scanf("%s", surname);
            while (ptr != NULL) {
                if (strcmp(surname, ptr->surname) == 0) {
                    printf("\n\tSubscriber\nNAME\t\t %s\nLAST NAME\t %s\nPHONE NUMBER\t %s\n", ptr->name, ptr->surname, ptr->phone_number);
                    flag++;
                }
                ptr = ptr->next;
            }
            if (flag == 0) {
                printf("There is no such subscriber %s in the telephone directory\n", surname);
            }
        } else if (temp == 3) {
            printf("Enter the subscriber's phone number:\n");
            scanf("%s", phone_number);
            while (ptr != NULL) {
                if (strcmp(phone_number, ptr->phone_number) == 0) {
                    printf("\n\tSubscriber\nNAME\t\t %s\nLAST NAME\t %s\nPHONE NUMBER\t %s\n", ptr->name, ptr->surname, ptr->phone_number);
                    flag++;
                }
                ptr = ptr->next;
            }
            if (flag == 0) {
                printf("There is no such subscriber %s in the telephone directory\n", phone_number);
            }
        }
    }
}

void output_telephone_directory() {
    int i = 1;
    if (head == NULL) {
        printf("\n\tThe phone directory is empty\n");
    } else {
        struct phone_directory *ptr = head;
        printf("\t\tTELEPHONE DIRECTORY\n");
        printf("No\tNAME\t\t\tLAST NAME\t\t\t\tPHONE NUMBER\n");
        while (ptr != NULL) {
            printf("%d\t%-20s\t%-50s %-20s\n", i, ptr->name, ptr->surname, ptr->phone_number);
            ptr = ptr->next;
            i++;
        }
    }
}
