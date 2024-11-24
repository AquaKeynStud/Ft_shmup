#include "player.h"
#include "scenery.h"

Asteroid asteroids[NUM_SCENERY]; // Constante nombre obstacles a l'ecran

void init_asteroids() {
	int i = 0;
    while (i < NUM_SCENERY) {
        asteroids[i].x = -1; // asteroid inactif
        asteroids[i].y = -1;
		asteroids[i].traj = rand() % 2;
		asteroids[i].traj -= (asteroids[i].traj == 0);
        i++;
    }
}

//fonction apparition des obstacles
void spawn_asteroid() {
    int i = 0;
    while (i < NUM_SCENERY) {
        if (asteroids[i].x == -1) { // Cherche un emplacement inactif
            asteroids[i].x = COLS - 1; //apparition a l'extremite droite
            asteroids[i].y = rand() % LINES; //position aleatoire sur y
            break;
        }
        i++;
    }
}

void move_asteroids() {
    int i = 0;
    while (i < NUM_SCENERY) {
        if (asteroids[i].x >= 0) {
            asteroids[i].x--; //deplace l'asteroide petit a petit
            if (asteroids[i].x < 0) { // Ennemi sorti de l'écran
                asteroids[i].x = -1; // Désactiver l'ennemi
            }
			else
			{
				int random = rand() % 25;
				if (random == 1)
					asteroids[i].y += asteroids[i].traj;
			}
        }
        i++;
    }
}

//fonction qui affiche les asteroides a une position lors de l'apparition
void display_asteroids() {
    int i = 0;
    while (i < NUM_SCENERY) {
        if (asteroids[i].x >= 0) { //actif
            mvaddch(asteroids[i].y, asteroids[i].x, 'O');
        }
        i++;
    }
}