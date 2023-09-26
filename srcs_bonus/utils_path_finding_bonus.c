/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path_finding_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:05:19 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/26 23:50:40 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	ft_free_list(t_map_corr *chain)
{
	t_map_corr	*e;
	t_map_corr	*last;

	if (!chain)
		return ;
	while (chain->next != NULL)
	{
		e = chain;
		last = get_last(chain);
		while (e->next != last)
			e = e->next;
		ft_malloc(0, e->next, FREE);
		e->next = NULL;
	}
}

t_path_return	*list_to_arrays(t_map_corr *head)
{
	t_path_return	*coord;
	t_map_corr		*copy;
	int				nb_co;
	int				i;

	copy = head;
	nb_co = 0;
	i = 0;
	coord = ft_malloc(1 * sizeof(t_path_return), NULL, MALLOC);
	while (copy != NULL )
	{
		nb_co++;
		copy = copy->next;
	}
	coord->x = ft_malloc(nb_co * sizeof(int), NULL, MALLOC);
	coord->y = ft_malloc(nb_co * sizeof(int), NULL, MALLOC);
	coord->moves = nb_co;
	copy = head;
	while (copy != NULL)
	{
		coord->x[i] = copy->x;
		coord->y[i++] = copy->y;
		copy = copy->next;
	}
	return (coord);
}

char	**copy_strings(char **src, int num_strings)
{
	char	**dest;
	int		i;

	dest = ft_malloc(num_strings * sizeof(char *), NULL, MALLOC);
	i = 0;
	while (i < num_strings)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	return (dest);
}

void	print_list(t_map_corr *head)
{
	t_map_corr	*current;

	current = head;
	while (current)
	{
		printf("x : %d\n", current->x);
		printf("y : %d\n", current->y);
		printf("\n");
		current = current->next;
	}
	printf("\n");
}
