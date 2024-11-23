/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:02:15 by hadia             #+#    #+#             */
/*   Updated: 2024/11/23 18:04:30 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bullet.h" 

Bullet bullets[NUM_BULLETS];//constante nombre de tir max

void init_bullets()
{

    int i = 0;
    while (i < NUM_BULLETS) {
        bullets[i].active = 0;
        i++;
    }
} //les tirs sont inactifs au depart

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
}//fait apparaitre les tirs a la position du player +1, soit juste devant lui

//fonction qui fait avancer les tirs, mais les tirs ne sortent pas de l'ecran
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

//fonction pour l'apparance des tirs
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

