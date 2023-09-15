/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:15:23 by bgenie            #+#    #+#             */
/*   Updated: 2023/05/28 18:26:59 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

static t_malloc_node	*fetch_allocation(t_malloc *list, void *ptr)
{
	t_malloc_node	*node;

	node = list->head;
	while (node)
	{
		if (node->allocation == ptr)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static void	ft_free(t_malloc *list, void *ptr)
{
	t_malloc_node	*node;
	t_malloc_node	*previous;

	previous = list->head;
	node = fetch_allocation(list, ptr);
	if (!node)
	{
		free(ptr);
		return ;
	}
	if (node == previous)
		list->head = list->head->next;
	else
	{
		while (previous->next != node)
			previous = previous->next;
		previous->next = node->next;
	}
	if (ptr)
		free(ptr);
	free(node);
	list->size--;
}

static void	*ft_alloc(t_malloc *list, size_t size)
{
	t_malloc_node	*node;
	void			*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		delete_malloc_list(list);
		exit(EXIT_FAILURE);
	}
	node = create_malloc_node(ptr, size);
	if (!node)
	{
		delete_malloc_list(list);
		write(2, EALLOC, 21);
		exit(EXIT_FAILURE);
	}
	push(list, node);
	return (ptr);
}

static void	*ralloc(t_malloc *list, void *ptr, size_t size)
{
	t_malloc_node	*node;

	node = create_malloc_node(ptr, size);
	if (!node)
	{
		delete_malloc_list(list);
		write(2, EALLOC, 21);
		exit(EXIT_FAILURE);
	}
	node->allocation = ft_realloc(ptr, size);
	if (!node->allocation)
	{
		delete_malloc_list(list);
		write(2, EALLOC, 21);
		exit(EXIT_FAILURE);
	}
	push(list, node);
	return (node->allocation);
}

void	*ft_malloc(size_t size, void *ptr, int action)
{
	static t_malloc	*list = NULL;

	if (!list)
		list = create_malloc_list();
	if (action == MALLOC)
		return (ft_alloc(list, size));
	else if (action == FREE)
		ft_free(list, ptr);
	else if (action == CLEAR)
		delete_malloc_list(list);
	else if (action == REALLOC)
		return (ralloc(list, ptr, size));
	return (NULL);
}
