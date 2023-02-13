/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:33:24 by kitsuki           #+#    #+#             */
/*   Updated: 2022/12/27 19:02:22 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	set_memory(t_memo *dst, size_t size, size_t add);

char	*search_newline(char *s)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\n' && *s != '\r' && *s != '\0')
		s ++;
	if (*s == '\r')
	{
		if (*(s + 1) == '\n')
			return (s + 2);
		else if (*(s + 1) == '\0')
			return (NULL);
		return (s + 1);
	}
	else if (*s == '\n')
		return (s + 1);
	return (NULL);
}

int	memo_join(t_memo *s1, char *s2)
{
	size_t	count;
	size_t	s1size;
	size_t	s2size;

	if (s1 == NULL || (s1->memo == NULL && s2 == NULL))
		return (-1);
	s1size = ft_strlen(s1->memo);
	s2size = ft_strlen(s2);
	if (set_memory(s1, s1size, s2size) == -1)
		return (-1);
	if (s1->stack != 0)
		s1->stack -= s2size;
	count = 0;
	while (count < s2size)
	{
		*(s1->memo + s1size + count) = *(s2 + count);
		count ++;
	}
	*(s1->memo + s1size + s2size) = '\0';
	return (0);
}

static int	set_memory(t_memo *dst, size_t size, size_t add)
{
	static const size_t	memory = 50;
	char				*out;

	if (dst == NULL || dst->stack >= add)
		return (0);
	if (memory > (size_t)BUFFER_SIZE)
	{
		while (dst->stack < add)
			dst->stack += memory;
		out = (char *)malloc(size + dst->stack + 1);
	}
	else
		out = (char *)malloc(size + add + 1);
	if (out == NULL)
		return (-1);
	while (size > 0)
	{
		*(out + size - 1) = *(dst->memo + size - 1);
		size --;
	}
	if (dst->memo != NULL)
		free(dst->memo);
	dst->memo = out;
	return (1);
}
