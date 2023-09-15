/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:35:06 by bgenie            #+#    #+#             */
/*   Updated: 2023/04/27 13:19:07 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char *line, char buffer)
{
	char	*nline;
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(line);
	nline = (char *) ft_malloc(sizeof(char) * (size + 2), NULL, MALLOC);
	while (line && line[i])
	{
		nline[i] = line[i];
		i++;
	}
	nline[i] = buffer;
	nline[i + 1] = 0;
	if (line)
		ft_malloc(0, line, FREE);
	return (nline);
}
