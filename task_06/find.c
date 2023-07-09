#include "telephone_directory.h"

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
