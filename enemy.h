/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:00:32 by hadia             #+#    #+#             */
/*   Updated: 2024/11/23 14:01:51 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
#define ENEMY_H

#include <ncurses.h>
#include <stdlib.h>
#include "utils.h"

//tableau de structure representant ennemis
typedef struct {
    int x, y;
} Enemy;

extern Enemy enemies[NUM_ENEMIES];

void init_enemies();
void spawn_enemy();
void move_enemies();
void display_enemies();

#endif // ENEMY_H

