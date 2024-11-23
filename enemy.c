#include "enemy.h"
#include "enemy_bullets.h"
#include "player.h"

Enemy enemies[NUM_ENEMIES]; //constante nombre d'ennemis max a l'ecran

void init_enemies() {
    int i = 0;
    while (i < NUM_ENEMIES) {
        enemies[i].x = -1; // Ennemi inactif
        enemies[i].y = -1;
        i++;
    }
}
//fonction apparition des ennemis
void spawn_enemy() {
    int i = 0;
    while (i < NUM_ENEMIES) {
        if (enemies[i].x == -1) { // Cherche un emplacement inactif
            enemies[i].x = COLS - 1; //apparition a l'extremite droite
            enemies[i].y = rand() % LINES; //position aleatoire sur y
            break;
        }
        i++;
    }
}

void move_enemies() {
    int i = 0;
    while (i < NUM_ENEMIES) {
        if (enemies[i].x >= 0) {
            enemies[i].x--; //deplce ennemi petit a petit
            if (enemies[i].x < 0) { // Ennemi sorti de l'écran
                enemies[i].x = -1; // Désactiver l'ennemi
            }
			else {
				if (enemies[i].x <= player_x + 50)
					fire_enemy_bullet(i);
				}
        }
        i++;
    }
}

//fonction qui affiche enemis a une position initial lors de l'apparition 
void display_enemies() {
    int i = 0;
    while (i < NUM_ENEMIES) {
        if (enemies[i].x >= 0) { //actif
            mvaddch(enemies[i].y, enemies[i].x, 'E');
        }
        i++;
    }
}
