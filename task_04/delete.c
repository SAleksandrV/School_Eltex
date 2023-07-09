#include "telephone_directory.h"


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
                if (*count == SIZE -1) {
                    strcpy(group[*count - 1].name, "");
                    strcpy(group[*count - 1].surname, "");
                    strcpy(group[*count - 1].phone_number, "");
                }
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
