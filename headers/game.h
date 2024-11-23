#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "enemy_bullets.h"

void init_game();
int is_game_over();
void handle_input(int ch);
void update_game();
void draw_game();
void init_background();

#endif // GAME_H

