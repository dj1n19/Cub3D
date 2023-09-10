/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 06:46:54 by merlinbourg       #+#    #+#             */
/*   Updated: 2023/09/10 18:06:26 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error.h"

// fonction d'affichage des erreur

void	ft_error(char *str)
{
	printf("%s\n", "Error");
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}
