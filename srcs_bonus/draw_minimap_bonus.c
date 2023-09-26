/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:32:03 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/26 23:48:59 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static void	draw_square_minimap_init(t_minimap_data *md)
{
	md->x = md->coordinate_x;
	md->y = md->coordinate_y;
	if (md->x < 0)
		md->x = 0;
	if (md->y < 0)
		md->y = 0;
	if (md->x + TILE_SIZE >= SCREEN_HEIGHT)
		md->size_x = SCREEN_HEIGHT - md->x - 1;
	if (md->y + TILE_SIZE >= SCREEN_WIDTH)
		md->size_y = SCREEN_WIDTH - md->y - 1;
}

void	draw_square_minimap(t_data *img, t_mlx *p, t_minimap_data *md)
{
	int				i;
	int				j;

	draw_square_minimap_init(md);
	i = md->y;
	while (i <= md->y + md->size_y)
	{
		j = md->x;
		while (j <= md->x + md->size_x)
		{
			if (i >= 0 && i < SCREEN_WIDTH && j >= 0
				&& j < SCREEN_HEIGHT && point_in_circle(j, i, 150))
				my_mlx_pixel_put(img, i, j, p->color);
			j++;
		}
		i++;
	}
}

static void	draw_minimap(t_minimap *mm)
{
	int				x;
	int				y;
	t_minimap_data	md;

	md.size_x = TILE_SIZE;
	md.size_y = TILE_SIZE;
	y = 0;
	while (y < mm->map->map_lenght)
	{
		x = 0;
		while (x < mm->map->map_len)
		{
			md.coordinate_y = (x - mm->y_tile_size)
				* TILE_SIZE + mm->map->def_y;
			md.coordinate_x = (y - mm->x_tile_size)
				* TILE_SIZE + mm->map->def_x;
			set_color(mm, x, y);
			draw_square_minimap(mm->img, mm->p, &md);
			x++;
		}
		y++;
	}
}

void	draw_map_2d(t_map *map, t_data *img, t_mlx *p, t_player *player)
{
	t_minimap		mm;
	t_minimap_data	md;

	mm.map = map;
	mm.img = img;
	mm.p = p;
	mm.player = player;
	mm.x_tile_size = player->x / TILE_SIZE;
	mm.y_tile_size = player->y / TILE_SIZE;
	map->def_y = MINIMAP_X;
	map->def_x = MINIMAP_Y;
	draw_map_circle(img);
	draw_minimap(&mm);
	draw_pathfinding(img, p, map, &mm);
	update_position_pathfinding(map, p, &mm);
	draw_circle(&mm, (map->def_x), (map->def_y), 5);
	md.x0 = map->def_y;
	md.y0 = map->def_x;
	md.x1 = map->def_y + player->delta_y * 5;
	md.y1 = map->def_x + player->delta_x * 5;
	draw_line_minimap(img, p, md);
}
