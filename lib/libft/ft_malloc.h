/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:35:12 by bgenie            #+#    #+#             */
/*   Updated: 2023/09/16 15:52:26 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include <stdlib.h>
# include <unistd.h>
# define EALLOC "Error: malloc failed\n"
# define EFREE "Error: invalid free\n"

typedef enum e_action
{
	MALLOC,
	REALLOC,
	FREE,
	CLEAR
}	t_action;

typedef struct s_malloc_node
{
	void					*allocation;
	size_t					size;
	struct s_malloc_node	*next;
}	t_malloc_node;

typedef struct s_malloc
{
	struct s_malloc_node	*head;
	struct s_malloc_node	*tail;
	size_t					size;
}	t_malloc;

/*
*		malloc_list.c
*/
t_malloc_node	*create_malloc_node(void *ptr, size_t size);
t_malloc		*create_malloc_list(void);
void			push(t_malloc *list, t_malloc_node *node);
void			pop(t_malloc *list);
void			delete_malloc_list(t_malloc *list);

/*
*		ft_malloc.c
*/
void			*ft_malloc(size_t size, void *ptr, int action);

/*
*		ft_realloc.c
*/
void			*ft_realloc(char *p, size_t size);

char			*ft_strdup(const char *s1);

#endif