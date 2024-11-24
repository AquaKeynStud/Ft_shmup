#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "enemy_bullets.h"
#include "scenery.h"
#include "game.h"
#include "menu.h"

int	stop_game() {
	endwin();
	return 0;
}

int main() {
	int ticks = 0;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand(time(NULL));

    display_start_page();

    int ch;
    while ((ch = getch()) != 's') {
        if (ch == 'q') {
            endwin();
            return 0;
        }
    }

    while (1) { // Boucle principale du jeu

        init_game();
        timeout(0);

        while (1) { // Boucle de la partie en cours
            if (is_game_over() || is_wone()) {
                display_end_page(is_wone(), is_game_over());
                while (1) { // Gérer les options du menu de fin
                    ch = getch();
                    if (ch == 'r') {
						replay();
                        break;
                    }
                    if (ch == 'q') {
                        stop_game(); // Quitter le jeu
                    }
                }
                break; // Sort de la boucle de la partie en cours pour redémarrer
            }

            ch = getch();
            if (ch == 'q') return stop_game();
            if (ch != ERR) handle_input(ch);

            update_game();

            clear();
            draw_game();
			ticks += 1;
			move_background();
            refresh();
            napms(100);
			if ((ticks % 10) == 0)
				increase_time(1);
        }
    }
    stop_game();
}

