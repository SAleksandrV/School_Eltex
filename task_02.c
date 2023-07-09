#include <stdio.h>

union code {
    unsigned char byte;
    struct bits {
    unsigned bit_0 : 1;
    unsigned bit_1 : 1;
    unsigned bit_2 : 1;
    unsigned bit_3 : 1;
    unsigned bit_4 : 1;
    unsigned bit_5 : 1;
    unsigned bit_6 : 1;
    unsigned bit_7 : 1;
    } bit;
};

// Вывод 4-х байтового числа по байтам и битам
int byte_bits(int *number);
// Запись в 3-й байт 4-х байтового числа маски из 8 бит
int write_mask_in_3_byte(int *number, unsigned char const *const mask);
// Инверсия 3-го байта (целиком) в 4-х байтовом числе
int byte_change(int * number);

int main(void) {
    unsigned char mask = 0xAF;
    int i, temp, number = 0xBBCCDDEE;
    for (i = 0; i < 4; i++) {
        temp = number >> i * 8 & 0xFF;
        printf("  %d BYTE and BITS\n", i + 1);
        byte_bits(&temp);
        puts("");
    }

    printf("\nChanging 3 byte by mask\n");
    printf("Old number value = \t%X\n", number);
    write_mask_in_3_byte(&number, &mask);
    printf("New number value = \t%X\n", number);

    byte_change(&number);
    printf("The number after the inversion\t\t %X\n", number);
    return 0;
}

int byte_bits(int *number) {
    union code result;
    result.byte = *number;
    printf("%X\t", result.byte);
    printf("%d %d %d %d %d %d %d %d\n", result.bit.bit_7, result.bit.bit_6, result.bit.bit_5,\
     result.bit.bit_4, result.bit.bit_3, result.bit.bit_2, result.bit.bit_1, result.bit.bit_0);
}

int write_mask_in_3_byte(int *number, unsigned char const *const mask) {
    int i;
    printf("Mask ");
    for (int i = 7; i >= 0; i--) {
        printf("%d ", (*mask >> i) & 1);
        if ((*mask >> i) & 1) {
            *number |= (1 << (i + 16));
        } else {
            *number &= ~(1 << (i + 16));
        }
    }
    printf("\t%X\n", *mask);
}


int byte_change(int * number) {
    printf("\nOriginal number\t\t\t\t %X\n", *number);
    unsigned char byte[4] = {0};
    for (int i = 0; i < 4; i++) {
        byte[i] = (*number >> 8 * i) & 0xFF;
    }
    printf("The third Byte before the inversion\t %X\n", byte[2]);
    byte[2] = ~byte[2];
    printf("The third byte after the inversion\t %X\n", byte[2]);
    for (int i = 3; i >= 0; i--) {
        *number = (*number << 8) | byte[i];
    }
}
