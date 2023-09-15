/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:44:30 by bgenie            #+#    #+#             */
/*   Updated: 2023/04/29 18:08:27 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static const char	*ft_getsign(const char *s, int *is_neg)
{
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			*is_neg = 1;
		s++;
	}
	return (s);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int		is_neg;
	long	tmp;

	nbr = 0;
	is_neg = 0;
	if (!*str)
		return (0);
	while (ft_isspace(*str))
		str++;
	str = ft_getsign(str, &is_neg);
	while (*str && *str >= 48 && *str <= 57)
	{
		tmp = nbr;
		nbr = (nbr * 10) + (*str++ - 48);
		if (nbr < tmp && is_neg == 0)
			return (-1);
		if (nbr < tmp && is_neg == 1)
			return (0);
	}
	if (is_neg == 1)
		return (-nbr);
	return (nbr);
}
