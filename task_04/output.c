#include "telephone_directory.h"


void output_telephone_directory(struct phone_directory *group, int *count) {
    if (*count == 0) {
        printf("\n\tThe phone directory is empty\n");
    } else {
        printf("\t\tTELEPHONE DIRECTORY\n");
        printf("No\tNAME\t\t\tLAST NAME\t\t\t\tPHONE NUMBER\n");
        for (int i = 0; i < *count; i++) {
            printf("%d\t%-20s\t%-50s %-20s\n", i + 1, group[i].name, group[i].surname, group[i].phone_number);
        }
    }
}
