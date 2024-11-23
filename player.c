#include "player.h"

int player_x = 100, player_y = 15; //position depart du joueur

void display_player() {
    mvaddch(player_y, player_x, 'H');
}  //apparition du joueur a la position initial 

void move_player(int ch) {
    switch(ch) {
        case KEY_UP:    if (player_y > 0) player_y--; break;
        case KEY_DOWN:  if (player_y < LINES - 1) player_y++; break;
        case KEY_LEFT:  if (player_x > 0) player_x--; break;
        case KEY_RIGHT: if (player_x < COLS - 1) player_x++; break;
    }
} //mouvememt du joueur afin qu'il ne sorte pas de l'ecran

/*int main() {
    int ch;

    // Initialisation de ncurses
    initscr();            // Initialise l'écran
    cbreak();             // Désactive le buffering de ligne
    noecho();             // N'affiche pas les caractères tapés
    keypad(stdscr, TRUE); // Active la prise en charge des touches spéciales
    curs_set(0);          // Cache le curseur

    // Boucle principale
    while ((ch = getch()) != 'q') { // Appuyez sur 'q' pour quitter
        clear();              // Efface l'écran
        move_player(ch);      // Met à jour la position du joueur
        display_player();     // Affiche le joueur à la nouvelle position
        refresh();            // Rafraîchit l'écran pour afficher les changements
    }

    // Fin de ncurses
    endwin();

    return 0;
}*/


