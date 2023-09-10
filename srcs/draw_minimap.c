/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:32:03 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/10 16:20:29 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minimap.h"

static int point_in_circle(double x, double y, double cx, double cy, double r)
{
    double distance = sqrt(pow(x - cx, 2) + pow(y - cy, 2));
    if (distance <= r)
	{
        return 1; // Le point est dans le cercle
    }
	else
	{
        return 0; // Le point est en dehors du cercle
    }
}

static void	draw_line_minimap(t_s *s, int x0, int y0, int x1, int y1)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
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
		if (x0 >= 0 && x0 < SCREEN_WIDTH && y0 >= 0 && y0 < SCREEN_HEIGHT && point_in_circle(x0, y0, MINIMAP_X, MINIMAP_Y, 150))
			my_mlx_pixel_put(s->img, x0, y0, s->p->color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 *err;
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

void	draw_map_2d(t_s *s)
{
	int	x;
	int	y;
	int i;
	int fill_minimap_x;
	int fill_minimap_y;
	t_path_return *co;
	float x_tile_size;
	float y_tile_size;

	x = 0;
	y = 0;
	x_tile_size = s->player->x / TILE_SIZE;
	y_tile_size = s->player->y / TILE_SIZE;
	s->map->def_y = MINIMAP_X;
	s->map->def_x = MINIMAP_Y;
	//BONUS fonction d'appel du path finding

	fill_minimap_x = 0;
	while (fill_minimap_x <= 350)
	{
		fill_minimap_y = 0;
		while (fill_minimap_y <= 350)
		{
			if (point_in_circle(fill_minimap_x, fill_minimap_y, MINIMAP_X, MINIMAP_Y, 150))
				my_mlx_pixel_put(s->img, fill_minimap_x, fill_minimap_y, 0x4e2823);
			else if (point_in_circle(fill_minimap_x, fill_minimap_y, MINIMAP_X, MINIMAP_Y, 160))
				my_mlx_pixel_put(s->img, fill_minimap_x, fill_minimap_y, 0x182029);
			fill_minimap_y++;
		}
		fill_minimap_x++;
	}
	co = get_path_finding_input(s->map->map, s->map->map_len, s->map->map_lenght);
	while (y < s->map->map_lenght)
	{
		x = 0;
		while (x < s->map->map_len)
		{
			if (s->map->map[y][x] == '1')
			{
				s->p->color = 0x4e2823;
			}
			else if (s->map->map[y][x] == '0')
			{
				s->p->color = 0x397a41;
			}
			//BONUS colorier la sortie en vert
			else if (s->map->map[y][x] == 'O')
			{
				s->p->color = 0xb96f2c;
			}
			else if (s->map->map[y][x] == 'E' || s->map->map[y][x] == 'N' || s->map->map[y][x] == 'S' || s->map->map[y][x] == 'W')
			{
				s->p->color = 0x629cc5;
			}
			draw_square_minimap(s, (y - x_tile_size) * TILE_SIZE + s->map->def_x, (x - y_tile_size)* TILE_SIZE + s->map->def_y, TILE_SIZE, TILE_SIZE);
			x++;
		}
		y++;
	}
	i = 0;
	//BONUS d'affichage du path_finding sur la map
	while(co && i != co->moves)
	{
		//BONUS affichage du joueur en bleu
		s->p->color = 0x333333;
		if (i != co->moves - 1)
		{
			draw_big_line(s, (co->x[i] - y_tile_size)* TILE_SIZE + 10 + s->map->def_y , (co->y[i] - x_tile_size) * TILE_SIZE + 10 + s->map->def_x, (co->x[i + 1] - y_tile_size) * TILE_SIZE + 10 + s->map->def_y, (co->y[i + 1] - x_tile_size) * TILE_SIZE + 10 + s->map->def_x, 8);
		}
		if (i == 0)
		{
			s->p->color = 0xaa8085;
			draw_square_minimap(s, (co->y[i] - x_tile_size) * TILE_SIZE + s->map->def_x, (co->x[i] - y_tile_size) * TILE_SIZE + s->map->def_y, TILE_SIZE, TILE_SIZE);
		}
		i++;
	}
	free(co->x);
	free(co->y);
	free(co);
	int j;

	i = 0;
	if (s->map->map[(int)x_tile_size][(int)y_tile_size] == '0')
	{
		while (i != s->map->map_lenght)
		{
			j = 0;
			while (j != s->map->map_len)
			{
				if (s->map->map[i][j] == 'W' || s->map->map[i][j] == 'E' || s->map->map[i][j] == 'S' || s->map->map[i][j] == 'N')
					s->map->map[i][j] = '0';
				j++;
			}
			i++;
		}
		s->map->map[(int)(x_tile_size)][(int)(y_tile_size)] = 'N';
	}
	s->p->color = 0x0FFFFF0;
	draw_circle(s, (s->map->def_x), (s->map->def_y), 5);
	draw_line_minimap(s, (s->map->def_y), (s->map->def_x), (s->map->def_y) + s->player->delta_y * 5, (s->map->def_x) + s->player->delta_x * 5);
}
