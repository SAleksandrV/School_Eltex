#include <stdio.h>
#include <stdlib.h>
#include "telephone_directory.h"


int main(void) {
    struct phone_directory group[SIZE];
    int count = 0, number;
    while (1) {
        printf("\n\tCHOOSE WHAT YOU WANT TO DO:\n1 - Add a subscriber\n2 - Delete the subscriber\n\
3 - Find a subscriber\n4 - View the entire phone directory\n5 - Close the phone directory\n");
        scanf("%d", &number);
        switch (number) {
            case 1:
                add_subscriber(group, &count);
                break;
            case 2:
                delete_subscriber(group, &count);
                break;
            case 3:
                find_subscriber(group, &count);
                break;
            case 4:
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
