/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dj1n <dj1n@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:38:08 by bgenie            #+#    #+#             */
/*   Updated: 2022/12/17 00:11:11 by dj1n             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
// TEST
// # include "../leaks_checker/leaks.h"
// TEST
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
size_t	ft_parse_format(char c, va_list ap);
size_t	ft_printchar(int c);
size_t	ft_printstr(char *str);
size_t	ft_printptr(void *ptr);
size_t	ft_printdec(int nbr);
size_t	ft_printudec(unsigned int nbr);
size_t	ft_printhex(char *hex, int upper, int padding);
char	*ft_utohex(unsigned int nbr);

#endif
