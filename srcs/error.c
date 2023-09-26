/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 06:46:54 by merlinbourg       #+#    #+#             */
/*   Updated: 2023/09/25 22:10:27 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// fonction d'affichage des erreur

void	ft_error(char *str)
{
	printf("%s\n", "Error");
	printf("%s\n", str);
	ft_malloc(0, NULL, CLEAR);
	ft_mlx_texture(NULL, NULL, CTEX);
	exit(EXIT_FAILURE);
}
