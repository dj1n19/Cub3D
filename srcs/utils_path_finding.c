/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path_finding.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:05:19 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/11 15:30:13 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pathfinding.h"

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
		free(e->next);
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
	coord = malloc(1 * sizeof(t_path_return));
	while (copy != NULL )
	{
		nb_co++;
		copy = copy->next;
	}
	coord->x = malloc(nb_co * sizeof(int));
	coord->y = malloc(nb_co * sizeof(int));
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

	dest = malloc(num_strings * sizeof(char *));
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
