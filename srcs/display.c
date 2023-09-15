/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:15:42 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/12 17:05:16 by bgenie           ###   ########.fr       */
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
