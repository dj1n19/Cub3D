/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_pathfinding_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:03:47 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/26 23:49:09 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static void	draw_big_line(t_data *img, t_mlx *p, t_minimap_data *md)
{
	int	above;
	int	i;

	above = md->thick / 2;
	i = 0;
	while (i != above)
	{
		draw_line_minimap(img, p, *md);
		md->x0 -= i;
		md->y0 -= i;
		md->x1 -= i;
		md->y1 -= i;
		draw_line_minimap(img, p, *md);
		i++;
		md->x0 += i;
		md->y0 += i;
		md->x1 += i;
		md->y1 += i;
	}
}

static void	draw_current_position(t_minimap *mm, t_path_return *co)
{
	t_minimap_data	md;

	md.coordinate_y = (co->x[0] - mm->y_tile_size)
		* TILE_SIZE + mm->map->def_y;
	md.coordinate_x = (co->y[0] - mm->x_tile_size)
		* TILE_SIZE + mm->map->def_x;
	md.size_x = TILE_SIZE;
	md.size_y = TILE_SIZE;
	mm->p->color = 0xaa8085;
	draw_square_minimap(mm->img, mm->p, &md);
}

void	draw_pathfinding(t_data *img, t_mlx *p, t_map *m, t_minimap *mm)
{
	int				i;
	t_path_return	*co;
	t_minimap_data	d;

	d.thick = 8;
	co = get_path_finding_input(m->map, m->map_len, m->map_lenght);
	i = 0;
	while (co && i != co->moves)
	{
		p->color = 0x333333;
		if (i != co->moves - 1)
		{
			d.x0 = (co->x[i] - mm->y_tile_size) * TILE_SIZE + 10 + m->def_x;
			d.y0 = (co->y[i] - mm->x_tile_size) * TILE_SIZE + 10 + m->def_x;
			d.x1 = (co->x[i + 1] - mm->y_tile_size) * TILE_SIZE + 10 + m->def_y;
			d.y1 = (co->y[i + 1] - mm->x_tile_size) * TILE_SIZE + 10 + m->def_x;
			draw_big_line(img, p, &d);
		}
		if (i == 0)
			draw_current_position(mm, co);
		i++;
	}
	ft_malloc(0, co->x, FREE);
	ft_malloc(0, co->y, FREE);
	ft_malloc(0, co, FREE);
}
