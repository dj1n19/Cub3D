/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:56:58 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/25 14:06:07 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	point_in_circle(double x, double y, double r)
{
	double	distance;

	distance = sqrt(pow(x - MINIMAP_X, 2) + pow(y - MINIMAP_Y, 2));
	if (distance <= r)
		return (1);
	else
		return (0);
}

void	set_color(t_minimap *mm, int x, int y)
{
	if (mm->map->map[y][x] == '1')
		mm->p->color = 0x4e2823;
	else if (mm->map->map[y][x] == '0')
		mm->p->color = 0x397a41;
	else if (mm->map->map[y][x] == 'O')
		mm->p->color = 0xb96f2c;
	else if (mm->map->map[y][x] == 'E' || mm->map->map[y][x] == 'N'
		|| mm->map->map[y][x] == 'S' || mm->map->map[y][x] == 'W')
		mm->p->color = 0x629cc5;
}

void	update_position_pathfinding(t_map *map, t_mlx *p, t_minimap *mm)
{
	int	i;
	int	j;

	i = 0;
	if (map->map[(int)mm->x_tile_size][(int)mm->y_tile_size] == '0')
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
		map->map[(int)(mm->x_tile_size)][(int)(mm->y_tile_size)] = 'N';
	}
	p->color = 0x0FFFFF0;
}

static void	draw_line_minimap_init(t_minimap_data *md)
{
	md->dx = abs(md->x1 - md->x0);
	md->dy = -abs(md->y1 - md->y0);
	if (md->x0 < md->x1)
		md->sx = 1;
	else
		md->sx = -1;
	if (md->y0 < md->y1)
		md->sy = 1;
	else
		md->sy = -1;
	md->err = md->dx + md->dy;
}

void	draw_line_minimap(t_data *img, t_mlx *p, t_minimap_data md)
{
	draw_line_minimap_init(&md);
	while (1)
	{
		if (md.x0 >= 0 && md.x0 < SCREEN_WIDTH && md.y0 >= 0
			&& md.y0 < SCREEN_HEIGHT && point_in_circle(md.x0, md.y0, 150))
			my_mlx_pixel_put(img, md.x0, md.y0, p->color);
		if (md.x0 == md.x1 && md.y0 == md.y1)
			break ;
		md.e2 = 2 * md.err;
		if (md.e2 >= md.dy)
		{
			md.err += md.dy;
			md.x0 += md.sx;
		}
		if (md.e2 <= md.dx)
		{
			md.err += md.dx;
			md.y0 += md.sy;
		}
	}
}
