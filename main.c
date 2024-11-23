#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "enemy_bullets.h"
#include "game.h"

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand(time(NULL));
	printw("press any key to start the game");
	refresh();
    init_game();

    int ch;
    while ((ch = getch()) != 'q') {
        if (is_game_over()) break;

        clear();
        handle_input(ch);
        update_game();
        draw_game();
        refresh();
        napms(200);
    }

    endwin();
    return 0;
}
