/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:35:44 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/16 15:42:11 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	update_player_movement_down(t_player *p, t_key_states *ks,
	t_map *m, double delta_time)
{
	if (ks->south == true)
	{
		if (!is_wall(m->map, ((p->x - p->delta_x) / 20 - COLLISION_MARGIN),
				((p->y - p->delta_y) / 20 - COLLISION_MARGIN)))
		{
			p->x -= p->delta_x / 2;
			p->y -= p->delta_y / 2;
		}
		else if (!is_wall(m->map, p->x / 20 - COLLISION_MARGIN,
				((p->y - p->delta_y) / 20 - COLLISION_MARGIN)))
		{
			p->y -= p->delta_y / 4;
		}
		else if (!is_wall(m->map, ((p->x - p->delta_x) / 20 - COLLISION_MARGIN),
				(p->y / 20 - COLLISION_MARGIN)))
		{
			p->x -= p->delta_x / 4;
		}
	}
}

static void	update_player_movement_up(t_player *p, t_key_states *ks,
	t_map *m, double delta_time)
{
	if (ks->north == true)
	{
		if (!is_wall(m->map, ((p->x + p->delta_x) / 20 + COLLISION_MARGIN),
				((p->y + p->delta_y) / 20 + COLLISION_MARGIN)))
		{
			p->x += p->delta_x / 2;
			p->y += p->delta_y / 2;
		}
		else if (!is_wall(m->map, ((p->x + p->delta_x) / 20 + COLLISION_MARGIN),
				(p->y / 20 + COLLISION_MARGIN)))
		{
			p->x += p->delta_x / 4;
		}
		else if (!is_wall(m->map, p->x / 20 + COLLISION_MARGIN,
				((p->y + p->delta_y) / 20 + COLLISION_MARGIN)))
		{
			p->y += p->delta_y / 4;
		}
	}
}

static void	update_player_movement_left_right(t_player *p,
	t_key_states *ks, double delta_time)
{
	if (ks->east == true)
	{
		p->player_angle -= PI / 60 * delta_time * 1.0;
		if (p->player_angle < 0)
		{
			p->player_angle = 2 * PI;
		}
		p->delta_x = (cos(p->player_angle) * 2);
		p->delta_y = (sin(p->player_angle) * 2);
	}
	if (ks->west == true)
	{
		p->player_angle += PI / 60 * delta_time * 1.0;
		if (p->player_angle > 2 * PI)
		{
			p->player_angle = 0;
		}
		p->delta_x = (cos(p->player_angle) * 2);
		p->delta_y = (sin(p->player_angle) * 2);
	}
}

void	update_player_movement(t_player *p, t_key_states *ks,
	t_map *m, double delta_time)
{
	update_player_movement_left_right(p, ks, delta_time);
	update_player_movement_up(p, ks, m, delta_time);
	update_player_movement_down(p, ks, m, delta_time);
}
