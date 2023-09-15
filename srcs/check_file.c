/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:16:18 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/12 16:26:53 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"

//fonction d'allocation du tableau de string de la map

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
		free(line);
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

//fonction pour lancer la vérification de la map

t_map	check_map(int fd, char **argv)
{
	t_map	map;

	map.map = ft_allocate_table(fd, &map,
			ft_put_file_table(fd, &map), argv);
	ft_verif_char_map(&map);
	return (map);
}
