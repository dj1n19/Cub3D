/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:10:34 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/16 15:41:14 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//fonction de free pour les tableau de char

void	free_tab(char **tmp)
{
	int	i;

	i = 0;
	if (!tmp)
		return ;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

int	ft_find_my_str(char *s, int i)
{
	int	j;

	j = 0;
	while (j != i)
	{
		if (s[j] && s[j + 1] && s[j] == '.' && s[j + 1] == '/')
			return (1);
		j++;
	}
	return (0);
}
