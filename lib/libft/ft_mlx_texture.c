/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:33:41 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/26 23:23:11 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static void	ft_add_img(t_texture_list *list, void *img)
{
	t_texture_node	*node;

	node = create_texture_node(img);
	if (!node)
	{
		delete_texture_list(list);
		write(2, EALLOC, 21);
		exit(EXIT_FAILURE);
	}
	push_tex(list, node);
}

void	ft_mlx_texture(void *mlx_ptr, void *img, int action)
{
	static t_texture_list	*list = NULL;

	if (!list)
		list = create_texture_list(mlx_ptr);
	if (action == INIT)
		list->mlx_win = img;
	if (action == MTEX)
		ft_add_img(list, img);
	else if (action == CTEX)
		delete_texture_list(list);
}
