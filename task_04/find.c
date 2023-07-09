#include "telephone_directory.h"


void find_subscriber(struct phone_directory *group, int *count) {
    char name[50], surname[100], phone_number[15];
    int point = 1;
     if (*count == 0) {
        printf("\n\tThe phone directory is empty\n");
    } else {
        printf("\tChoose how to search for a subscriber:\n1 - by name\n2 - by surname\n3 - by phone number\n");
        int temp;
        scanf("%d", &temp);
        if (temp == 1) {
            printf("Enter the subscriber's name:\n");
            scanf("%s", name);
            for (int i = 0; i < *count; i++) {
                if (strcmp(name, group[i].name) == 0) {
                    printf("\n\tSubscriber\nNAME\t\t %s\nLAST NAME\t %s\nPHONE NUMBER\t %s\n", group[i].name, group[i].surname, group[i].phone_number);
                    point--;
                }
            }
            if (point > 0) {
                printf("There is no such subscriber %s in the telephone directory\n", name);
            }
        } else if (temp == 2) {
            printf("Enter the subscriber's last name:\n");
            scanf("%s", surname);
            for (int i = 0; i < *count; i++) {
                if (strcmp(surname, group[i].surname) == 0) {
                    printf("\n\tSubscriber\nNAME\t\t %s\nLAST NAME\t %s\nPHONE NUMBER\t %s\n", group[i].name, group[i].surname, group[i].phone_number);
                    point--;
                }
            }
            if (point > 0) {
                printf("There is no such subscriber %s in the telephone directory\n", surname);
            }
        } else if (temp == 3) {
            printf("Enter the subscriber's phone number:\n");
            scanf("%s", phone_number);
            for (int i = 0; i < *count; i++) {
                if (strcmp(phone_number, group[i].phone_number) == 0) {
                    printf("\n\tSubscriber\nNAME\t\t %s\nLAST NAME\t %s\nPHONE NUMBER\t %s\n", group[i].name, group[i].surname, group[i].phone_number);
                    point--;
                }
            }
            if (point > 0) {
                printf("There is no such subscriber %s in the telephone directory\n", phone_number);
            }
        }
    }
}
