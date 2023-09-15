/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:12:51 by bgenie            #+#    #+#             */
/*   Updated: 2023/04/27 13:08:15 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new_str;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new_str = ft_malloc(1, NULL, MALLOC);
		*new_str = 0;
		return (new_str);
	}
	s += start;
	if (ft_strlen(s) > len)
		new_str = ft_malloc(len + 1, NULL, MALLOC);
	else
		new_str = ft_malloc(ft_strlen(s) + 1, NULL, MALLOC);
	while (*s && len--)
		new_str[i++] = *s++;
	new_str[i] = 0;
	return (new_str);
}
