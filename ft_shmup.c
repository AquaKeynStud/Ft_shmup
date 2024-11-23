#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

// Structures pour les tirs et les ennemis
typedef struct {
    int x, y;
    int active; // 1 si le tir est actif, 0 sinon
} Bullet;

typedef struct {
    int x, y;
} Enemy;

// Déclarations globales
#define NUM_ENEMIES 10
#define NUM_BULLETS 5
Bullet bullets[NUM_BULLETS];
Enemy enemies[NUM_ENEMIES];
int player_x = 10, player_y = 10;
int score = 0;
int game_over = 0;

// Initialisation des ennemis
void spawn_enemy(int index) {
    enemies[index].x = COLS - 1;
    enemies[index].y = rand() % LINES;
}

void init_enemies() {
    for (int i = 0; i < NUM_ENEMIES; i++) {
        spawn_enemy(i);
    }
}

void display_enemies() {
    for (int i = 0; i < NUM_ENEMIES; i++) {
        if (enemies[i].x >= 0) {
            mvaddch(enemies[i].y, enemies[i].x, 'E');
        }
    }
}

void move_enemies() {
    for (int i = 0; i < NUM_ENEMIES; i++) {
        if (enemies[i].x >= 0) {
            enemies[i].x--;
        }
    }
}

// Initialisation des tirs
void init_bullets() {
    for (int i = 0; i < NUM_BULLETS; i++) {
        bullets[i].active = 0;
    }
}

void fire_bullet() {
    for (int i = 0; i < NUM_BULLETS; i++) {
        if (!bullets[i].active) {
            bullets[i].x = player_x + 1;
            bullets[i].y = player_y;
            bullets[i].active = 1;
            break;
        }
    }
}

void move_bullets() {
    for (int i = 0; i < NUM_BULLETS; i++) {
        if (bullets[i].active) {
            bullets[i].x++;
            if (bullets[i].x >= COLS) {
                bullets[i].active = 0;
            }
        }
    }
}

void display_bullets() {
    for (int i = 0; i < NUM_BULLETS; i++) {
        if (bullets[i].active) {
            mvaddch(bullets[i].y, bullets[i].x, '|');
        }
    }
}

// Gestion des collisions
void check_collisions() {
    for (int i = 0; i < NUM_ENEMIES; i++) {
        if (enemies[i].x == player_x && enemies[i].y == player_y) {
            game_over = 1;
        }
        for (int j = 0; j < NUM_BULLETS; j++) {
            if (bullets[j].active && bullets[j].x == enemies[i].x && bullets[j].y == enemies[i].y) {
                enemies[i].x = -1;
                bullets[j].active = 0;
                score += 10;
            }
        }
    }
}

// Gestion du joueur
void display_player() {
    mvaddch(player_y, player_x, 'b');
}

void move_player(int ch) {
    switch(ch) {
        case KEY_UP:    if (player_y > 0) player_y--; break;
        case KEY_DOWN:  if (player_y < LINES - 1) player_y++; break;
        case KEY_LEFT:  if (player_x > 0) player_x--; break;
        case KEY_RIGHT: if (player_x < COLS - 1) player_x++; break;
    }
}

// Fonction principale
int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    srand(time(NULL));

    init_enemies();
    init_bullets();

    int ch;
    while ((ch = getch()) != 'q') {
        if (game_over) break;

        clear();
        move_player(ch);
        display_player();
        if (ch == ' ') fire_bullet();
        move_bullets();
        display_bullets();
        move_enemies();
        display_enemies();
        check_collisions();
        mvprintw(0, 0, "Score: %d", score);
        refresh();
        napms(200);
    }

    endwin();
    return 0;
}

