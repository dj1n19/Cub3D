/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:53:10 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/17 23:25:25 by bgenie           ###   ########.fr       */
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
	if (keycode == 53)
		exit(0);
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
