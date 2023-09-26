/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_straf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:45:42 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/26 22:44:22 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_player_movement_right(t_player *p, t_key_states *ks,
	t_map *m)
{
	(void)m;
	if (ks->west == true)
	{
		p->delta_x = cos(p->player_angle - M_PI_2) * 5;
		p->delta_y = sin(p->player_angle - M_PI_2) * 5;
		if (!is_wall(m->map, ((p->x + p->delta_x) / 20 - COLLISION_MARGIN),
				((p->y + p->delta_y) / 20 - COLLISION_MARGIN)))
		{
			p->x += p->delta_x / 2;
			p->y += p->delta_y / 2;
		}
	}
}

void	update_player_movement_left(t_player *p, t_key_states *ks,
	t_map *m)
{
	(void)m;
	if (ks->east == true)
	{
		p->delta_x = cos(p->player_angle + M_PI_2) * 5;
		p->delta_y = sin(p->player_angle + M_PI_2) * 5;
		if (!is_wall(m->map, ((p->x + p->delta_x) / 20 + COLLISION_MARGIN),
				((p->y + p->delta_y) / 20 + COLLISION_MARGIN)))
		{
			p->x += p->delta_x / 2;
			p->y += p->delta_y / 2;
		}
	}
}
