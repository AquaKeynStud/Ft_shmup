/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:08:59 by arocca            #+#    #+#             */
/*   Updated: 2024/11/24 17:20:35 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <ncurses.h>
#include <stdlib.h>
#include "utils.h"

// Tableau de structure representant des obstacles
typedef struct {
	int x, y;
} star;

extern star stars[NUM_STARS];

void init_background();
void display_background();
void move_background();

#endif