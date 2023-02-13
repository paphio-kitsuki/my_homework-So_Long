/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:36:13 by kitsuki           #+#    #+#             */
/*   Updated: 2022/12/31 02:32:45 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char		*sendline(t_memo *memo, char *end);
static ssize_t	buffered_read(int fd, t_memo *dst, char *buffer);
static t_memo	*search_memo(int fd, t_memo **memo);
static void		clear_memo(int fd, t_memo **memo);

char	*get_next_line(int fd)
{
	static t_memo	*strage = NULL;
	t_memo			*memo;
	char			*after;
	ssize_t			sign;
	char			*buffer;

	memo = search_memo(fd, &strage);
	if (memo == NULL)
		return (NULL);
	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	sign = 1;
	while (sign > 0)
	{
		after = search_newline(memo->memo);
		if (after != NULL)
			break ;
		sign = buffered_read(fd, memo, buffer);
	}
	if (buffer != NULL)
		free(buffer);
	if (sign >= 0)
		after = sendline(memo, after);
	if (after == NULL || memo->memo == NULL)
		clear_memo(fd, &strage);
	return (after);
}

static ssize_t	buffered_read(int fd, t_memo *dst, char *buffer)
{
	ssize_t	sign;

	if (buffer == NULL)
		return (-1);
	sign = read(fd, (void *)buffer, (size_t)BUFFER_SIZE);
	if (sign > 0)
	{
		buffer[sign] = '\0';
		if (memo_join(dst, buffer) == -1)
			return (-1);
	}
	return (sign);
}

static char	*sendline(t_memo *memo, char *end)
{
	char	*out;
	char	*tmp;

	if (memo == NULL || memo->memo == NULL)
		return (NULL);
	if (end == NULL)
	{
		out = memo->memo;
		memo->memo = NULL;
		return (out);
	}
	out = ft_substr(memo->memo, 0, end - memo->memo);
	tmp = memo->memo;
	memo->stack = 0;
	if (ft_strlen(end) == 0)
		memo->memo = NULL;
	else
		memo->memo = ft_substr(end, 0, ft_strlen(end));
	free(tmp);
	return (out);
}

static t_memo	*search_memo(int fd, t_memo **memo)
{
	t_memo	*out;
	t_memo	*tmp;

	if (memo == NULL || BUFFER_SIZE < 0 || BUFFER_SIZE > ((size_t)-1) - 1)
		return (NULL);
	out = *memo;
	while (out != NULL && out->fd != fd)
		out = out->next;
	if (out != NULL)
		return (out);
	out = (t_memo *)malloc(sizeof(t_memo));
	if (out == NULL)
		return (NULL);
	out->fd = fd;
	out->memo = NULL;
	out->next = NULL;
	out->stack = 0;
	tmp = *memo;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	if (*memo == NULL)
		*memo = out;
	else
		tmp->next = out;
	return (out);
}

static void	clear_memo(int fd, t_memo **memo)
{
	t_memo	*now;
	t_memo	*next;

	if (memo == NULL || *memo == NULL)
		return ;
	now = *memo;
	while (now->next != NULL)
	{
		if (now->next->fd == fd)
			break ;
		now = now->next;
	}
	if (now->next == NULL && now->fd != fd)
		return ;
	if (now->fd == fd)
		(*memo) = (*memo)->next;
	else if (now->next != NULL)
	{
		next = now->next;
		now->next = next->next;
		now = next;
	}
	if (now->memo != NULL)
		free(now->memo);
	free(now);
}
