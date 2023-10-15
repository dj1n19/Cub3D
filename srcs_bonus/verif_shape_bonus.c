/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_shape_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:04:13 by mebourge          #+#    #+#             */
/*   Updated: 2023/10/15 16:01:39 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static int	ft_verif_neighbours(t_map *map, int i, int j)
{
	if (j != 0 && map->map[i][j - 1] != '1' && map->map[i][j - 1] != ' ')
		return (0);
	if (map->map[i][j + 1] != '1' && map->map[i][j + 1] != ' ')
		return (0);
	if (i != map->map_lenght - 1 && map->map[i + 1][j] != '1'
		&& map->map[i + 1][j] != ' ')
		return (0);
	if (i != 0 && map->map[i - 1][j] != '1' && map->map[i - 1][j] != ' ')
		return (0);
	return (1);
}

static int	ft_verif_space(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_lenght)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
			{
				if (!ft_verif_neighbours(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_verif_map_border(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[0][++i])
	{
		if (map->map[0][i] != '1' && map->map[0][i] != ' ')
			return (0);
	}
	i = 0;
	while (++i < map->map_lenght - 1)
	{
		if ((map->map[i][0] != '1' && map->map[i][0] != ' ')
			|| (map->map[i][ft_strlen(map->map[i]) - 1] != '1'
			&& map->map[i][ft_strlen(map->map[i]) - 1] != ' '))
			return (0);
	}
	i = -1;
	while (map->map[map->map_lenght - 1][++i])
	{
		if (map->map[map->map_lenght - 1][i] != '1'
			&& map->map[map->map_lenght - 1][i] != ' ')
			return (0);
	}
	return (1);
}

int	ft_verif_map_shape(t_map *map)
{
	if (!ft_verif_map_border(map))
		return (0);
	if (!ft_verif_space(map))
		return (0);
	return (1);
}
