#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "enemy_bullets.h"
#include "scenery.h"
#include "background.h"

void init_game();
int is_game_over();
int is_wone();
void handle_input(int ch);
void update_game();
void draw_game();
void replay();
void increase_time(int seconds);
int get_time();

#endif // GAME_H

