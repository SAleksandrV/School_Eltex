#include "telephone_directory.h"

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
