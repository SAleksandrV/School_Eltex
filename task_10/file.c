#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main() {

    float first = 0, second = 0, op = 0, res = -1;
    char quit = 'y';
    /* In libs & ops information about certain func is stored at certain index:

       |  0  |  1  |  2  |  3  |
       | ADD | SUB | MUL | DIV |

    */
    void* libs[NUM_OPS] = {[0 ... NUM_OPS-1] = NULL};
    int (*ops[NUM_OPS])(int, int);
    init_interface(libs, ops); // <--- func that fills libs & ops with information about funcs
                               // <--- AND configures which funcs will be in calc

    while (quit != 'n' && quit != 'q') {
        printf("Enter first number: ");
        scanf(" %d", &first);
        printf("Enter second number: ");
        scanf(" %d", &second);
        int counter = 0;
        printf("\n\nAvailable operations:\n");
        for (int counter = 0; counter < NUM_OPS; counter++) {
            if (counter == 0 && libs[counter] != NULL) printf("0. Add\n");
            if (counter == 1 && libs[counter] != NULL) printf("1. Sub\n");
            if (counter == 2 && libs[counter] != NULL) printf("2. Mul\n");
            if (counter == 3 && libs[counter] != NULL) printf("3. Div\n");
        }
        scanf("%d", &op);
        res = ops[op](first, second); // <--- calling function from dynamic library

        if (res == -1 && op == 3) {
            /* If denominator == 0 */
            printf("Something went wrong...TRY AGAIN!\n");
        } else {
            printf("RESULT: %d\n", res);
        }

        printf("Again?(y/n): ");
        scanf(" %c", &quit);
    }

    for (int i = 0; i < NUM_OPS; i++) {
        if (libs[i] != NULL) dlclose(libs[i]);
    }
}
    return 0;
}