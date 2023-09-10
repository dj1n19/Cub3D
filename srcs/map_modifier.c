/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:26:19 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/10 18:01:14 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

/*
* Ce fichier sert a parser la map en changant
* les espaces contenus dans la map en 1
*/

static int	get_longest_line_length(t_map *map)
{
	int	i;
	int	j;
	int	longest_len;

	longest_len = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (j > longest_len)
			longest_len = j;
		i++;
	}
}

void	space_to_one(t_map *map)
{
	int	i;
	int	j;
	int	long_line_len;

	long_line_len = get_longest_line_length(map);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == ' ')
				map->map[i][j] = '1';
			j++;
		}
		map->map[i] = ft_realloc(map->map[i], long_line_len + 1);
		while (j < long_line_len)
		{
			map->map[i][j] = '1';
			j++;
		}
		map->map[i][j] = 0;
		i++;
	}
}
