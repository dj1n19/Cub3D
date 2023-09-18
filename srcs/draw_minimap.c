/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:32:03 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/18 02:25:38 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	point_in_circle(double x, double y, double r)
{
	double	distance;

	distance = sqrt(pow(x - MINIMAP_X, 2) + pow(y - MINIMAP_Y, 2));
	if (distance <= r)
		return (1);
	else
		return (0);
}

static void	draw_circle(t_data *img, t_mlx *p, int x0, int y0, int radius)
{
	int	y;
	int	x;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				my_mlx_pixel_put(img, x0 + x, y0 + y, p->color);
			x++;
		}
		y++;
	}
}

static void	draw_line_minimap(t_data *img, t_mlx *p, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	err = dx + dy;
	while (1)
	{
		if (x0 >= 0 && x0 < SCREEN_WIDTH && y0 >= 0
			&& y0 < SCREEN_HEIGHT && point_in_circle(x0, y0, 150))
			my_mlx_pixel_put(img, x0, y0, p->color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

static void	draw_big_line(t_data *img, t_mlx *p, int x0, int y0, int x1, int y1, int thick)
{
	int	above;
	int	i;

	above = thick / 2;
	i = 0;
	while (i != above)
	{
		draw_line_minimap(img, p, x0 + i, y0 + i, x1 + i, y1 + i);
		draw_line_minimap(img, p, x0 - i, y0 - i, x1 - i, y1 - i);
		i++;
	}
}

static void draw_square_minimap(t_data *img, t_mlx *p, long coordinate)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	size_x;
	int	size_y;

	x = (int)coordinate;
	y = (int)(coordinate >> 32);
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x + TILE_SIZE >= SCREEN_HEIGHT)
		size_x = SCREEN_HEIGHT - x - 1;
	if (y + TILE_SIZE >= SCREEN_WIDTH)
		size_y = SCREEN_WIDTH - y - 1;
	i = y;
	while (i <= y + size_y)
	{
		j = x;
		while (j <= x + size_x)
		{
			if (i >= 0 && i < SCREEN_WIDTH && j >= 0
				&& j < SCREEN_HEIGHT && point_in_circle(i, j, 150))
				my_mlx_pixel_put(img, i, j, p->color);
			j++;
		}
		i++;
	}
}

static void	draw_map_circle(t_data *img)
{
	int	fill_minimap_x;
	int	fill_minimap_y;

	fill_minimap_x = 0;
	while (fill_minimap_x <= 350)
	{
		fill_minimap_y = 0;
		while (fill_minimap_y <= 350)
		{
			if (point_in_circle(fill_minimap_x, fill_minimap_y, 150))
				my_mlx_pixel_put(img, fill_minimap_x, fill_minimap_y, 0x4e2823);
			else if (point_in_circle(fill_minimap_x, fill_minimap_y, 160))
				my_mlx_pixel_put(img, fill_minimap_x, fill_minimap_y, 0x182029);
			fill_minimap_y++;
		}
		fill_minimap_x++;
	}
}

static void	draw_minimap(t_data *img, t_map *map, t_mlx *p, t_map_2d *m2d)
{
	int		x;
	int		y;
	long	coordinate;

	coordinate = ((long)((x - m2d->y_tile_size) * TILE_SIZE + map->def_y)) << 32;
	coordinate += (long)((y - m2d->x_tile_size) * TILE_SIZE + map->def_x);
	y = 0;
	while (y < map->map_lenght)
	{
		x = 0;
		while (x < map->map_len)
		{
			if (map->map[y][x] == '1')
				p->color = 0x4e2823;
			else if (map->map[y][x] == '0')
				p->color = 0x397a41;
			else if (map->map[y][x] == 'O')
				p->color = 0xb96f2c;
			else if (map->map[y][x] == 'E' || map->map[y][x] == 'N'
				|| map->map[y][x] == 'S' || map->map[y][x] == 'W')
				p->color = 0x629cc5;
			draw_square_minimap(img, p, coordinate);
			x++;
		}
		y++;
	}
}

static void	draw_current_position(t_data *img, t_mlx *p,
	t_map *map, t_map_2d *m2d, t_path_return *co)
{
	long	coordinate;

	coordinate = ((long)((co->x[0] - m2d->y_tile_size) * TILE_SIZE + map->def_y)) << 32;
	coordinate += (long)((co->y[0] - m2d->x_tile_size) * TILE_SIZE + map->def_x);
	p->color = 0xaa8085;
	draw_square_minimap(img, p, coordinate);
}

static void	draw_pathfinding(t_data *img, t_mlx *p, t_map *map, t_map_2d *m2d)
{
	int				i;
	t_path_return	*co;

	co = get_path_finding_input(map->map, map->map_len, map->map_lenght);
	i = 0;
	while (co && i != co->moves)
	{
		p->color = 0x333333;
		if (i != co->moves - 1)
		{
			draw_big_line(img, p,
				(co->x[i] - m2d->y_tile_size) * TILE_SIZE + 10 + map->def_y,
				(co->y[i] - m2d->x_tile_size) * TILE_SIZE + 10 + map->def_x,
				(co->x[i + 1] - m2d->y_tile_size) * TILE_SIZE + 10 + map->def_y,
				(co->y[i + 1] - m2d->x_tile_size)
				* TILE_SIZE + 10 + map->def_x, 8);
		}
		if (i == 0)
			draw_current_position(img, p, map, m2d, co);
		i++;
	}
	free(co->x);
	free(co->y);
	free(co);
}

static void	update_position_pathfinding(t_map *map, t_mlx *p, t_map_2d *m2d)
{
	int	i;
	int	j;

	i = 0;
	if (map->map[(int)m2d->x_tile_size][(int)m2d->y_tile_size] == '0')
	{
		while (i != map->map_lenght)
		{
			j = 0;
			while (j != map->map_len)
			{
				if (map->map[i][j] == 'W' || map->map[i][j] == 'E'
					|| map->map[i][j] == 'S' || map->map[i][j] == 'N')
					map->map[i][j] = '0';
				j++;
			}
			i++;
		}
		map->map[(int)(m2d->x_tile_size)][(int)(m2d->y_tile_size)] = 'N';
	}
	p->color = 0x0FFFFF0;
}

void	draw_map_2d(t_map *map, t_data *img, t_mlx *p, t_player *player)
{
	t_map_2d		m2d;

	m2d.x_tile_size = player->x / TILE_SIZE;
	m2d.y_tile_size = player->y / TILE_SIZE;
	map->def_y = MINIMAP_X;
	map->def_x = MINIMAP_Y;
	draw_map_circle(img);
	draw_minimap(img, map, p, &m2d);
	draw_pathfinding(img, p, map, &m2d);
	update_position_pathfinding(map, p, &m2d);
	draw_circle(img, p, (map->def_x), (map->def_y), 5);
	draw_line_minimap(img, p, (map->def_y), (map->def_x),
		(map->def_y) + player->delta_y * 5, (map->def_x) + player->delta_x * 5);
}
