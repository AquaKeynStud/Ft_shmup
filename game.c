#include "game.h"

int score = 0;
int live = 3;
int game_over = 0;

void init_game() {
    init_enemies();
    init_bullets();
	init_enemy_bullets();
	init_background();
}

int is_game_over() {
    return game_over;
}

void check_collisions() {
    int i = 0;
    while (i < NUM_ENEMIES) {
        if (enemies[i].x == player_x && enemies[i].y == player_y) {
            live -= 1;
    	} // si le joueur rentre en colision avec un ennemi, le jeu s'arrete
	int j = 0;
	while (j < NUM_BULLETS) {
	    if (bullets[j].active && (((bullets[j].x == enemies[i].x) || (bullets[j].x == enemies[i].x + 1)) && bullets[j].y == enemies[i].y)) {
	        enemies[i].x = -1;
	        bullets[j].active = 0;
	        score += 10;
	    	} // si un des tirs du joueurs touche un ennemis, le score augmemte de 10
	    j++;
		}
	int k = 0;
	while (k < NUM_ENEMY_BULLETS) {
	    if (enemy_bullets[k].active && (((enemy_bullets[k].x == player_x) || (enemy_bullets[k].x == player_x - 1)) && enemy_bullets[k].y == player_y)) {
	        enemy_bullets[k].active = 0;
			live -= 1;
	    	} // si un des tirs ennemis touche le joueur, la vie diminue de 1
	    k++;
		}
	i++;
    }
}

void handle_input(int ch) {
    move_player(ch);
    if (ch == ' ') fire_bullet();
} // espace actionne un tir

void update_game() {
    static int spawn_counter = 0;
	int gen = 0;

	gen += 1;
	if (gen % 5 == 0)
	{
		init_background();
		gen = 0;
	}

    move_bullets();
    move_enemies();
   	move_enemy_bullets(); //fait apparaitre les tirs enemies
    check_collisions();
	if (live <= 0) game_over = 1;

    // Faire apparaître un ennemi toutes les X itérations
    spawn_counter++;
    if (spawn_counter >= 20) { // limite le nombre d'apparition d'ennemis a 20
        spawn_enemy();
        spawn_counter = 0;
    }
}


void draw_game() {
    display_player();
    display_bullets();
    display_enemies(); //fait apparaitre le joueur, les ennemis, et les tirs a leur position initial
	display_enemy_bullets(); //fait apparaitre les tirs enemis
    mvprintw(0, 0, "Score: %d", score); // fait apparaitre le score en haut de l'ecran
	mvprintw(0, 50, "Lives: %d", live); // fait apparaitre la vie en haut au milieu
}
