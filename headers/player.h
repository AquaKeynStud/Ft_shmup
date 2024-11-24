#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>

extern int player_x, player_y;

void display_player();
void move_player(int ch);
void replace_player();

#endif // PLAYER_H

