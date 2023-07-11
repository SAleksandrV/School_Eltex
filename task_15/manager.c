#include "manager.h"
#include <ncurses.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define SELECTED_COLOR_PAIR 1
#define LIST_WIN_WIDTH 256

int main() {
    pid_t child_pid;
    int status;
    // Инициализация Ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(SELECTED_COLOR_PAIR, COLOR_BLUE, COLOR_BLACK);

    // Создание содержимого первого окна
    int height, width;
    getmaxyx(stdscr, height, width);
    int main_width = width / 2;
    WINDOW *first_win = newwin(height - 2, main_width, 0, 0);
    wbkgd(first_win, COLOR_PAIR(1));
    refresh();

    // Открытие текущей директории
    char *path_1 = strdup(getenv("PWD"));
    int index_1 = 0;
    display_files(first_win, path_1, index_1);


    // Создание содержимого второго окна
    WINDOW *second_win = newwin(height - 2, main_width, 0, main_width);
    wbkgd(second_win, COLOR_PAIR(1));

    // Открытие текущей директории
    char *path_2 = strdup(getenv("PWD"));
    int index_2 = 0;
    display_files(first_win, path_2, index_2);


    int ch, flag = 0;
    while ((ch = getch()) != 'q' && ch != 'Q') {
        switch (ch) {
            case KEY_UP:
                // Переместить выделение вверх
                if (flag == 0 && index_1 > 0) {
                    index_1--;
                } else if (flag == 1 && index_2 > 0) {
                    index_2--;
                }
                break;
            case KEY_DOWN:
                // Переместить выделение вниз
                if (flag == 0) {
                    index_1++;
                } else {
                    index_2++;
                }
                break;
            case '\n': {
                // Открываем выбранный элемент
                char selected_entry[256];
                int i = 0;
                if (flag == 0) {
                    DIR *dir = opendir(path_1);
                    struct dirent *entry;
                    rewinddir(dir);
                    while ((entry = readdir(dir)) != NULL) {
                        if (i == index_1) {
                            strcpy(selected_entry, entry->d_name);
                            break;
                        }
                        i++;
                    }
                    closedir(dir);

                    // Формируем полный путь к выбранному элементу
                    char full_path[512];
                    snprintf(full_path, sizeof(full_path), "%s/%s", path_1, selected_entry);

                    // Если выбранный элемент является директорией, отображаем ее содержимое
                    DIR *selected_dir = opendir(full_path);
                    if (selected_dir != NULL) {
                        closedir(selected_dir);
                        free(path_1);
                        path_1 = strdup(full_path);
                        index_1 = 0;
                    } else {
                        char* args[] = { "./editor", NULL };
                        child_pid = fork();
                        if (child_pid == 0) {
                            execvp(args[0], args);
                            exit(5);
                        } else {
                            wait(&status);
                        }
                        display_files(first_win, path_1, index_1);
                    }
                } else {
                    DIR *dir = opendir(path_2);
                    struct dirent *entry;
                    rewinddir(dir);
                    while ((entry = readdir(dir)) != NULL) {
                        if (i == index_2) {
                            strcpy(selected_entry, entry->d_name);
                            break;
                        }
                        i++;
                    }
                    closedir(dir);

                    // Формируем полный путь к выбранному элементу
                    char full_path[512];
                    snprintf(full_path, sizeof(full_path), "%s/%s", path_2, selected_entry);

                    // Если выбранный элемент является директорией, отображаем её содержимое
                    DIR *selected_dir = opendir(full_path);
                    if (selected_dir != NULL) {
                        closedir(selected_dir);
                        free(path_2);
                        path_2 = strdup(full_path);
                        index_2 = 0;
                    } else {
                        char* args[] = {"./editor", NULL};
                        child_pid = fork();
                        if (child_pid == 0) {
                            execvp(args[0], args);
                            exit(5);
                        } else {
                            wait(&status);
                        }
                        display_files(first_win, path_2, index_2);
                    }
                }
                break;
            }
            case '\t': {
                if (flag == 0) {
                    index_1 = 0;
                    flag = 1;
                } else {
                    index_2 = 0;
                    flag = 0;
                }
                break;
            }
            default:
                break;
        }
        // Обновить отображение файлов при изменении окна
        if (flag == 0) {
            display_files(first_win, path_1, index_1);
        } else {
            display_files(second_win, path_2, index_2);
        }
    }

    free(path_1);
    free(path_2);
    delwin(first_win);
    delwin(second_win);
    endwin();
    return 0;
}
