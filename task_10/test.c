#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

int main() {
    int number_libraries, i = 0;
    int libraries[5] = {0};
    printf("\tSIMPLE CALCULATOR PROGRAM\nEnter the number of libraries (from 1 to 4): ");
    scanf("%d", &number_libraries); 
    if (number_libraries < 1 || number_libraries > 4) {
        fprintf(stderr, "Invalid number of libraries\n");
        return 1;
    }

    // printf("\nEnter the name of the libraries, for example: libadd or ladd\n");
    // while (i < number_libraries) {
    //     char name_library[50];
    //     printf("Libraries № %d\n", i + 1);
    //     scanf("%s", name_library);
    //     if (strcmp("libadd", name_library) == 0 || strcmp("ladd", name_library) == 0) {
    //         printf("Library %s addedа\n", name_library);
    //         libraries[1] = 1;
    //         i++;
    //     } else if (strcmp("libsubtract", name_library) == 0 || strcmp("lsubtract", name_library) == 0) {
    //         printf("Library %s addedа\n", name_library);
    //         libraries[2] = 1;
    //         i++;
    //     } else if (strcmp("libmultiply", name_library) == 0 || strcmp("lmultiply", name_library) == 0) {
    //         printf("Library %s addedа\n", name_library);
    //         libraries[3] = 1;
    //         i++;
    //     } else if (strcmp("libdivide", name_library) == 0 || strcmp("ldivide", name_library) == 0) {
    //         printf("Library %s addedа\n", name_library);
    //         libraries[4] = 1;
    //         i++;
    //     } else {
    //         printf("Error there is no such library\n");
    //     }
    // }

// Загрузка динамической библиотеки
    void *add_lib = dlopen("./libadd.so", RTLD_LAZY);
    void *subtract_lib = dlopen("./libsubtract.so", RTLD_LAZY);
    void *multiply_lib = dlopen("./libmultiply.so", RTLD_LAZY);
    void *divide_lib = dlopen("./libdivide.so", RTLD_LAZY);

    if (add_lib || subtract_lib || !multiply_lib || !divide_lib) {
        fprintf(stderr, "Ошибка загрузки библиотеки\n");
        return 1;
    }

// Получение указателя на функцию из библиотеки
    float (*add)(float, float) = dlsym(add_lib, "add");
    float (*subtract)(float, float) = dlsym(subtract_lib, "subtract");
    float (*multiply)(float, float) = dlsym(multiply_lib, "multiply");
    float (*divide)(float, float) = dlsym(divide_lib, "divide");

    if (!add_lib || subtract || !multiply || !divide) {
        fprintf(stderr, "Ошибка загрузки функций\n");
        return 1;
    }


    int number;
    float first, second, result = 0.0;
    printf("\tSIMPLE CALCULATOR PROGRAM\n");
    while (1) {
        printf("Enter two integer numbers\n");
        printf("First number:\t");
        scanf("%f", &first);
        printf("Second number:\t");
        scanf("%f", &second);
        printf("\n\tCHOOSE WHAT YOU WANT TO DO:\n1 - Add the second number to the first number\n\
2 - Subtract the second number from the first number\n3 - Multiply the first number by the second number\n\
4 - Divide the first number by the second number\n5 - Close the Calculator program\n");
        scanf("%d", &number);
        switch (number) {
            case 1:
                result = add(first, second);
                printf("\tThe result of addition %.0f + %.0f = %.0f\n", first, second, result);
                break;
            case 2:
                result = subtract(first, second);
                printf("\tThe result of subtraction %.0f - %.0f = %.0f\n", first, second, result);
                break;
            case 3:
                result = multiply(first, second);
                printf("\tThe result of multiplication %.0f * %.0f = %.0f\n", first, second, result);
                break;
            case 4:
                if (second == 0) {
                    printf("\tIt is impossible to divide by 0\n");
                } else {
                    result = divide(first, second);
                    printf("\tDivision result %.0f %% %.0f = %.2f\n", first, second, result);
                }
                break;
            case 5:
                printf("The program \"SIMPLE CALCULATOR\" is closed\n");
                exit(0);
            default:
                printf("Repeat the input\n");
                break;
        }
    }
}
