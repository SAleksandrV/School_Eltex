#include "manager.h"
#include <ncurses.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>


void display_files(WINDOW *win, const char *directory_path, int temp_index) {
    // char string[100];
    // Очистка окна перед отображением файлов
    werase(win);
    box(win, 0, 0);

    int start_x = 2;  // начальное значение по оси X для отображения файлов
    int start_y = 1;  // начальное значение по оси Y для отображения файлов
    int max_y, max_x;
    getmaxyx(win, max_y, max_x);

    wmove(win, start_y, start_x);  // переход на начальные позиции
    wrefresh(win);

    // Открытие директории
    DIR *dir = opendir(directory_path);
        if (dir == NULL) {
            return;
        }

    // Чтение файлов из директории
    struct dirent *entry;
    int row = start_y;  // Начальная строка для отображения файлов
    int index = 0;  // Индекс текущего файла

    // Если выбранная директория - не текущая директория, изменить текущую директорию
    char *path = strdup(getenv("PWD"));  // Получить текущую директорию
        if (strcmp(directory_path, path) != 0) {
            chdir(directory_path);
        }

    rewinddir(dir);
    // добавлено условие, что строка не должна выходить за пределы окна)
    while ((entry = readdir(dir)) != NULL && row < max_y - 1) {
        if (index == temp_index) {
            wattron(win, A_REVERSE);
        }

        if (entry->d_type == DT_DIR) {
            mvwprintw(win, row, 1, "DIR %-20s", entry->d_name);
        } else {
            mvwprintw(win, row, 1, "    %-20s", entry->d_name);
        }

        if (index == temp_index) {
            wattroff(win, A_REVERSE);
        }

        index++;
        row++;
        wmove(win, row, start_x);  // переход на следующую строку
    }

    // Возвращаем текущую директорию, если она была изменена
    if (strcmp(directory_path, path) != 0) {
        chdir(path);
    }

    closedir(dir);
    wrefresh(win);
    free(path);
}
