#ifndef ENEMY_BULLETS_H
#define ENEMY_BULLETS_H

#include <ncurses.h>
#include "utils.h"
#include "enemy.h"

// Structure pour représenter un tir ennemi
typedef struct {
    int x, y;
    int active; // 1 si le tir est actif, 0 sinon
} EnemyBullet;

// Déclaration des variables externes
extern EnemyBullet enemy_bullets[NUM_ENEMY_BULLETS];

// Déclaration des fonctions
void init_enemy_bullets();
void fire_enemy_bullet();
void move_enemy_bullets();
void display_enemy_bullets();

#endif // ENEMY_BULLETS_H

