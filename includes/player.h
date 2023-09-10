/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:34:00 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/10 17:52:06 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "event.h"
# include "map.h"
# include "constants.h"

/*
*	structure de gestion du joueur
*/
typedef struct s_player
{
	float delta_x;
	float delta_y;
	float player_angle;
	float x;
	float y;
}	t_player;

void update_player_movement(t_player *p, t_key_states *ks, t_map *m, double delta_time);

#endif