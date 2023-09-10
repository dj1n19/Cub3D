/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:47:29 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/10 18:32:05 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> // TO_REMOVE
# include "libft.h"
# include "get_next_line.h"
# include "error.h"

/*
*	Structure de gestion des infos contenue dans le fichier
*/
typedef struct s_map
{
	int		def_x;
	int		def_y;
	char	def_angle;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		floor_color;
	int		Ceiling_color;
	int		map_lenght;
	int		map_len;
	int		map_max;
	char	*map_line;
	char	**map;
}	t_map;

/*
*	Structure de verification de la map
*/
typedef struct s_verif
{
	char	**map;
	char	*line;
	char	**tmp;
	int		instruct;
	int		line_pos;
	int		map_pos;
	int		indic;
	int	i;
	int	j;
}	t_verif;

/*
*	check_file.c
*/
t_map	check_map(int fd, char **argv);

/*
*	map_modifier.c
*/
void	space_to_one(t_map *map);

/*
*	parsing_map.c
*/
int	ft_put_file_table(int fd, t_map *map_struct);

/*
*	parsing_map_utils.c
*/
void	free_tab(char **tmp);
int		ft_find_my_str(char *s, int i);

/*
*
*/
void	ft_verif_char_map(t_map *map);

/*
*	verif_shape.c
*/
int		ft_verif_map_shape(t_map *map);

#endif