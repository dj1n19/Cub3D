/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:56:25 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/26 23:50:00 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

t_map_corr	*get_last(t_map_corr *chain)
{
	t_map_corr	*e;

	if (!chain)
		return (NULL);
	e = chain;
	while (e->next)
		e = e->next;
	return (e);
}

t_map_corr	*lstadd_back(t_map_corr *chain, t_map_corr *co)
{
	t_map_corr	*l;

	l = chain;
	if (!chain || !co)
		return (NULL);
	if (!chain)
	{
		chain = co;
		return (chain);
	}
	while (l->next != NULL)
		l = l->next;
	l->next = co;
	return (chain);
}

/*
* fonction servant a appliquer l'algorithme de manathan,
* a trouver le coup le moins cher
*/
void	ft_path_finding_map_manathan(t_map_verif *map)
{
	int	diff1;
	int	diff2;

	if ((map->x - map->out_x) < 0)
		diff1 = -(map->x - map->out_x);
	else
		diff1 = (map->x - map->out_x);
	if ((map->y - map->out_y) < 0)
		diff2 = -(map->y - map->out_y);
	else
		diff2 = (map->y - map->out_y);
	map->dist = diff1 + diff2;
}

void	ft_path_finding_map_put_tab(t_map_verif *map)
{
	int	i;
	int	j;

	i = 0;
	map->map_dist = ft_malloc(map->map_mapleng * sizeof(int *), NULL, MALLOC);
	if (!map->map_dist)
		return ;
	while (i != map->map_mapleng)
	{
		j = 0;
		map->map_dist[i] = ft_malloc(map->map_x * sizeof(int *), NULL, MALLOC);
		if (!map->map_dist[i])
			return ;
		map->x = 0;
		while (j != map->map_x)
		{
			ft_path_finding_map_manathan(map);
			map->map_dist[i][j] = map->dist;
			map->x++;
			j++;
		}
		map->y++;
		i++;
	}
}

//fonction servant a trouver un carractere se trouvant sur la carte

void	ft_path_finding_map_locate(t_map_verif *map, char c)
{
	map->x = 0;
	map->y = 0;
	while (map->map_compl[map->y][map->x] != c)
	{
		if (map->y == map->map_mapleng - 1)
			return ;
		if (map->x == map->map_x)
		{
			map->x = 0;
			map->y++;
		}
		map->x++;
	}
}
