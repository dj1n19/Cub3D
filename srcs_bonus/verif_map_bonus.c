/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 06:46:57 by merlinbourg       #+#    #+#             */
/*   Updated: 2023/10/16 14:10:34 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

//fonction de vérification de la présence du joueur sur la carte

static int	ft_is_player(char **map, t_map *s)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'E'
			|| map[i][j] == 'S' || map[i][j] == 'N')
			{
				s->def_x = i * 20 + 10;
				s->def_y = j * 20 + 10;
				s->def_angle = map[i][j];
				player++;
			}
			j++;
		}
		i++;
	}
	return (player);
}

//fonction pour retirer les espaces en fin de ligne

static char	**ft_without_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]) - 1;
		while (map[i][j] == ' ')
		{
			map[i][j] = '\0';
			j--;
		}
		i++;
	}
	return (map);
}

//fonction pour retirer les newline en fin de ligne

static char	**ft_without_newline(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][j - 1] = '\0';
		i++;
	}
	return (map);
}

/*
*	verifie que la map n'est composee que de characteres autorises
*/

static void	ft_verif_forbidden_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			ft_verif_player_pos(map->map[i][j], map);
			if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j]
			!= ' ' && map->map[i][j] != 'W' && map->map[i][j]
			!= 'E' && map->map[i][j] != 'S' && map->map[i][j] != 'N'
			&& map->map[i][j] != 'O')
				ft_error(CHAR_ERROR);
			j++;
		}
		i++;
	}
}

/*
*	fonction pour vérifier que les carracteres présents sur la map soient les bons
*/
void	ft_verif_char_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->map = ft_without_newline(map->map);
	map->map = ft_without_spaces(map->map);
	ft_verif_forbidden_char(map);
	if (ft_is_player(map->map, map) != 1)
		ft_error(BAD_PLAYER_ERROR);
	if (ft_is_exit(map->map) > 1)
		ft_error(BAD_EXIT_ERROR);
	if (!ft_verif_map_shape(map))
		ft_error(MAP_LAYOUT_ERROR);
	space_to_one(map);
	map->map_len = ft_strlen(map->map[0]);
}
