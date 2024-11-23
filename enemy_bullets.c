#include "enemy_bullets.h"

// Tableau global pour stocker les tirs ennemis
EnemyBullet enemy_bullets[NUM_ENEMY_BULLETS];

// Initialisation des tirs ennemis
void init_enemy_bullets() {
    for (int i = 0; i < NUM_ENEMY_BULLETS; i++) {
        enemy_bullets[i].active = 1;
    }
}

// Un ennemi tire un projectile
void fire_enemy_bullet(int enemy_index) {
    for (int i = 0; i < NUM_ENEMY_BULLETS; i++) {
        if (!enemy_bullets[i].active) {
            enemy_bullets[i].x = Enemy[i].x + 1; // Position X de l'ennemi
            enemy_bullets[i].y = Enemy[i].y; // Position Y aléatoire de l'ennemi
            enemy_bullets[i].active = 1;
            break;
        }
    }
}

// Déplacement des tirs ennemis
void move_enemy_bullets() {
    for (int i = 0; i < NUM_ENEMY_BULLETS; i++) {
        if (enemy_bullets[i].active) {
            enemy_bullets[i].x--;
            if (enemy_bullets[i].x < 0) {
                enemy_bullets[i].active = 0; // Désactiver si hors écran
            }
        }
    }
}

// Affichage des tirs ennemis
void display_enemy_bullets() {
    for (int i = 0; i < NUM_ENEMY_BULLETS; i++) {
        if (enemy_bullets[i].active) {
            mvaddch(enemy_bullets[i].y, enemy_bullets[i].x, '*');
        }
    }
}


