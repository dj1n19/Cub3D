/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:16 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/26 23:49:56 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

t_map_corr	*ft_path_red3(t_map_verif *map, t_map_corr *chain)
{
	t_map_corr	*e;
	t_map_corr	*co;

	map->lower_cost = 2147483647;
	co = ft_malloc(sizeof(t_map_corr), NULL, MALLOC);
	if (!co)
		return (NULL);
	co->next = NULL;
	e = get_last(chain);
	map->x = e->x;
	map->y = e->y;
	return (co);
}

t_map_corr	*ft_path_finding_map_update(t_map_verif *map, t_map_corr *chain)
{
	t_map_corr	*co;

	while (map->map_compl[map->y][map->x] != 'O')
	{
		co = ft_path_red3(map, chain);
		if (ft_path_finding_map_search_neighbour(map) == 0)
		{
			return (NULL);
		}
		ft_path_red(map, chain, co);
		ft_path_red2(map, chain, co);
		if (map->lower_cost == 0)
			break ;
		else if (map->lower_cost == 2147483647)
		{
			chain = ft_path_finding_map_suppup(map, chain);
		}
		else
			chain = lstadd_back(chain, co);
	}
	ft_malloc(0, co, FREE);
	return (chain);
}

t_path_return	*ft_path_finding2(t_map_verif *map, char **map_path,
	t_map_corr co)
{
	t_map_corr		*chain;
	t_path_return	*coord;

	map->map_compl = copy_strings(map_path, map->map_y);
	ft_path_finding_map_locate(map, 'O');
	map->out_x = map->x;
	map->out_y = map->y;
	map->x = 0;
	map->y = 0;
	ft_path_finding_map_manathan(map);
	ft_path_finding_map_put_tab(map);
	ft_path_finding_map_locate(map, 'P');
	co.x = map->x;
	co.y = map->y;
	chain = ft_path_finding_map_update(map, &co);
	coord = list_to_arrays(chain);
	return (coord);
}

t_path_return	*ft_path_finding(t_map_verif *map, char **map_path)
{
	t_map_corr		co;
	t_path_return	*coord;

	co.next = NULL;
	coord = ft_path_finding2(map, map_path, co);
	return (coord);
}
