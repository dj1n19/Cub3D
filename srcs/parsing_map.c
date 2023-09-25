/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:49:47 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/25 14:34:36 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//Fichier contenant le découpage d'une fonction servant 
//a parser le contenu du fichier .cub et le mettre
//dans la structure

static void	ft_put_file_table5(t_verif *verif, t_map *map_struct, int fd)
{
	if (verif->instruct != 6)
		ft_error(BAD_FILE);
	verif->line = get_next_line(fd);
	verif->line_pos++;
	while (ft_strncmp(verif->line, "\n", 1) == 0)
	{
		ft_malloc(0, verif->line, FREE);
		verif->line = get_next_line(fd);
		verif->line_pos++;
	}
	while (verif->line != NULL)
	{
		ft_malloc(0, verif->line, FREE);
		verif->map_pos++;
		verif->line = get_next_line(fd);
	}
	ft_malloc(0, verif->line, FREE);
	map_struct->map_lenght = verif->map_pos;
}

static void	ft_put_file_table4(t_verif *verif, t_map *map_struct)
{
	if (ft_strncmp(verif->line, "C ", 2) == 0)
	{
		verif->indic = 0;
		verif->tmp = ft_split(ft_strrchr(verif->line, ' ') + 1, ',');
		while (verif->tmp[verif->indic] != NULL)
		{
			map_struct->ceiling_color |= (ft_atoi(verif->tmp[verif->indic])
					<< (verif->indic * 8));
			verif->indic++;
		}
		free_tab(verif->tmp);
		verif->instruct++;
	}
}

static void	ft_put_file_table3(t_verif *verif, t_map *map_struct)
{
	if (ft_strncmp(verif->line, "EA ", 3) == 0)
	{
		map_struct->east_texture = ft_substr(verif->line, 3,
				ft_strlen(verif->line) - 4);
		verif->instruct++;
	}
	else if (ft_strncmp(verif->line, "F ", 2) == 0)
	{
		verif->indic = 0;
		verif->tmp = ft_split(ft_strrchr(verif->line, ' ') + 1, ',');
		while (verif->tmp[verif->indic] != NULL)
		{
			map_struct->floor_color |= (ft_atoi(verif->tmp[verif->indic])
					<< (verif->indic * 8));
			verif->indic++;
		}
		free_tab(verif->tmp);
		verif->instruct++;
	}
}

static void	ft_put_file_table2(t_verif *verif, t_map *map_struct)
{
	if (ft_strncmp(verif->line, "NO ", 3) == 0)
	{
		map_struct->north_texture = ft_substr(verif->line, 3,
				ft_strlen(verif->line) - 4);
		verif->instruct++;
	}
	else if (ft_strncmp(verif->line, "SO ", 3) == 0)
	{
		map_struct->south_texture = ft_substr(verif->line, 3,
				ft_strlen(verif->line) - 4);
		verif->instruct++;
	}
	else if (ft_strncmp(verif->line, "WE ", 3) == 0)
	{
		map_struct->west_texture = ft_substr(verif->line, 3,
				ft_strlen(verif->line) - 4);
		verif->instruct++;
	}
}

int	ft_put_file_table(int fd, t_map *map_struct)
{
	t_verif	verif;

	verif.indic = 0;
	verif.instruct = 0;
	verif.line_pos = 0;
	verif.map_pos = 0;
	map_struct->floor_color = 0;
	map_struct->ceiling_color = 0;
	while (verif.instruct != 6)
	{
		verif.line = get_next_line(fd);
		verif.line_pos++;
		if (verif.line == NULL)
			break ;
		ft_put_file_table2(&verif, map_struct);
		ft_put_file_table3(&verif, map_struct);
		ft_put_file_table4(&verif, map_struct);
	}
	ft_put_file_table5(&verif, map_struct, fd);
	return (verif.line_pos);
}
