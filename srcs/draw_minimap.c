/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:32:03 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/14 17:07:00 by bgenie           ###   ########.fr       */
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

static void	draw_line_minimap(t_data *img, t_mlx *p, int x0, int y0, int x1, int y1)
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
			my_mlx_pixel_put(img, x0, y0, p->color);
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

static void draw_square_minimap(t_data *img, t_mlx *p, int x, int y, int size_x, int size_y)
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
                my_mlx_pixel_put(img, i, j, p->color);
            }
            j++;
        }
        i++;
    }
}

void	draw_map_2d(t_map *map, t_data *img, t_mlx *p, t_player *player)
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
	map->def_y = MINIMAP_X;
	map->def_x = MINIMAP_Y;
	//BONUS fonction d'appel du path finding

	fill_minimap_x = 0;
	while (fill_minimap_x <= 350)
	{
		fill_minimap_y = 0;
		while (fill_minimap_y <= 350)
		{
			if (point_in_circle(fill_minimap_x, fill_minimap_y, MINIMAP_X, MINIMAP_Y, 150))
				my_mlx_pixel_put(img, fill_minimap_x, fill_minimap_y, 0x4e2823);
			else if (point_in_circle(fill_minimap_x, fill_minimap_y, MINIMAP_X, MINIMAP_Y, 160))
				my_mlx_pixel_put(img, fill_minimap_x, fill_minimap_y, 0x182029);
			fill_minimap_y++;
		}
		fill_minimap_x++;
	}
	co = get_path_finding_input(map->map, map->map_len, map->map_lenght);
	while (y < map->map_lenght)
	{
		x = 0;
		while (x < map->map_len)
		{
			if (map->map[y][x] == '1')
			{
				p->color = 0x4e2823;
			}
			else if (map->map[y][x] == '0')
			{
				p->color = 0x397a41;
			}
			//BONUS colorier la sortie en vert
			else if (map->map[y][x] == 'O')
			{
				p->color = 0xb96f2c;
			}
			else if (map->map[y][x] == 'E' || map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y][x] == 'W')
			{
				p->color = 0x629cc5;
			}
			draw_square_minimap(img, p, (y - x_tile_size) * TILE_SIZE + map->def_x, (x - y_tile_size)* TILE_SIZE + map->def_y, TILE_SIZE, TILE_SIZE);
			x++;
		}
		y++;
	}
	i = 0;
	//BONUS d'affichage du path_finding sur la map
	while(co && i != co->moves)
	{
		//BONUS affichage du joueur en bleu
		p->color = 0x333333;
		if (i != co->moves - 1)
		{
			draw_big_line(s, (co->x[i] - y_tile_size)* TILE_SIZE + 10 + map->def_y , (co->y[i] - x_tile_size) * TILE_SIZE + 10 + map->def_x, (co->x[i + 1] - y_tile_size) * TILE_SIZE + 10 + map->def_y, (co->y[i + 1] - x_tile_size) * TILE_SIZE + 10 + map->def_x, 8);
		}
		if (i == 0)
		{
			s->p->color = 0xaa8085;
			draw_square_minimap(img, p, (co->y[i] - x_tile_size) * TILE_SIZE + map->def_x, (co->x[i] - y_tile_size) * TILE_SIZE + map->def_y, TILE_SIZE, TILE_SIZE);
		}
		i++;
	}
	free(co->x);
	free(co->y);
	free(co);
	int j;

	i = 0;
	if (map->map[(int)x_tile_size][(int)y_tile_size] == '0')
	{
		while (i != map->map_lenght)
		{
			j = 0;
			while (j != map->map_len)
			{
				if (map->map[i][j] == 'W' || map->map[i][j] == 'E' || map->map[i][j] == 'S' || map->map[i][j] == 'N')
					map->map[i][j] = '0';
				j++;
			}
			i++;
		}
		map->map[(int)(x_tile_size)][(int)(y_tile_size)] = 'N';
	}
	p->color = 0x0FFFFF0;
	draw_circle(s, (map->def_x), (map->def_y), 5);
	draw_line_minimap(img, p, (map->def_y), (map->def_x), (map->def_y) + player->delta_y * 5, (map->def_x) + player->delta_x * 5);
}
