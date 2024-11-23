#include "enemy_bullets.h"

// Tableau global pour stocker les tirs ennemis
EnemyBullet enemy_bullets[NUM_ENEMY_BULLETS];

// Initialisation des tirs ennemis
void init_enemy_bullets() {
    for (int i = 0; i < NUM_ENEMY_BULLETS; i++) {
        enemy_bullets[i].active = 0;
    }
}

// Un ennemi tire un projectile
void fire_enemy_bullet(int i) {
	//(void)enemy_index;
    if (!enemy_bullets[i].active) {
            enemy_bullets[i].active = 1;
    }
}

// Déplacement des tirs ennemis
void move_enemy_bullets() {
    for (int i = 0; i < NUM_ENEMY_BULLETS; i++) {
        if (enemy_bullets[i].active) {
            enemy_bullets[i].x -= 2;
            if (enemy_bullets[i].x < 0) {
                enemy_bullets[i].active = 0; // Désactiver si hors écran
            }
        }
		else {
			enemy_bullets[i].x = enemies[i].x - 1; // Position X de l'ennemi
        	enemy_bullets[i].y = enemies[i].y; // Position Y aléatoire de l'ennemi
		}
    }
}

// Affichage des tirs ennemis
void display_enemy_bullets() {
    for (int i = 0; i < NUM_ENEMY_BULLETS; i++) {
		mvaddch(enemy_bullets[i].y, enemy_bullets[i].x, '*');
    }
}
