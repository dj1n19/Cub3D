/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:53:34 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/26 15:27:13 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_init(t_render *r, t_camera *camera, int i)
{
	r->ray_angle = (camera->dir.x - r->fov_offset)
		+ ((float)i * r->fov_times_inv_num_rays);
	r->map_x = (int)camera->pos.x;
	r->map_y = (int)camera->pos.y;
	r->eye_x = sin(r->ray_angle);
	r->eye_y = cos(r->ray_angle);
	r->delta_dist_x = fabs(1 / r->eye_x);
	r->delta_dist_y = fabs(1 / r->eye_y);
}

void	render_hit(char **map, t_render *r)
{
	r->hit = 0;
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			if (r->step_x == 1)
				r->ray.wall_face = 'E';
			else
				r->ray.wall_face = 'W';
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			if (r->step_y == 1)
				r->ray.wall_face = 'N';
			else
				r->ray.wall_face = 'S';
		}
		if (map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}
