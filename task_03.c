#include <stdio.h>

/* Создать и вывести на экран одно и двухмерные статичные массивы*/

#define SIZE_01 3
#define SIZE_02 5
// Заполнение и вывод массива, переворот и вывод этого же массива
int array(int vector[], const int size);
// заполнение и вывод квадратной матрицы
int square(int matrix[][SIZE_01], const int size);
// Вывод массива из 0 1 разделённых по диагоналям (главной и побочной)
int main_diagonal(int matrix[][SIZE_01], const int size);
int side_diagonal(int matrix[][SIZE_01], const int size);
// Заполнение матрицы по спирали - вправо, вниз, влево, вверх
int square_spiral(int matrix[][SIZE_01], const int size);
// Транспонирование матрицы -горизонтали становятся вертикалями (вверх -> влево)
int square_transposition(int matrix[][SIZE_01], const int size);

int main(void) {
    int vector[SIZE_02];
    int matrix[SIZE_01][SIZE_01];
    puts("\tVECTOR");
    array(vector, SIZE_02);
    puts("\tSQUARE");
    square(matrix, SIZE_01);
    puts("\tMAIN DIAGONAL");
    main_diagonal(matrix, SIZE_01);
    puts("\tSIDE DIAGONAL");
    side_diagonal(matrix, SIZE_01);
    puts("\tSQUARE SPIRAL");
    square_spiral(matrix, SIZE_01);
    puts("\tSQUARE TRANSPOSITION");
    square_transposition(matrix, SIZE_01);

    return 0;
}

int array(int vector[], const int size) {
    for (int i = 0; i < size; i++) {
        vector[i] = i + 1;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    for (int i = 0; i < size / 2; i++) {
        int temp = vector[i];
        vector[i] = vector[size - i - 1];
        vector[size - i - 1] = temp;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}


int square(int matrix[][SIZE_01], const int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            matrix[i][j] = i * size + j + 1;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main_diagonal(int matrix[][SIZE_01], const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i >= j) {
                matrix[i][j] = 1;
                printf("%d ", matrix[i][j]);
            } else {
                matrix[i][j] = 0;
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int side_diagonal(int matrix[][SIZE_01], const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i + j <= size - 1) {
                matrix[i][j] = 1;
                printf("%d ", matrix[i][j]);
            } else {
                matrix[i][j] = 0;
                printf("%d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int square_spiral(int matrix[][SIZE_01], const int size) {
    int i, j, start_row = 0, end_row = size - 1, start_col = 0, end_col = size - 1, count = 1;
    while (start_row <= end_row && start_col <= end_col) {
        for (i = start_col; i <= end_col; i++) {
            matrix[start_row][i] = count++;
        }
        start_row++;
        for (i = start_row; i <= end_row; i++) {
            matrix[i][end_col] = count++;
        }
        end_col--;
        for (i = end_col; i >= start_col; i--) {
            matrix[end_row][i] = count++;
        }
        end_row--;
        for (i = end_row; i >= start_row; i--) {
            matrix[i][start_col] = count++;
        }
        start_col++;
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int square_transposition(int matrix[][SIZE_01], const int size) {
    int i, j, temp;
    printf("\nThe original matrix\n");
    square(matrix, SIZE_01);
    for (int i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    printf("\nTransposed matrix\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}
