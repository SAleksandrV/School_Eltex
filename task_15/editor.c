#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 255

int main()
{
    char file_name[SIZE];

    // Initialize Ncurses
    initscr();

    // Request file name
    printw("Enter the file name: ");
    refresh();
    getstr(file_name);

    // Create window with border
    WINDOW *win = newwin(LINES - 2, COLS - 2, 1, 1);
    box(win, 0 ,0);
    refresh();
    wrefresh(win);
    keypad(win, TRUE);

    // Open file
    FILE *file = fopen(file_name, "r+");
    if (file == NULL)
    {
        printw("File opening error.\n");
        refresh();
        getch();
        endwin();
        exit(EXIT_FAILURE);
    }

    // Read and display file content in the window
    char sym;
    int row = 1, col = 1;
    while ((sym = fgetc(file)) != EOF)
    {
        mvwaddch(win, row, col, sym);
        col++;
        if (col == COLS - 2)
        {
            col = 1;
            row++;
        }
    }

    fseek(file, 0, SEEK_SET);

    // Modify file content
    char new_sym;
    while ((new_sym = wgetch(win)) != KEY_F(10))
    {
        if (new_sym == KEY_BACKSPACE || new_sym == '\b')
        {
            col--;
            if (col < 1) {
                col = COLS - 2;
                row--;
                if (row < 1)
                {
                    row = 1;
                }
            }
            mvwaddch(win, row, col, ' ');
            fseek(file, (row - 1) * (COLS - 2) + (col - 1), SEEK_SET);
            fputc(' ', file);
        } else if (new_sym == '\n')
        {
            col = 1;
            row++;
            if (row >= LINES - 2)
            {
                row = LINES - 2;
            }
            fseek(file, (row - 1) * (COLS - 2), SEEK_SET);
        } else
        {
            mvwaddch(win, row, col, new_sym);
            fseek(file, (row - 1) * (COLS - 2) + (col - 1), SEEK_SET);
            fputc(new_sym, file);
            col++;
            if (col >= COLS - 2)
            {
                col = COLS - 2;
            }
        }
        wrefresh(win);
    }

    // Save file
    fclose(file);

    // Close window and exit program
    endwin();
    return 0;
}
