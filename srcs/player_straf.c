/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_straf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:45:42 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/26 17:10:09 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_player_movement_right(t_player *p, t_key_states *ks,
	t_map *m)
{
	(void)m;
	if (ks->west == true)
	{
		if (!is_wall(m->map, ((p->x - p->delta_x) / 20 - COLLISION_MARGIN), ((p->y - p->delta_y) / 20 - COLLISION_MARGIN)))
		{
			p->y -= p->delta_x / 2;
			p->x -= p->delta_y / 2;
		}
	}
}

void	update_player_movement_left(t_player *p, t_key_states *ks,
	t_map *m)
{
	(void)m;
	if (ks->east == true)
	{
		if (!is_wall(m->map, ((p->x + p->delta_x) / 20 + COLLISION_MARGIN), ((p->y + p->delta_y) / 20 + COLLISION_MARGIN)))
		{
			p->y += p->delta_x / 2;
			p->x += p->delta_y / 2;
		}
	}
}