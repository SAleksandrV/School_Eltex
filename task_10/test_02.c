#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// Декларация типа указателя на функцию операции
typedef int (*OperationFunction)(int, int);

int main() {
    void* libraryHandles[4] = {NULL};
    OperationFunction operations[4] = {NULL};
    int numLibraries;

    printf("Калькулятор. Введите количество библиотек (от 1 до 4): ");
    scanf("%d", &numLibraries);
    if (numLibraries < 1 || numLibraries > 4) {
        fprintf(stderr, "Недопустимое количество библиотек\n");
        return 1;
    }

    for (int i = 0; i < numLibraries; i++) {
        char libraryName[50];
        printf("Введите название библиотеки %d (без расширения .so): ", i + 1);
        scanf("%s", libraryName);
        if (strcmp())
        libraryHandles[i] = dlopen(libraryName, RTLD_LAZY);
        if (!libraryHandles[i]) {
            fprintf(stderr, "Ошибка при загрузке библиотеки %d: %s\n", i + 1, dlerror());
            return 1;
        }

        operations[i] = dlsym(libraryHandles[i], "operation");
        if (!operations[i]) {
            fprintf(stderr, "Ошибка при загрузке функции операции из библиотеки %d: %s\n", i + 1, dlerror());
            return 1;
        }
    }

    int operand1, operand2;
    char operator;

    while (1) {
        printf("Введите операцию (+, -, *, /) или 'q' для выхода: ");
        scanf(" %c", &operator);

        if (operator == 'q') {
            break;
        }

        printf("Выберите номер библиотеки (от 1 до %d): ", numLibraries);
        int libraryIndex;
        scanf("%d", &libraryIndex);

        if (libraryIndex < 1 || libraryIndex > numLibraries) {
            fprintf(stderr, "Недопустимый номер библиотеки\n");
            continue;
        }

        printf("Введите первый операнд: ");
        scanf("%d", &operand1);

        printf("Введите второй операнд: ");
        scanf("%d", &operand2);

        int result = operations[libraryIndex - 1](operand1, operand2);

        printf("Результат: %d\n", result);
    }

    for (int i = 0; i < numLibraries; i++) {
        if (libraryHandles[i]) {
            dlclose(libraryHandles[i]);
        }
    }

    return 0;
}



// int main(int argc, char *argv[]) {
//     void *handle;
//     double (*cosine)(double);
//     char *error;
//     handle = dlopen("./.so", RTLD_LAZY);
//     if (!handle) {
//         fputs(dlerror(), stderr);
//         exit(1);
//     }
//     cosine = dlsym(handle, "cos");
//     if ((error = dlerror()) != NULL) {
//         fputs(error, stderr);
//         exit(1);
//     }
//     printf("%f\n", (*cosine)(2.0));
//     dlclose(handle);
// }