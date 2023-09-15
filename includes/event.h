/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:45:23 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/11 15:57:18 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H
# include <stdbool.h>

typedef enum e_directions
{
	// SOUTH = 1,
	// NORTH = 13,
	// EAST = 2,
	// WEST = 0,
	// ESC = 53,
	NORTH = 119,
	WEST = 97,
	SOUTH = 115,
	EAST = 100,
	ESC = 65307,
}	t_directions;

/*
*	structure de gestion des event clavier
*/
typedef struct s_key_states
{
    bool east;
    bool west;
    bool north;
    bool south;
} t_key_states;

/*
*	hook.c
*/
int key_hook(int keycode, t_key_states *ks);
int	relase_key_hook(int	keycode, t_key_states *ks);

#endif