/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:59:30 by bgenie            #+#    #+#             */
/*   Updated: 2023/05/28 18:26:41 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	delete_malloc_list(t_malloc *list)
{
	if (!list)
		return ;
	while (list->size)
		pop(list);
}

void	pop(t_malloc *list)
{
	t_malloc_node	*tmp;

	if (list->size == 1)
		list->tail = NULL;
	tmp = list->head;
	list->head = list->head->next;
	free(tmp->allocation);
	free(tmp);
	list->size--;
}

void	push(t_malloc *list, t_malloc_node *node)
{
	if (list->size == 0)
		list->tail = node;
	node->next = list->head;
	list->head = node;
	list->size++;
}

t_malloc	*create_malloc_list(void)
{
	static t_malloc	list;

	list.head = NULL;
	list.tail = NULL;
	list.size = 0;
	return (&list);
}

t_malloc_node	*create_malloc_node(void *ptr, size_t size)
{
	t_malloc_node	*node;

	node = malloc(sizeof(t_malloc_node));
	if (!node)
		return (NULL);
	node->allocation = ptr;
	node->size = size;
	node->next = NULL;
	return (node);
}
