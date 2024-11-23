#ifndef BULLET_H
#define BULLET_H

#include <ncurses.h>
#include "player.h"
#include "utils.h"

typedef struct {
    int x, y;
    int active; // 1 si actif, 0 sinon
} Bullet; //structure d'un tir

extern Bullet bullets[NUM_BULLETS];

void init_bullets();
void fire_bullet();
void move_bullets();
void display_bullets();

#endif // BULLET_H

