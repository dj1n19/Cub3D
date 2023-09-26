/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 06:46:58 by merlinbourg       #+#    #+#             */
/*   Updated: 2023/09/26 15:30:06 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_exit(void *data)
{
	(void)data;
	ft_malloc(0, NULL, CLEAR);
	ft_mlx_texture(NULL, NULL, CTEX);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc != 2)
		ft_error(ARGUMENT_ERROR);
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		ft_error(FILE_DESRIPTOR_ERROR);
	map = check_map(fd, argv);
	display_window(&map);
}
