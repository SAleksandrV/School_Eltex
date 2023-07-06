#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

void display_files(WINDOW *win, const char *dir_path) {
    // Открытие директории
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        return;
    }

    // Очистка окна перед отображением файлов
    werase(win);
    wrefresh(win);

    // Чтение файлов из директории
    struct dirent *entry;
    int row = 1; // Начальная строка для отображения файлов
    while ((entry = readdir(dir)) != NULL) {
        // Отображение имени файла
        mvwprintw(win, row, 1, entry->d_name);
        row++;
    }

    // Закрытие директории
    closedir(dir);

    // Обновление окна после отображения файлов
    wrefresh(win);
}

int main() {
    // Инициализация Ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Создание основного окна
    int height, width;
    getmaxyx(stdscr, height, width);
    WINDOW *mainwin = newwin(height - 2, width, 2, 0);
    refresh();

    // Отображение текущей директории
    char *cwd = getenv("PWD");
    display_files(mainwin, cwd);

    // Обработка пользовательского ввода
    int key;
    while ((key = getch()) != 'q') {
        // При нажатии Enter отображается содержимое выбранной директории
        if (key == '\\n') {
            // Получение имени выбранного файла или директории
            char current_entry[256];
            int cury, curx;
            getyx(mainwin, cury, curx);
            mvwinchnstr(mainwin, cury, 1, current_entry, sizeof(current_entry));

            // Создание нового пути к выбранному файлу или директории
            char new_path[256];
            snprintf(new_path, sizeof(new_path), "%s/%s", cwd, current_entry);

            // Проверка, является ли выбранный объект директорией
            DIR *dir = opendir(new_path);
            if (dir != NULL) {
                // Если выбранная папка - директория, она становится текущей
                closedir(dir);
                display_files(mainwin, new_path);
                cwd = new_path;
            } else {
                // Если выбран файл, можно выполнить определенные действия
                // Здесь можно добавить ваш код для обработки выбора файлов
            }
        }
    }

    // Закрытие Ncurses
    delwin(mainwin);
    endwin();
    refresh();

    return 0;
}
