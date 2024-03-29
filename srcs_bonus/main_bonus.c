/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 06:46:58 by mebourge          #+#    #+#             */
/*   Updated: 2023/10/01 15:00:55 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

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
	char	*ext;

	if (argc != 2)
		ft_error(ARGUMENT_ERROR);
	ext = ft_strrchr(argv[1], '.');
	if (!ext || ft_strnstr(ext, ".cub", 5) == NULL || *(ext + 4) != 0)
		ft_error("Bad file format");
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		ft_error(FILE_DESRIPTOR_ERROR);
	map = check_map(fd, argv);
	ft_verif_map_size(&map);
	display_window(&map);
}
