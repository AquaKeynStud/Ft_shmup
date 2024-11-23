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

	getch();
    init_game();

	timeout(0);
    int ch;

    while (1) {
        if (is_game_over()) break;
		ch = getch();
		if (ch == 'q') break;

		if (ch != ERR) handle_input(ch);

		update_game();

		clear();
		draw_game();
        refresh();
		
        napms(100);
    }

    endwin();
    return 0;
}
