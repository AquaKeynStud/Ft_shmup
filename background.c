#include <ncurses.h>
#include <stdlib.h>
#include "background.h"

star stars[NUM_STARS];

void	init_background()
{
	int i = 0;
    while (i < NUM_STARS) {
		stars[i].x = rand() % COLS;  // Choisir une colonne aléatoire
        stars[i].y = rand() % LINES; // Choisir une ligne aléatoire
        i++;
    }
}

void	move_background()
{
	int i = 0;
	while (i < NUM_STARS) {
        if (stars[i].x >= 0) { //actif
            stars[i].x -= 1;
			if (stars[i].x <= 0) {
				stars[i].x = COLS;
        		stars[i].y = rand() % LINES; // Choisir une ligne aléatoire
			} 
        }
        i++;
    }
}

void display_background() {
	int i = 0;
    while (i < NUM_STARS) {
        if (stars[i].x >= 0) { //actif
            mvaddch(stars[i].y, stars[i].x, '.');
        }
        i++;
    }
}