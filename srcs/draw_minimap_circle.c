/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_circle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:01:26 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/25 14:17:29 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_circle(t_minimap *mm, int x0, int y0, int radius)
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
				my_mlx_pixel_put(mm->img, x0 + x, y0 + y, mm->p->color);
			x++;
		}
		y++;
	}
}

void	draw_map_circle(t_data *img)
{
	int	fill_minimap_x;
	int	fill_minimap_y;

	fill_minimap_y = 0;
	while (fill_minimap_y <= 350)
	{
		fill_minimap_x = 0;
		while (fill_minimap_x <= 350)
		{
			if (point_in_circle(fill_minimap_x, fill_minimap_y, 150))
				my_mlx_pixel_put(img, fill_minimap_x, fill_minimap_y, 0x4e2823);
			else if (point_in_circle(fill_minimap_x, fill_minimap_y, 160))
				my_mlx_pixel_put(img, fill_minimap_x, fill_minimap_y, 0x182029);
			fill_minimap_x++;
		}
		fill_minimap_y++;
	}
}
