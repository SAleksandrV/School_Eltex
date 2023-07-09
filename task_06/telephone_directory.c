#include "telephone_directory.h"

struct phone_directory *head = NULL;

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
