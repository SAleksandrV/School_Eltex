
#include <ncurses.h>
#include <dirent.h>
#include <string.h>

#define SELECTED_COLOR_PAIR 1
#define first_win_WIDTH 256

int main() {
    DIR *dir;
    struct dirent *entry;
    int selected_index = 0;
    char current_path[256];

    // Инициализация Ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(SELECTED_COLOR_PAIR, COLOR_BLUE, COLOR_BLACK);

    // Открытие текущей директории
    getcwd(current_path, sizeof(current_path));
    dir = opendir(current_path);

    // Создание содержимого первого окна
    int height, width;
    getmaxyx(stdscr, height, width);
    int main_width = width / 2;
    WINDOW *first_win = newwin(height - 2, main_width, 0, 0);
    wbkgd(first_win, COLOR_PAIR(1));
    WINDOW *second_win = newwin(height - 2, main_width, 0, main_width);
    wbkgd(second_win, COLOR_PAIR(1));

    WINDOW *current_win = first_win;
    wbkgd(current_win, COLOR_PAIR(1));
    wbkgd(second_win, COLOR_PAIR(1));

    // Основной цикл программы
    int ch;
    while ((ch = getch()) != 'q') {
        if (ch == '\t') {
            if (current_win == first_win) {
                current_win = second_win;
                wbkgd(first_win, COLOR_PAIR(0));
                wbkgd(second_win, COLOR_PAIR(1));
            } else {
                current_win = first_win;
                wbkgd(first_win, COLOR_PAIR(1));
                wbkgd(second_win, COLOR_PAIR(0));
            }
        }

        int win_height, win_width;
        getmaxyx(current_win, win_height, win_width);

        if (ch == KEY_UP) {
            if (selected_index > 0) {
                selected_index--;
            }
        } else if (ch == KEY_DOWN) {
            selected_index++;
        }

        wclear(current_win);
        box(current_win, 0, 0);

        // Чтение файлов и папок текущей директории
        int i = 0;


#include <ncurses.h>
#include <dirent.h>
#include <string.h>

#define SELECTED_COLOR_PAIR 1
#define LIST_WIN_WIDTH 256

int main() {
    DIR *dir;
    struct dirent *entry;
    int selected_index = 0;
    char current_path[256];
    char list_buffer[256][256];
    char second_buffer[256][256];
    

    // Инициализация Ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(SELECTED_COLOR_PAIR, COLOR_BLUE, COLOR_BLACK);

    // Открытие текущей директории
    getcwd(current_path, sizeof(current_path));
    dir = opendir(current_path);

    // Создание содержимого первого окна
    int height, width;
    getmaxyx(stdscr, height, width);
    int main_width = width / 2;
    WINDOW *list_win = newwin(height - 2, main_width, 0, 0);
    wbkgd(list_win, COLOR_PAIR(1));
    box(list_win, 0, 0);

    // Создание содержимого второго окна
    WINDOW *second_win = newwin(height - 2, main_width, 0, main_width);
    wbkgd(second_win, COLOR_PAIR(1));
    box(second_win, 0, 0);

    // Основной цикл программы
    int ch;
    while ((ch = getch()) != 'q') {
    if (ch == '\t') {
        if (current_win == list_win) {
            // Сохранение содержимого первого окна в буфер
            strncpy(list_buffer, second_buffer, sizeof(list_buffer));
            // Восстановление содержимого второго окна из буфера
            strncpy(second_buffer, second_win, sizeof(second_buffer));
            current_win = second_win;
        } else {
            // Сохранение содержимого второго окна в буфер
            strncpy(second_buffer, list_buffer, sizeof(second_buffer));
            // Восстановление содержимого первого окна из буфера
            strncpy(list_buffer, list_win, sizeof(list_buffer));
            current_win = list_win;
        }
    }
        wrefresh(list_win);     // Обновление содержимого первого окна
        wrefresh(second_win);  // Обновление содержимого второго окна

        int win_height, win_width;
        getmaxyx(current_win, win_height, win_width);

        if (ch == KEY_UP) {
            if (selected_index > 0) {
                selected_index--;
            }
        } else if (ch == KEY_DOWN) {
            selected_index++;
        }

        werase(current_win);

        // Чтение файлов и папок текущей директории
        int i = 0;
        rewinddir(dir);
        while ((entry = readdir(dir)) != NULL && i < win_height) {
            if (i == selected_index) {
                wattron(current_win, A_REVERSE);
            }

            if (entry->d_type == DT_DIR) {
                wprintw(current_win, "%s/\n", entry->d_name);
            } else {
                wprintw(current_win, "%s\n", entry->d_name);
            }

            if (i == selected_index) {
                wattroff(current_win, A_REVERSE);
            }

            i++;
        }

        if (ch == '\n') {
            char selected_entry[256];
            i = 0;
            rewinddir(dir);
            while ((entry = readdir(dir)) != NULL) {
                if (i == selected_index) {
                    strcpy(selected_entry, entry->d_name);
                    break;
                }
                i++;
            }

            if (strcmp(selected_entry, "..") == 0) {
                chdir("..");
            } else {
                chdir(selected_entry);
            }

            getcwd(current_path, sizeof(current_path));
            closedir(dir);
            dir = opendir(current_path);
            selected_index = 0;
        }

        wrefresh(current_win);
    }

    closedir(dir);
    delwin(list_win);
    delwin(second_win);
    endwin();

    return 0;
}

        rewinddir(dir);
        while ((entry = readdir(dir)) != NULL && i < win_height) {
            if (i == selected_index) {
                wattron(current_win, A_REVERSE);
            }

            if (entry->d_type == DT_DIR) {
                wprintw(current_win, "%s/\n", entry->d_name);
            } else {
                wprintw(current_win, "%s\n", entry->d_name);
            }

            if (i == selected_index) {
                wattroff(current_win, A_REVERSE);
            }

            i++;
        }

        if (ch == '\n') {
            char selected_entry[256];
            i = 0;
            rewinddir(dir);
            while ((entry = readdir(dir)) != NULL) {
                if (i == selected_index) {
                    strcpy(selected_entry, entry->d_name);
                    break;
                }
                i++;
            }

            if (strcmp(selected_entry, "..") == 0) {
                chdir("..");
            } else {
                chdir(selected_entry);
            }

            getcwd(current_path, sizeof(current_path));
            closedir(dir);
            dir = opendir(current_path);
            selected_index = 0;
        }

        wrefresh(first_win);
        wrefresh(second_win);
    }

    closedir(dir);
    delwin(first_win);
    delwin(second_win);
    endwin();

    return 0;
}