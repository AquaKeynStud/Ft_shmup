#ifndef MENU_H
#define MENU_H

#include <ncurses.h>

// Affiche la page de démarrage
void display_start_page();
void display_end_page(int player_won, int player_loose);
#endif // MENU_H
