/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:04:43 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/10 18:06:45 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define CHAR_ERROR "Unrecognized characters"
# define MAP_LAYOUT_ERROR "Bad map layout"
# define ARGUMENT_ERROR "Invalid argument"
# define FILE_DESRIPTOR_ERROR "Bad file descriptor"
# define BAD_PLAYER_ERROR "Not enough or too many players present on the map"
# define BAD_FILE "Bad file arrangement"
# include <stdio.h>

void	ft_error(char *str);

#endif