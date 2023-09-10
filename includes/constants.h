/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:25:26 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/10 18:06:52 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H


/*
*	Macros de gestion des visuels
*/

# define SCREEN_HEIGHT 700
# define SCREEN_HEIGHT_1 SCREEN_HEIGHT / 2
# define SCREEN_WIDTH 1200
# define TITLE_SCREEN "Cub3D"
# define MAX_FPS 100
# define BITS_PER_BYTE 8
# define MINIMAP_X 170
# define MINIMAP_Y 170

# define TILE_SIZE 20

#define FOV M_2_SQRTPI
#define NUM_RAYS SCREEN_WIDTH

/*
*	Macros de gestion mathematique
*/

#define COLLISION_MARGIN 0.00001f

# define PI 3.141592
# define CASTED_RAYS 1400
# define STEP_ANGLE FOV / CASTED_RAYS
# define SCALE (SCREEN_WIDTH / 2) / CASTED_RAYS

#define SPRITE_WIDTH 64
#define SPRITE_HEIGHT 64

/*
*	FPS COUNTER
*/
#define NUM_FRAMES_TO_MEASURE 10

#endif