#include "game.h"

int score = 0;
int game_over = 0;

void init_game() {
    init_enemies();
    init_bullets();
}

int is_game_over() {
    return game_over;
}

void check_collisions() {
    int i = 0;
    while (i < NUM_ENEMIES) {
        if (enemies[i].x == player_x && enemies[i].y == player_y) {
            game_over = 1;
        } // si le joueur rentre en colision avec un ennemi, le jeu s'arrete
        
	fire_enemy_bullet(enemies[i].x);
        int j = 0;
        while (j < NUM_BULLETS) {
            if (bullets[j].active && bullets[j].x == enemies[i].x && bullets[j].y == enemies[i].y) {
                enemies[i].x = -1;
                bullets[j].active = 0;
                score += 10;
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
    check_collisions();

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
}

