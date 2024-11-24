#include "game.h"

int score = 0;
int live = 3;
int game_over = 0;
int you_win = 0;
int games = 0;

int sec = 0;
int hours;
int minutes;
int sseconds;

void init_game() {
    init_enemies();
	init_asteroids();
    init_bullets();
	init_enemy_bullets();
	init_background();
}

void increase_time(int seconds)
{
        hours = sec / 3600;         // Calculer les heures
        minutes = (sec % 3600) / 60; // Calculer les minutes
        sseconds = sec % 60;

        sec += seconds;
}

int is_game_over() {
    return game_over;
}

int	is_wone(){
	return you_win;
}

void	replay() {
	score = 0;
	live = 3;
	game_over = 0;
	you_win = 0;
	sec = 0;
	games += 1;
	replace_player();
	init_game();
}

void	check_player_pos(){
	if (player_x < 0 || player_x > COLS || player_y < 0 || player_x > LINES)
		game_over = 1;
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

void check_collisions_asteroid() {
    int i = 0;
    while (i < NUM_SCENERY) {
        if ((asteroids[i].x > -1) && ((asteroids[i].x == player_x) || (asteroids[i].x == player_x - 1)) && asteroids[i].y == player_y) {
            player_x = asteroids[i].x - 1;
    	} // si le joueur rentre en colision avec un ennemi, le jeu s'arrete
	int j = 0;
	while (j < NUM_BULLETS) {
	    if (bullets[j].active && (((bullets[j].x == asteroids[i].x) || (bullets[j].x == asteroids[i].x + 1)) && bullets[j].y == asteroids[i].y)) {
	        asteroids[i].x = -1;
	        bullets[j].active = 0;
	    	} // si un des tirs du joueurs touche un ennemis, le score augmemte de 10
	    j++;
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

    move_bullets();
    move_enemies();
   	move_enemy_bullets(); //fait apparaitre les tirs enemies
	move_asteroids();
    check_collisions();
	check_collisions_asteroid();
	if (live <= 0) game_over = 1;
	else if (score >= 100) you_win = 1;
    // Faire apparaître un ennemi toutes les X itérations
    spawn_counter++;
    if (spawn_counter >= 20) { // limite le nombre d'apparition d'ennemis a 20
        spawn_enemy();
		spawn_asteroid();
        spawn_counter = 0;
    }
}

void draw_game() {
	display_background();
    display_player();
    display_bullets();
    display_enemies(); //fait apparaitre le joueur, les ennemis, et les tirs a leur position initial
	display_enemy_bullets(); //fait apparaitre les tirs enemis
	display_asteroids();
    mvprintw(0, 0, "Score: %d", score); // fait apparaitre le score en haut de l'ecran
	mvprintw(0, 50, "Lives: %d", live); // fait apparaitre la vie en haut au milieu
	mvprintw(0, 100, "Time: %02d:%02d:%02d", hours, minutes, sseconds);
	mvprintw(0, 150, "Replayed: %d times", games); // Fait apparître le nombre de fois que le joueur a restart
}
