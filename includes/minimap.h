/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:34:36 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/10 16:27:05 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H
# include <math.h>
# include "constants.h"

typedef struct s_minimap
{
	
}	t_minimap;

/*
*	structure de return du path_finding
*/
typedef struct s_path_return
{
	int moves;
	int *x;
	int *y;
}	 t_path_return;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif