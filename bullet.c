#include "bullet.h" 

Bullet bullets[NUM_BULLETS];

void init_bullets()
{

    int i = 0;
    while (i < NUM_BULLETS) {
        bullets[i].active = 0;
        i++;
    }
}

void fire_bullet() 
{
    int i = 0;
    while (i < NUM_BULLETS) {
        if (!bullets[i].active) {
            bullets[i].x = player_x + 1;
            bullets[i].y = player_y;
            bullets[i].active = 1;
            break;
        }
        i++;
    }
}

void move_bullets() 
{
    int i = 0;
    while (i < NUM_BULLETS) {
        if (bullets[i].active) {
            bullets[i].x++;
            if (bullets[i].x >= COLS) {
                bullets[i].active = 0;
            }
        }
        i++;
    }
}

void display_bullets()
{
    int i = 0;
    while (i < NUM_BULLETS) {
        if (bullets[i].active) {
            mvaddch(bullets[i].y, bullets[i].x, '-');
        }
        i++;
    }
}
