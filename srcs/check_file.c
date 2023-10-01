/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:16:18 by mebourge          #+#    #+#             */
/*   Updated: 2023/10/01 13:43:24 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_verif_map_size(t_map *map)
{
	if (map->map_len > 200 || map->map_lenght > 200)
		ft_error("Bad map_size > 200");
}

void	ft_verif_player_pos(char is_pos, t_map *map)
{
	if (is_pos == 'N')
		map->start_angle = M_PI;
	if (is_pos == 'S')
		map->start_angle = 0;
	if (is_pos == 'E')
		map->start_angle = M_PI_2;
	if (is_pos == 'W')
		map->start_angle = 3 * M_PI_2;
}

/*
*	fonction d'allocation du tableau de string de la map
*/
static char	**ft_allocate_table(int fd, t_map *map_struct,
	int line_pos, char **argv)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map_struct->map = ft_malloc((map_struct->map_lenght + 1) * sizeof(char *),
			NULL, MALLOC);
	while (i != line_pos - 1)
	{
		line = get_next_line(fd);
		ft_malloc(0, line, FREE);
		i++;
	}
	i = 0;
	map_struct->map[i] = line;
	while (i != map_struct->map_lenght + 1)
	{
		line = get_next_line(fd);
		map_struct->map[i] = line;
		i++;
	}
	return (map_struct->map);
}

/*
*	fonction pour lancer la vérification de la map
*/
t_map	check_map(int fd, char **argv)
{
	t_map	map;

	map.map = ft_allocate_table(fd, &map,
			ft_put_file_table(fd, &map), argv);
	ft_verif_char_map(&map);
	return (map);
}
