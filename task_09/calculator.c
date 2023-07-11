#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main(void) {
    int number, first, second;
    double result = 0.0;
    printf("\tSIMPLE CALCULATOR PROGRAM\n");
    while (1) {
        printf("Enter two integer numbers\n");
        printf("First number:\t");
        scanf("%d", &first);
        printf("Second number:\t");
        scanf("%d", &second);
        printf("\n\tCHOOSE WHAT YOU WANT TO DO:\n1 - Add the second number to the first number\n\
2 - Subtract the second number from the first number\n3 - Multiply the first number by the second number\n\
4 - Divide the first number by the second number\n5 - Close the Calculator program\n");
        scanf("%d", &number);
        switch (number) {
            case 1:
                result = add(first, second);
                printf("\tThe result of addition %d + %d = %0.0f\n", first, second, result);
                break;
            case 2:
                result = subtract(first, second);
                printf("\tThe result of subtraction %d - %d = %0.0f\n", first, second, result);
                break;
            case 3:
                result = multiply(first, second);
                printf("\tThe result of multiplication %d * %d = %0.0f\n", first, second, result);
                break;
            case 4:
                if (second == 0) {
                    printf("\tIt is impossible to divide by 0\n");
                } else {
                    result = divide(first, second);
                    printf("\tDivision result %d %% %d = %.2f\n", first, second, result);
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
    return 0;
}
