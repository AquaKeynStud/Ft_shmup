#include <ncurses.h>
#include <stdlib.h>

void	init_background()
{
	for (int i = 0; i < 100; i++)
	{
		int x = rand() % COLS;  // Choisir une colonne aléatoire
        int y = rand() % LINES; // Choisir une ligne aléatoire
		mvaddch(y, x, '.');
	}
}
