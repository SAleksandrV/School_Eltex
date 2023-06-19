#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Программа телефонный справочник */
struct phone_directory {
    char name[50];
    char surname[100];
    char phone_number[12];
};

// Добавление абонента
void add_subscriber(struct phone_directory *group, int *count);


int main(void) {
    struct phone_directory group[100];
    int count = 0, number;
    while (1) {
        printf("\n\tCHOOSE WHAT YOU WANT TO DO:\n1 - Add a subscriber\n2 - Delete the subscriber\n\
3 - Find a subscriber\n4 - View the entire phone directory\n5 - Close the phone directory\n");
        printf("%d\n", count);
        scanf("%d", &number);
        switch (number) {
            case 1:
                printf("Adding a subscriber to the phone directory\n");
                add_subscriber(group, &count);
                break;
            case 2:
                printf("We remove the subscriber from the telephone directory\n");
                break;
            case 3:
                printf("Pass");
                // find();
                break;
            case 4:
                printf("Viewing the entire phone directory\n");
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
    if (*count > 99) {
        printf("The phone directory is full\n");
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

