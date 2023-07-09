#include "telephone_directory.h"

void delete_subscriber(struct phone_directory **head, char *phone_number) {
    if (*head == NULL) {
        printf("Phone directory is empty\n");
        return;
    }
    struct phone_directory *temp = *head;
    struct phone_directory *previous = NULL;
    while (temp != NULL) {
        if (strcmp(temp->phone_number, phone_number) == 0) {
            if (previous == NULL) {
                *head = temp->next;
            } else {
                previous->next = temp->next;
            }
            free(temp);
            printf("\n\tSubscriber PHONE NUMBER\t %s delete\n", phone_number);
            return;
        }
        previous = temp;
        temp = temp->next;
    }
    printf("\n\tSubscriber PHONE NUMBER \t%s - not in the phone directory\n", phone_number);
}
