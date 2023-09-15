/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:48:58 by bgenie            #+#    #+#             */
/*   Updated: 2023/04/28 14:15:43 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c)
			{
				if (!*s)
					return (count);
				s++;
			}
		}
		s++;
	}
	return (count);
}

static char	*ft_word_extract(const char *s, char c)
{
	char		*word;
	const char	*start;
	int			i;

	start = s;
	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	word = ft_substr(start, 0, i);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strings_array;
	char	**sa_start;

	if (!s)
		return (NULL);
	strings_array = ft_malloc(sizeof(char *) * (ft_count_word(s, c) + 1),
			NULL, MALLOC);
	sa_start = strings_array;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		*strings_array = ft_word_extract(s, c);
		s += ft_strlen(*strings_array++);
	}
	*strings_array = NULL;
	return (sa_start);
}
