#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

void operations (int libraries[5]);


int main()
{
    int number_libraries, i = 0;
    int libraries[5] = {0};
    printf("\t\tSIMPLE CALCULATOR PROGRAM\n\tEnter the number of libraries (from 1 to 4): ");
    scanf("%d", &number_libraries);
    if (number_libraries < 1 || number_libraries > 4)
    {
        fprintf(stderr, "Invalid number of libraries\n");
        return 1;
    }
    printf("\nEnter the name of the libraries, for example: libadd or ladd\n");
    printf("\tAvailable libraries: ladd, lsubtract, lmultiply, ldivide\n");
    while (i < number_libraries)
    {
        char name_library[50];
        printf("Libraries № %d\n", i + 1);
        scanf("%s", name_library);
        if (strcmp("libadd", name_library) == 0 || strcmp("ladd", name_library) == 0)
        {
            printf("Library %s addedа\n", name_library);
            libraries[1] = 1;
            i++;
        } else if (strcmp("libsubtract", name_library) == 0 || strcmp("lsubtract", name_library) == 0)
        {
            printf("Library %s addedа\n", name_library);
            libraries[2] = 1;
            i++;
        } else if (strcmp("libmultiply", name_library) == 0 || strcmp("lmultiply", name_library) == 0)
        {
            printf("Library %s addedа\n", name_library);
            libraries[3] = 1;
            i++;
        } else if (strcmp("libdivide", name_library) == 0 || strcmp("ldivide", name_library) == 0)
        {
            printf("Library %s addedа\n", name_library);
            libraries[4] = 1;
            i++;
        } else printf("Error there is no such library\n");
    }
    operations(libraries);
}


void operations(int libraries[5])
{
    // Загрузка динамических библиотек
    int *add_lib = dlopen("./libadd.so", RTLD_LAZY);
    int *subtract_lib = dlopen("./libsubtract.so", RTLD_LAZY);
    int *multiply_lib = dlopen("./libmultiply.so", RTLD_LAZY);
    double *divide_lib = dlopen("./libdivide.so", RTLD_LAZY);

    // Получение указателя на функцию из библиотеки
    int (*add)(int, int) = dlsym(add_lib, "add");
    int (*subtract)(int, int) = dlsym(subtract_lib, "subtract");
    int (*multiply)(int, int) = dlsym(multiply_lib, "multiply");
    double (*divide)(double, double) = dlsym(divide_lib, "divide");

    while (1)
    {
        int number, first, second;
        double result = 0.0;
        printf("\n\tSIMPLE CALCULATOR PROGRAM\n");
        printf("Enter two integer numbers\n");
        printf("First number:\t");
        scanf("%d", &first);
        printf("Second number:\t");
        scanf("%d", &second);
        printf("\n\tCHOOSE WHAT YOU WANT TO DO:\n");
            if (libraries[1]) printf("1 - Add the second number to the first number\n");
            if (libraries[2]) printf("2 - Subtract the second number from the first number\n");
            if (libraries[3]) printf("3 - Multiply the first number by the second number\n");
            if (libraries[4]) printf("4 - Divide the first number by the second number\n");
            printf("5 - Close the Calculator program\n");
            scanf("%d", &number);
            switch (number)
            {
                case 1:
                    if (libraries[1]) {
                        printf("\tThe result of addition %d + %d = %d\n", first, second, add(first, second));
                    } else {
                        printf("\tThere is no such function\n");
                    }
                    break;
                case 2:
                    if (libraries[2]) {
                        printf("\tThe result of subtraction %d - %d = %d\n", first, second, subtract(first, second));
                    } else {
                        printf("\tThere is no such function\n");
                    }
                    break;
                case 3:
                if (libraries[3]) {
                        printf("\tThe result of multiplication %d * %d = %d\n", first, second, multiply(first, second));
                    } else {
                        printf("\tThere is no such function\n");
                    }
                    break;
                case 4:
                    if (second != 0) {
                        if (libraries[4]) {
                            printf("\tDivision result %d %% %d = %.2lf\n", first, second, divide(first, second));
                        } else {
                            printf("\tThere is no such function\n");
                        }
                    } else {
                        printf("\tIt is impossible to divide by 0\n");
                    }
                    break;
                case 5:
                    printf("The program \"SIMPLE CALCULATOR\" is closed\n");
                    if (add_lib != NULL) dlclose(add_lib);
                    if (subtract_lib != NULL) dlclose(subtract_lib);
                    if (multiply_lib != NULL) dlclose(multiply_lib);
                    if (divide_lib != NULL) dlclose(divide_lib);
                    exit(0);
                default:
                    printf("Repeat the input\n");
                    break;
            }
        }
    }
