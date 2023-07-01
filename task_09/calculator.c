#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main(void)
{
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
                add(first, second, &result);
                printf("\tThe result of addition %.0f + %.0f = %.0f\n", first, second, result);
                break;
            case 2:
                subtract(first, second, &result);
                printf("\tThe result of subtraction %.0f - %.0f = %.0f\n", first, second, result);
                break;
            case 3:
                multiply(first, second, &result);
                printf("\tThe result of multiplication %.0f * %.0f = %.0f\n", first, second, result);
                break;
            case 4:
                if (second == 0) {
                    printf("\tIt is impossible to divide by 0\n");
                } else {
                    divide(first, second, &result);
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
    return 0;
}
