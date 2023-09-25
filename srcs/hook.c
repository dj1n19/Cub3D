/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:53:10 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/25 14:45:12 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	relase_key_hook(int keycode, t_key_states *ks)
{
	if (keycode == EAST)
		ks->east = false;
	else if (keycode == WEST)
		ks->west = false;
	else if (keycode == NORTH)
		ks->north = false;
	else if (keycode == SOUTH)
		ks->south = false;
	return (0);
}

int	key_hook(int keycode, t_key_states *ks)
{
	if (keycode == ESC)
		ft_exit(NULL);
	else if (keycode == EAST)
		ks->east = true;
	else if (keycode == WEST)
		ks->west = true;
	else if (keycode == NORTH)
		ks->north = true;
	else if (keycode == SOUTH)
		ks->south = true;
	return (0);
}
