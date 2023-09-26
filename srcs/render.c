/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:47:23 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/25 20:58:38 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calc_wall_dist(char **map, t_render *r, t_camera *camera)
{
	render_hit(map, r);
	if (r->ray.wall_face == 'E' || r->ray.wall_face == 'W')
	{
		r->perp_wall_dist = (r->map_x - camera->pos.x
				+ (1 - r->step_x) / 2) / r->eye_x;
	}
	else
	{
		r->perp_wall_dist = (r->map_y - camera->pos.y
				+ (1 - r->step_y) / 2) / r->eye_y;
	}
	r->ray.distance = r->perp_wall_dist;
	r->wall_height = (int)((float)SCREEN_HEIGHT
			/ get_corrected_distance(r->ray.distance,
				r->ray_angle - camera->dir.x));
	r->half_wall_height = r->wall_height / 2;
	r->draw_start = -r->half_wall_height + r->half_screen_height;
	r->draw_end = r->half_wall_height + r->half_screen_height;
	r->line_height = r->draw_end - r->draw_start;
	r->wall_x;
	if (r->ray.wall_face == 'N' || r->ray.wall_face == 'S')
		r->wall_x = camera->pos.x + r->perp_wall_dist * r->eye_x;
	else
		r->wall_x = camera->pos.y + r->perp_wall_dist * r->eye_y;
	r->wall_x -= floor(r->wall_x);
}

void	apply_text_wall(char **map, t_render *r, t_camera *camera, t_s *s)
{
	calc_wall_dist(map, r, camera);
	if (r->ray.wall_face == 'N')
		r->tex_num = 0;
	else if (r->ray.wall_face == 'S')
		r->tex_num = 1;
	else if (r->ray.wall_face == 'W')
		r->tex_num = 2;
	else
		r->tex_num = 3;
	r->tex_x = (int)(r->wall_x * (float)s->xpm[r->tex_num].width);
	if (((r->ray.wall_face == 'N' || r->ray.wall_face == 'S') && r->eye_x > 0)
		|| ((r->ray.wall_face == 'W' || r->ray.wall_face == 'E')
			&& r->eye_y < 0))
		r->tex_x = s->xpm[r->tex_num].width - r->tex_x - 1;
	r->step = 1.0 * s->xpm[r->tex_num].height / r->line_height;
	r->tex_pos = (r->draw_start - r->half_screen_height
			+ r->line_height / 2) * r->step;
}

void	render_by_pixels(t_s *s, t_render *r, int *j, int *i)
{
	*j = r->draw_start;
	while (*j < r->draw_end)
	{
		r->tex_y = (int)r->tex_pos & (s->xpm[r->tex_num].height - 1);
		r->tex_pos += r->step;
		s->p->color = get_wall_face_color(s, r->ray.wall_face,
				abs(r->tex_x), abs(r->tex_y));
		my_mlx_pixel_put(s->img, abs(*i), abs(*j), s->p->color);
		(*j)++;
	}
}

void	eye_position(t_camera *camera, t_render *r)
{
	if (r->eye_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (camera->pos.x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - camera->pos.x) * r->delta_dist_x;
	}
	if (r->eye_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (camera->pos.y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - camera->pos.y) * r->delta_dist_y;
	}	
}

void	render(t_camera *camera, char **map, t_s *s)
{
	t_render	r;
	int			i;
	int			j;

	r.inv_num_rays = 1.0f / NUM_RAYS;
	r.half_screen_height = SCREEN_HEIGHT / 2;
	r.fov_offset = FOV / 2.0;
	r.fov_times_inv_num_rays = FOV * r.inv_num_rays;
	i = 0;
	while (i < NUM_RAYS)
	{
		render_init(&r, camera, i);
		eye_position(camera, &r);
		apply_text_wall(map, &r, camera, s);
		render_by_pixels(s, &r, &j, &i);
		i++;
	}
}
