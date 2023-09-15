/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:28:26 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/12 16:23:14 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_textures(t_s *s)
{
	s->xpm = ft_malloc(5 * sizeof(t_xpm), NULL, MALLOC);
	
	s->xpm[0] = textures_init(s, s->map->north_texture);
	s->xpm[1] = textures_init(s, s->map->south_texture);
	s->xpm[2] = textures_init(s, s->map->east_texture);
	s->xpm[3] = textures_init(s, s->map->west_texture);
	s->xpm[4] = textures_init(s, "assets/ben.xpm");
}
