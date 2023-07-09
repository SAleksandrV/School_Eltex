#include "telephone_directory.h"

void add_subscriber() {
    struct phone_directory *temp = malloc(sizeof(struct phone_directory));
    if (temp == NULL) {
        printf("No memory allocated\n");
        return;
    }
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
        struct phone_directory *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = temp;
    }
    printf("\n%s added successfully!\n", temp->name);
}
