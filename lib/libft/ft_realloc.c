/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:22:12 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/16 15:53:29 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	free_array(char *p)
{
	if (p)
	{
		ft_malloc(0, p, FREE);
	}
}

void	*ft_realloc(char *p, size_t size)
{
	char	*new_alloc;
	size_t	i;

	i = 0;
	if (!p)
		return (NULL);
	new_alloc = malloc(size);
	if (!new_alloc)
		return (NULL);
	while (p[i])
	{
		new_alloc[i] = p[i];
		i++;
	}
	free_array(p);
	return (new_alloc);
}
