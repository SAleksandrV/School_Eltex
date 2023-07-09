#include "telephone_directory.h"


void output_telephone_directory() {
    int i = 1;
    if (head == NULL) {
        printf("\n\tThe phone directory is empty\n");
    }

    struct phone_directory *temp = head;

    printf("\t\tTELEPHONE DIRECTORY\n");
    printf("No\tNAME\t\t\tLAST NAME\t\t\t\tPHONE NUMBER\n");
    while (temp != NULL) {
        printf("%d\t%-20s\t%-50s %-20s\n", i, temp->name, temp->surname, temp->phone_number);
        temp = temp->next;
        i++;
    }
}
