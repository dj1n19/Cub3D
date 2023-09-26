/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:53:10 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/26 23:49:29 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	relase_key_hook(int keycode, t_key_states *ks)
{
	if (keycode == LEFT)
		ks->left = false;
	else if (keycode == RIGHT)
		ks->right = false;
	if (keycode == NORTH)
		ks->north = false;
	else if (keycode == SOUTH)
		ks->south = false;
	else if (keycode == EAST)
		ks->east = false;
	else if (keycode == WEST)
		ks->west = false;
	return (0);
}

int	key_hook(int keycode, t_key_states *ks)
{
	if (keycode == ESC)
		ft_exit(NULL);
	else if (keycode == LEFT)
		ks->left = true;
	else if (keycode == RIGHT)
		ks->right = true;
	else if (keycode == NORTH)
		ks->north = true;
	else if (keycode == SOUTH)
		ks->south = true;
	else if (keycode == EAST)
		ks->east = true;
	else if (keycode == WEST)
		ks->west = true;
	return (0);
}
