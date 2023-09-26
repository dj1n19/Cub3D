/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:53:10 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/26 17:00:10 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
