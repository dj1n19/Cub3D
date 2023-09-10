/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:15:42 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/10 16:21:06 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_big_line(t_s *s, int x0, int y0, int x1, int y1, int thick)
{
	int above;
	int i;

	above = thick / 2;
	i = 0;
	while (i != above)
	{
		draw_line_minimap(s, x0 + i, y0 + i, x1 + i, y1 + i);
		draw_line_minimap(s, x0 - i, y0 - i, x1 - i, y1 - i);
		i++;
	}
}

void draw_circle(t_s *s, int x0, int y0, int radius)
{
    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -radius; x <= radius; x++)
        {
            if (x * x + y * y <= radius * radius)
            {
				my_mlx_pixel_put(s->img, x0 + x, y0 + y, s->p->color);
            }
        }
    }
}

void draw_square_minimap(t_s *s, int x, int y, int size_x, int size_y)
{
    // Vérification que les coordonnées ne débordent pas de l'écran
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x + size_x >= SCREEN_HEIGHT) size_x = SCREEN_HEIGHT - x - 1;
    if (y + size_y >= SCREEN_WIDTH) size_y = SCREEN_WIDTH - y - 1;

    int i;
    int j;

    // Boucle pour dessiner chaque pixel du carré
    i = y;
    while (i <= y + size_y)
    {
        j = x;
        while (j <= x + size_x)
        {
            // Vérification que les coordonnées ne débordent pas de l'écran
            if (i >= 0 && i < SCREEN_WIDTH && j >= 0 && j < SCREEN_HEIGHT && point_in_circle(i, j, MINIMAP_X, MINIMAP_Y, 150))
            {
                my_mlx_pixel_put(s->img, i, j, s->p->color);
            }
            j++;
        }
        i++;
    }
}

float	ft_square(float f)
{
	return(f * f);
}

float	distance(float y1, float x1, float y2, float x2)
{
	return (sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2)));
}

void	clear_window(t_s *s)
{
	int i;
	int j;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(s->img, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

void	display_ceiling_floor(t_data img, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < SCREEN_HEIGHT_1)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&img, j, i, map->Ceiling_color);
			j++;
		}
		i++;
	}
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(&img, j, i, map->floor_color);
			j++;
		}
		i++;
	}
}

void	ft_allocate_struct(t_s *s)
{
	s->p = malloc(1 * sizeof(t_mlx));
	if (!s->p)
		exit(EXIT_FAILURE);
	s->img = malloc(1 * sizeof(t_data));
	if (!s->img)
	{
		free(s->p);
		exit(EXIT_FAILURE);
	}
	s->player = malloc(1 * sizeof(t_player));
	if (!s->player)
	{
		free(s->p);
		free(s->img);
		exit(EXIT_FAILURE);
	}
}

int	relase_key_hook(int	keycode, t_s *s)
{
    if (keycode == EAST)
        s->key_states.east = false;
    else if (keycode == WEST)
        s->key_states.west = false;
    else if (keycode == NORTH)
        s->key_states.north = false;
    else if (keycode == SOUTH)
        s->key_states.south = false;
    return (0);
}

int key_hook(int keycode, t_s *s)
{
	// printf("KEY: %d\n", keycode);
    if (keycode == 53)
        exit(0);
    else if (keycode == EAST)
        s->key_states.east = true;
    else if (keycode == WEST)
        s->key_states.west = true;
    else if (keycode == NORTH)
        s->key_states.north = true;
    else if (keycode == SOUTH)
        s->key_states.south = true;
    return (0);
}

static double fps_counter(t_s *s)
{
	static int frameCounter = 0;
	long long elapsedTime;
	double fps;

	fps = 0;
	frameCounter++;
	if (frameCounter >= NUM_FRAMES_TO_MEASURE)
	{
		elapsedTime = get_current_microseconds() - s->start_time;
		fps = (double)frameCounter / (elapsedTime / 1e6);
		frameCounter = 0;
		s->start_time = get_current_microseconds();
	}
	return (fps);
}

int	paint_frame(t_s *s)
{
	double	fps;

	update_player_movement(s, 0.5);
	s->player->delta_x = cos(s->player->player_angle) * 5;
	s->player->delta_y = sin(s->player->player_angle) * 5;
	display_ceiling_floor(*s->img, s->map);
	cast_rays(s);
	draw_map_2d(s);
	mlx_put_image_to_window(s->p->mlx, s->p->mlx_win, s->xpm[4].img, 150, 150);
	mlx_put_image_to_window(s->p->mlx, s->p->mlx_win, s->img->img, 0, 0);
	fps = fps_counter(s);
	mlx_string_put(s->p->mlx, s->p->mlx_win, SCREEN_WIDTH - 40, SCREEN_HEIGHT - 40, 0xFFFF00FF, ft_itoa((int)fps));
	return (0);
}

void	init_struct(t_s *s, t_map *map)
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

void	display_window(t_map *map)
{
	t_s s;

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
	mlx_hook(s.p->mlx_win, 3, 1L<<0, relase_key_hook, &s);
	mlx_hook(s.p->mlx_win, 2, 1L<<1, key_hook, &s);
	mlx_loop_hook(s.p->mlx, paint_frame, &s);
	mlx_loop(s.p->mlx);
}
