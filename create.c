/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:33:34 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/12 01:33:34 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*create_image(t_frame *f, char *path)
{
	t_image	*i;

	i = (t_image *)malloc(sizeof(t_image));
	if (i == NULL)
		return (NULL);
	i->image = mlx_xpm_file_to_image(f->mlx, path, &i->width, &i->height);
	if (i->image == NULL)
	{
		free(i);
		return (NULL);
	}
	i->path = mlx_get_data_addr(i->image, &i->bpp, &i->length, &i->endian);
	return (i);
}

t_image	*create_empty_image(t_frame *f, size_t width, size_t height)
{
	t_image	*i;

	if (width > INT_MAX / WIDTH || height > INT_MAX / HEIGHT)
		return (NULL);
	i = (t_image *)malloc(sizeof(t_image));
	if (i == NULL)
		return (NULL);
	i->width = (int)(width * WIDTH);
	i->height = (int)(height * HEIGHT);
	i->image = mlx_new_image(f->mlx, i->width, i->height);
	if (i->image == NULL)
	{
		free(i);
		return (NULL);
	}
	i->path = mlx_get_data_addr(i->image, &i->bpp, &i->length, &i->endian);
	return (i);
}

static void	search_player_point(int **map, int *x, int *y)
{
	*y = 0;
	while (*(map + *y) != NULL)
	{
		*x = 0;
		while (map[*y][*x] != NONE)
		{
			if (map[*y][*x] == PLAYER)
			{
				map[*y][*x] = ROAD;
				return ;
			}
			(*x)++;
		}
		(*y)++;
	}
	*x = -1;
	*y = -1;
}

t_player	*create_player(t_image *image, int **map)
{
	t_player	*out;
	int			x;
	int			y;

	if (map == NULL)
		return (NULL);
	out = (t_player *)malloc(sizeof(t_player));
	if (out == NULL)
		return (NULL);
	search_player_point(map, &x, &y);
	if (x < 0 || y < 0)
	{
		free(out);
		return (NULL);
	}
	out->image = image;
	out->x = x;
	out->y = y;
	out->firstx = x;
	out->firsty = y;
	out->move_count = 0;
	out->direction = 2 * 3 + 0;
	return (out);
}
