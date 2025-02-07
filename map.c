/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:33:36 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/13 22:33:36 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*create_readlines(const char *path);
static int		**create_list(t_list *buffer, int *w, int *h, UINT *f);
static int		*create_numberline(t_list *buf, UINT *check, int *length);
static int		get_number(int *dst, char *src, size_t ct, UINT *flag);

int	**read_map(const char *path, int *width, int *height)
{
	int		**out;
	t_list	*buffer;
	char	*tmp;
	UINT	flag;

	if (path == NULL)
		return (NULL);
	tmp = ft_strrchr(path, '.');
	if (tmp == NULL || ft_strncmp(tmp, ".ber", 5) != 0)
		return (NULL);
	buffer = create_readlines(path);
	ft_lstfix(&buffer);
	if (buffer == NULL)
		return (NULL);
	*width = 0;
	out = create_list(buffer, width, height, &flag);
	ft_lstclear(&buffer);
	if (out != NULL && (flag & 14) != 14)
		clear_list(&out);
	return (out);
}

static t_list	*create_readlines(const char *path)
{
	t_list	*out;
	t_list	*tmp;
	char	*str;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = get_next_line(fd);
	out = NULL;
	while (str != NULL)
	{
		tmp = ft_lstnew(str);
		if (tmp == NULL)
		{
			ft_lstclear(&out);
			break ;
		}
		ft_lstadd_back(&out, tmp);
		str = get_next_line(fd);
	}
	close(fd);
	return (out);
}

static int	**create_list(t_list *buffer, int *w, int *h, UINT *flag)
{
	int	count;
	int	size;
	int	**out;

	*flag = 0;
	size = ft_lstsize(buffer);
	out = (int **)malloc(sizeof (int *) * (size + 1));
	if (out == NULL)
		return (NULL);
	count = 0;
	while (count < size)
	{
		out[count + 1] = NULL;
		out[count] = create_numberline(buffer, flag, w);
		if (out[count] == NULL)
		{
			clear_list(&out);
			return (NULL);
		}
		buffer = buffer->next;
		count ++;
	}
	*h = size;
	return (out);
}

static int	*create_numberline(t_list *buf, UINT *flag, int *length)
{
	int	*out;
	int	count;

	if (buf == NULL || flag == NULL || length == NULL)
		return (NULL);
	*flag &= ~(UINT)1;
	if (*length == 0 || buf->next == NULL)
		*flag |= 1;
	*length = ft_strlen(buf->str);
	if (buf->next != NULL && *length != (int)ft_strlen(buf->next->str))
		return (NULL);
	out = (int *)malloc(sizeof (int) * (*length + 1));
	if (out == NULL)
		return (NULL);
	count = 0;
	while (count < *length)
	{
		if (get_number(out, buf->str, count++, flag) < 0)
		{
			free(out);
			return (NULL);
		}
	}
	out[*length] = NONE;
	return (out);
}

static int	get_number(int *dst, char *src, size_t ct, UINT *f)
{
	if ((ct == 0 || ct == ft_strlen(src) - 1 || *f % 2 == 1) && src[ct] != '1')
		return (-1);
	if (((*f & 2) == 2 && src[ct] == 'E') || ((*f & 4) == 4 && src[ct] == 'P'))
		return (-1);
	if (src[ct] == 'E')
		*f += 2;
	else if (src[ct] == 'P')
		*f += 4;
	else if ((*f >> 3) % 2 == 0 && src[ct] == 'C')
		*f += 8;
	if (src[ct] == '0')
		dst[ct] = ROAD;
	else if (src[ct] == '1')
		dst[ct] = WALL;
	else if (src[ct] == 'C')
		dst[ct] = COLLECTION;
	else if (src[ct] == 'E')
		dst[ct] = GOAL;
	else if (src[ct] == 'P')
		dst[ct] = PLAYER;
	else if (ISBONUS > 0 && src[ct] == 'N')
		dst[ct] = ENEMY;
	else
		return (-1);
	return (0);
}
