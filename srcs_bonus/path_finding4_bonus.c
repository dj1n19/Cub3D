/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding4_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:57:46 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/26 23:50:05 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

static int	ft_path_finding_alredy(int y, int x, t_map_corr *chain)
{
	t_map_corr	*l;

	l = chain;
	if (!chain)
		return (1);
	while (l != NULL)
	{
		if (x == l->x && y == l->y)
			return (1);
		l = l->next;
	}
	return (0);
}

/*
* fonction servant a mettre la cases a 1
* si elle as déja été visitée dans la liste chainée
*/
t_map_corr	*ft_path_finding_map_suppup(t_map_verif *map, t_map_corr *chain)
{
	t_map_corr	*l;

	l = chain;
	if (!chain)
		return (NULL);
	while (l->next->next != NULL)
		l = l->next;
	map->map_compl[map->y][map->x] = '1';
	map->x = l->x;
	map->y = l->y;
	ft_malloc(0, l->next, FREE);
	l->next = NULL;
	return (chain);
}

//fonction de vérification des cases voisines

int	ft_path_finding_map_search_neighbour(t_map_verif *map)
{
	int	i;

	i = 0;
	if (map->map_compl[map->y][map->x + 1] != '1')
		i++;
	if (map->map_compl[map->y][map->x - 1] != '1')
		i++;
	if (map->map_compl[map->y + 1][map->x] != '1')
		i++;
	if (map->map_compl[map->y - 1][map->x] != '1')
		i++;
	return (i);
}

//fonction de déplacement sur les cases voisines

void	ft_path_red(t_map_verif *map, t_map_corr *chain, t_map_corr *co)
{
	if (map->map_compl[map->y][map->x + 1] != '1'
		&& ft_path_finding_alredy(map->y, map->x + 1, chain) == 0
			&& map->map_dist[map->y][map->x + 1] < map->lower_cost)
	{
		map->lower_cost = map->map_dist[map->y][map->x + 1];
		co->x = map->x + 1;
		co->y = map->y;
	}
	if (map->map_compl[map->y][map->x - 1] != '1'
		&& ft_path_finding_alredy(map->y, map->x - 1, chain) == 0
			&& map->map_dist[map->y][map->x - 1] < map->lower_cost)
	{
		map->lower_cost = map->map_dist[map->y][map->x - 1];
		co->x = map->x - 1;
		co->y = map->y;
	}
	if (map->map_compl[map->y + 1][map->x] != '1'
		&& ft_path_finding_alredy(map->y + 1, map->x, chain) == 0
			&& map->map_dist[map->y + 1][map->x] < map->lower_cost)
	{
		map->lower_cost = map->map_dist[map->y + 1][map->x];
		co->x = map->x;
		co->y = map->y + 1;
	}
}

void	ft_path_red2(t_map_verif *map, t_map_corr *chain, t_map_corr *co)
{
	if (map->map_compl[map->y - 1][map->x] != '1'
		&& ft_path_finding_alredy(map->y - 1, map->x, chain) == 0
			&& map->map_dist[map->y - 1][map->x] < map->lower_cost)
	{
		map->lower_cost = map->map_dist[map->y - 1][map->x];
		co->x = map->x;
		co->y = map->y - 1;
	}
}
