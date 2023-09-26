/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:28:26 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/26 23:50:31 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	load_textures(t_s *s)
{
	s->xpm = ft_malloc(4 * sizeof(t_xpm), NULL, MALLOC);
	s->xpm[0] = textures_init(s, s->map->north_texture);
	s->xpm[1] = textures_init(s, s->map->south_texture);
	s->xpm[2] = textures_init(s, s->map->east_texture);
	s->xpm[3] = textures_init(s, s->map->west_texture);
}
