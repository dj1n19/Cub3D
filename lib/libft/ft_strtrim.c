/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:47:18 by bgenie            #+#    #+#             */
/*   Updated: 2023/04/27 13:07:11 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

static const char	*check_char_begin(char const *s1, char const *set)
{
	while (*s1)
	{
		if (ft_is_in_set(*s1, set))
			s1++;
		else
			break ;
	}
	return (s1);
}

static int	check_char_end(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	if (i < 0)
		return (0);
	while (i > 0)
	{
		if (ft_is_in_set(s1[i], set))
			i--;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*new_str;
	int		end_trim_str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	s1 = check_char_begin(s1, set);
	end_trim_str = check_char_end(s1, set);
	new_str = ft_malloc(end_trim_str + 2, NULL, MALLOC);
	while (i <= end_trim_str)
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
