/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:42:21 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/26 23:50:19 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

t_xpm	textures_init(t_s *s, char *path)
{
	t_xpm	sprite;

	sprite.img = mlx_xpm_file_to_image(s->p->mlx, path,
			&sprite.width, &sprite.height);
	if (!sprite.img)
		ft_error(TEX_LOAD);
	ft_mlx_texture(s->p->mlx, sprite.img, MTEX);
	sprite.addr = mlx_get_data_addr(sprite.img,
			&sprite.bits_per_pixel, &sprite.line_length, &sprite.endian);
	return (sprite);
}

//fonction d'aatribution de la couleur du pixel sur la texture

unsigned int	get_wall_face_color(t_s *s, char wall_face, int x, int y)
{
	t_xpm	*texture;
	int		texture_idx;

	texture_idx = -1;
	if (wall_face == 'N')
		texture_idx = 0;
	else if (wall_face == 'S')
		texture_idx = 1;
	else if (wall_face == 'E')
		texture_idx = 2;
	else if (wall_face == 'W')
		texture_idx = 3;
	else if (texture_idx == -1)
		return (0xFFFFFF);
	texture = &s->xpm[texture_idx];
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	return (*(unsigned int *)(texture->addr
		+ (y * texture->line_length + x * (texture->bits_per_pixel / 8))));
}

//fonction de correction de fisheye

float	get_corrected_distance(float distance, float angle)
{
	float	corrected_distance;

	corrected_distance = distance * cos(angle);
	return (corrected_distance);
}

//fonction pour mettre les variable de t_s 
//dans les variables spécifiques au raycast

void	cast_rays(t_s *s)
{
	t_camera	camera;
	float		player_x;
	float		player_y;

	player_x = s->player->x / TILE_SIZE;
	player_y = s->player->y / TILE_SIZE;
	camera = (t_camera){{player_y, player_x}, {s->player->player_angle, -1.0}};
	render(&camera, s->map->map, s);
}
