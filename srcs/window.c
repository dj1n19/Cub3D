/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:29:39 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/17 23:34:54 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	paint_frame(t_s *s)
{
	update_player_movement(s->player, &s->key_states, s->map, 0.5);
	s->player->delta_x = cos(s->player->player_angle) * 5;
	s->player->delta_y = sin(s->player->player_angle) * 5;
	display_ceiling_floor(*s->img, s->map);
	cast_rays(s);
	draw_map_2d(s->map, s->img, s->p, s->player);
	mlx_put_image_to_window(s->p->mlx, s->p->mlx_win, s->xpm[4].img, 150, 150);
	mlx_put_image_to_window(s->p->mlx, s->p->mlx_win, s->img->img, 0, 0);
	return (0);
}

static void	init_struct(t_s *s, t_map *map)
{
	s->key_states.east = false;
	s->key_states.west = false;
	s->key_states.north = false;
	s->key_states.south = false;
	s->player->x = map->def_x;
	s->player->y = map->def_y;
	s->player->player_angle = M_PI_2;
	if (s->map->map_len > s->map->map_lenght)
	{
		s->map->map_max = s->map->map_len;
	}
	else
		s->map->map_max = s->map->map_lenght;
	s->map->map_line = concatenate_string_array(map->map, map->map_len);
}

static void	ft_allocate_struct(t_s *s)
{
	s->p = ft_malloc(1 * sizeof(t_mlx), NULL, MALLOC);
	s->img = ft_malloc(1 * sizeof(t_data), NULL, MALLOC);
	s->player = ft_malloc(1 * sizeof(t_player), NULL, MALLOC);
}

void	display_window(t_map *map)
{
	t_s	s;

	s.map = map;
	ft_allocate_struct(&s);
	init_struct(&s, map);
	printf("x : %f, y : %f\n", s.player->x, s.player->y);
	s.p->mlx = mlx_init();
	s.p->mlx_win = mlx_new_window(s.p->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, TITLE_SCREEN);
	s.img->img = mlx_new_image(s.p->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	s.img->addr = mlx_get_data_addr(s.img->img, &s.img->bits_per_pixel,
			&s.img->line_length, &s.img->endian);
	s.start_time = get_current_microseconds();
	load_textures(&s);
	mlx_hook(s.p->mlx_win, 3, 1L << 0, relase_key_hook, &s.key_states);
	mlx_hook(s.p->mlx_win, 2, 1L << 1, key_hook, &s.key_states);
	mlx_loop_hook(s.p->mlx, paint_frame, &s);
	mlx_loop(s.p->mlx);
}
