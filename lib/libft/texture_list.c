/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:21:50 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/28 11:40:09 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	delete_texture_list(t_texture_list *list)
{
	if (!list)
		return ;
	while (list->size)
		pop_tex(list);
	if (list->mlx_win)
		mlx_destroy_window(list->mlx_ptr, list->mlx_win);
}

void	pop_tex(t_texture_list *list)
{
	t_texture_node	*tmp;

	if (list->size == 1)
		list->tail = NULL;
	tmp = list->head;
	list->head = list->head->next;
	mlx_destroy_image(list->mlx_ptr, tmp->img);
	free(tmp);
	list->size--;
}

void	push_tex(t_texture_list *list, t_texture_node *node)
{
	if (list->size == 0)
		list->tail = node;
	node->next = list->head;
	list->head = node;
	list->size++;
}

t_texture_list	*create_texture_list(void *mlx_ptr)
{
	static t_texture_list	list;

	list.head = NULL;
	list.tail = NULL;
	list.size = 0;
	list.mlx_ptr = mlx_ptr;
	list.mlx_win = NULL;
	return (&list);
}

t_texture_node	*create_texture_node(void *img)
{
	t_texture_node	*node;

	node = malloc(sizeof(t_texture_node));
	if (!node)
		return (NULL);
	node->img = img;
	node->next = NULL;
	return (node);
}
