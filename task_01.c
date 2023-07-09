#include <stdio.h>

/* Вывести по байтам число 0xDDCCBBAA (16 система счисления)
Инвертировать 3 байт 4-x байтового числа. Изменить 3 байт по маске*/

// Вывод 4-х байтового числа по байтам и битам
void out(int number);
// Инвертирование битов в 3 байте, 4-х байтового числа
int inverting_3_byte(int *number);
// Запись в 3-й байт 4-х байтового числа маски из 8 бит
int write_mask_in_3_byte(int *number, const unsigned char mask);

int main (void) {
    int number = 0xDDCCBBAA, result, i;
    unsigned char mask = 0xEE;

    for (i = 0; i < 4; i++) {
        printf("The %d byte\n", i + 1);
        result = (number >> (i * 8)) & 0xFF;
        out(result);
    }

    printf("Inverting 3 bytes\n");
    printf("Old number value = %X\n", number);
    inverting_3_byte(&number);
    printf("\nNew number value = %X\n", number);

    printf("\nChanging 3 bytes by mask\n");
    printf("Old number value = \t%X\n", number);
    write_mask_in_3_byte(&number, mask);
    printf("New number value = \t%X\n", number);
    return 0;
}

void out (int number) {
    unsigned char result;
    short new_result;
    int i;
    // Получение 1-го байта в 16 системе счисления
    result = (number & 0x000000FF);
    printf("%X\t\t in HEX \n", result);
    /* Преобразование char (1 байт) в short (2 байта) и вывод байта в 10 и 8 системах счисления */
    new_result = (short)result;
    printf("%d\t\t in DEC\n", new_result);
    printf("%o\t\t in OCT\n", new_result);
    for (i = 7; i >= 0; i--) {
        printf("%d ", (result >> i) & 1);
    }
    printf(" in BIN\n");
    printf("\n");
}

int inverting_3_byte(int *number) {
    int i;
    for (i = 31; i >=0; i--) {
        printf("%d ", (*number >> i) & 1);
    }
    puts("\n");
    for (i = 31; i >= 0; i--) {
        if (i <= 23 && i >= 16) {
            *number ^= 1 << i;
            printf("%d ", (*number >> i) & 1);
        } else {
            printf("%d ", (*number >> i) & 1);
        }
    }
}

int write_mask_in_3_byte(int *number, const unsigned char mask) {
    int i;
    printf("Mask ");
    for (int i = 7; i >= 0; i--) {
        printf("%d ", (mask >> i) & 1);
        if ((mask >> i) & 1) {
            *number |= (1 << (i + 16));
        } else {
            *number &= ~(1 << (i + 16));
        }
    }
    printf("\t%X\n", mask);
}
