/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_shape_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:04:13 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/26 23:50:50 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

//Le fichier entier est une découpe d'une fonction destinée 
//a vérifier que la map soit bien entourée de mur

static int	ft_verif_map_shape3(t_map *map, int i, int j)
{
	if (map->map[i][j] != '1' && map->map[i][j] != ' ')
		return (0);
	if (map->map[i][j] == ' ' && i != map->map_lenght - 1
		&& map->map[i + 1][j] != '1' && map->map[i + 1][j] != ' ')
		return (0);
	return (1);
}

static int	ft_verif_map_shape2(t_map *map, int i, int j)
{
	if (map->map[i][j] == ' ')
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
	}
	if (map->map[i][j] == '0')
	{
		if (ft_strlen(map->map[i - 1]) < ft_strlen(map->map[i]) && j
			> (int)ft_strlen(map->map[i - 1]) - 1)
			return (0);
		if (ft_strlen(map->map[i + 1]) < ft_strlen(map->map[i]) && j
			> (int)ft_strlen(map->map[i + 1]) - 1)
			return (0);
	}
	return (1);
}

static int	ft_verif_map_shape4(t_map *map, t_verif *verif)
{
	if (map->map[verif->i][ft_strlen(map->map[verif->i]) - 1] != '1'
		&& map->map[verif->i][ft_strlen(map->map[verif->i]) - 1] != ' ')
		return (0);
	while (map->map[verif->i][verif->j])
	{
		if (ft_verif_map_shape2(map, verif->i, verif->j) == 0)
			return (0);
		verif->j++;
	}
	return (1);
}

int	ft_verif_map_shape(t_map *map)
{
	t_verif	verif;

	verif.i = 0;
	while (verif.i != map->map_lenght)
	{
		verif.j = 0;
		if (verif.i == 0 || verif.i == map->map_lenght)
		{
			while (map->map[verif.i][verif.j])
			{
				if (ft_verif_map_shape3(map, verif.i, verif.j) == 0)
					return (0);
				verif.j++;
			}
		}
		else
		{
			if (ft_verif_map_shape4(map, &verif) == 0)
				return (0);
		}
		verif.i++;
	}
	return (1);
}
