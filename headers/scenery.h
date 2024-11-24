/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenery.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:02:40 by arocca            #+#    #+#             */
/*   Updated: 2024/11/24 16:37:25 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENERY_H
#define SCENERY_H

#include <ncurses.h>
#include <stdlib.h>
#include "utils.h"

// Tableau de structure representant des obstacles
typedef struct {
	int x, y;
	int traj;
} Asteroid;

extern Asteroid asteroids[NUM_SCENERY];

void init_asteroids();
void spawn_asteroid();
void move_asteroids();
void display_asteroids();

#endif