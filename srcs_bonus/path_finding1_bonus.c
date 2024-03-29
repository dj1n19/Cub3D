/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:40:03 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/26 23:49:51 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static t_path_return	*get_path_finding_input2(char **map_path,
	t_map_verif *map, int rows, int cols)
{
	int				i;
	t_path_return	*coord;

	map->map_x = rows;
	map->map_y = cols;
	map->map_mapleng = cols;
	map->lower_cost = 0;
	map->x = 0;
	map->y = 0;
	map->dist = 0;
	coord = ft_path_finding(map, map_path);
	i = 0;
	while (i != map->map_mapleng && map->map_dist[i])
		ft_malloc(0, map->map_dist[i++], FREE);
	ft_malloc(0, map->map_dist, FREE);
	ft_malloc(0, map, FREE);
	i = 0;
	while (i != cols)
	{
		ft_malloc(0, map_path[i], FREE);
		i++;
	}
	ft_malloc(0, map_path, FREE);
	return (coord);
}

t_path_return	*get_path_finding_input(char **map_map, int rows, int cols)
{
	t_map_verif	*map;
	char		**map_path;
	int			i;
	int			j;

	i = 0;
	map_path = copy_strings(map_map, cols);
	map = ft_malloc(1 * sizeof(t_map_verif), NULL, MALLOC);
	while (i != cols)
	{
		j = 0;
		while (j != rows)
		{
			if (map_path[i][j] == 'W' || map_path[i][j] == 'E'
				|| map_path[i][j] == 'S' || map_path[i][j] == 'N')
				map_path[i][j] = 'P';
			j++;
		}
		i++;
	}
	return (get_path_finding_input2(map_path, map, rows, cols));
}
