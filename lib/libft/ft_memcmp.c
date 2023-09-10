/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:32:11 by mebourge          #+#    #+#             */
/*   Updated: 2023/07/08 10:35:41 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	int				j;

	i = 0;
	while (i < n)
	{
		j = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (j)
			return (j);
		i++;
	}
	return (0);
}
