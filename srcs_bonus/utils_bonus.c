/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:11:26 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/26 23:50:35 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

char	*concatenate_string_array(char **map, int len)
{
	char	*map_line;
	int		i;

	i = 1;
	map_line = ft_strdup(map[0]);
	while (map[i])
	{
		map_line = ft_strjoin(map_line, map[i]);
		i++;
	}
	map_line[i * len] = '\0';
	return (map_line);
}

long long	get_current_microseconds(void)
{
	struct timespec	current_time;

	return (current_time.tv_sec * 1e6 + current_time.tv_nsec / 1e3);
}

int	is_wall(char **map, float y, float x)
{
	int	int_x;
	int	int_y;

	int_x = (int)floorf(x);
	int_y = (int)floorf(y);
	if (map[int_y][int_x] == '1')
	{
		return (1);
	}
	else
		return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > SCREEN_WIDTH || y > SCREEN_HEIGHT - 1)
	{
		return ;
	}
	dst = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / BITS_PER_BYTE));
	*(unsigned int *)dst = color;
}
