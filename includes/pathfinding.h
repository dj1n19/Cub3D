/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:37:43 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/11 15:42:57 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDING_H
# define PATHFINDFING_H
# include "libft.h"

/*
*	structure de gestion du path_finding
*/
typedef struct s_map_verif
{
	int		error;
	char	*map_path;
	int		map_x;
	int		map_y;
	int		x;
	int		y;
	int		out_x;
	int		out_y;
	int		dist;
	int		map_mapleng;
	int		lower_cost;
	int		**map_dist;
	char	**map_compl;
}	t_map_verif;

/*
*	liste chainée du path_finding
*/
typedef struct s_map_corr
{
	int					x;
	int					y;
	struct s_map_corr	*next;
}	t_map_corr;

/*
*	structure de return du path_finding
*/
typedef struct s_path_return
{
	int moves;
	int *x;
	int *y;
}	 t_path_return;

/*
*	utils_path_finding.c
*/
t_path_return	*list_to_arrays(t_map_corr* head);
char 			**copy_strings(char** src, int numStrings);
void			printList(t_map_corr* head);
void			ft_free_list(t_map_corr *chain);

/*
*	path_finding1.c
*/
t_path_return *get_path_finding_input(char **map_map, int rows, int cols);

/*
*	path_finding3.c
*/
t_map_corr		*get_last(t_map_corr *chain);
t_map_corr		*lstadd_back(t_map_corr *chain, t_map_corr *co);
void			ft_path_finding_map_manathan(t_map_verif *map);
void			ft_path_finding_map_put_tab(t_map_verif *map);
void			ft_path_finding_map_locate(t_map_verif *map, char c);

/*
*	path_finding4.c
*/
t_map_corr		*ft_path_finding_map_suppup(t_map_verif *map, t_map_corr *chain);
int				ft_path_finding_map_search_neighbour(t_map_verif *map);

#endif