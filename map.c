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
static int		**create_list(t_list *buffer, int *width, int *height);
static int		*create_numberline(t_list *buf, UINT *checker, int *length);
static int		get_number(int *dst, char *src, size_t ct, UINT *flag);

int	**read_map(const char *path, int *width, int *height)
{
	int		**out;
	t_list	*buffer;
	char	*tmp;

	if (path == NULL)
		return (NULL);
	tmp = ft_strrchr(path, '.');
	if (tmp == NULL || ft_strncmp(tmp, ".ber", 5) != 0)
		return (NULL);
	buffer = create_readlines(path);
	ft_lstfix(&buffer);
	if (buffer == NULL)
		return (NULL);
	*width = -1;
	out = create_list(buffer, width, height);
	ft_lstclear(&buffer);
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

static int	**create_list(t_list *buffer, int *width, int *height)
{
	size_t	count;
	size_t	size;
	UINT	checker;
	int		**out;

	checker = 0;
	size = ft_lstsize(buffer);
	out = (int **)malloc(sizeof (int *) * (size + 1));
	if (out == NULL)
		return (NULL);
	count = 0;
	while (count < size)
	{
		out[count + 1] = NULL;
		out[count] = create_numberline(buffer, &checker, width);
		if (out[count] == NULL)
		{
			clear_list(&out);
			return (NULL);
		}
		buffer = buffer->next;
		count ++;
	}
	*height = size;
	return (out);
}

static int	*create_numberline(t_list *buf, UINT *checker, int *length)
{
	int		*out;
	size_t	count;

	if (buf == NULL || checker == NULL || length == NULL)
		return (NULL);
	*checker &= !(UINT)1;
	if (*length == -1 || buf->next == NULL)
		*checker |= 1;
	*length = ft_strlen(buf->str);
	if (buf->next != NULL && *length != ft_strlen(buf->next->str))
		return (NULL);
	out = (int *)malloc(sizeof (int) * (*length +  1));
	if (out == NULL)
		return (NULL);
	count = 0;
	while (count < *length)
	{
		if (get_number(out, buf->str, count++, checker) < 0)
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
	if ((*f >> 1) % 2 == 1 && src[ct] == 'E')
		return (-1);
	if ((*f >> 2) % 2 == 1 && src[ct] == 'P')
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
	else
		return (-1);
	return (0);
}
