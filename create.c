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
	i->path = mlx_get_data_addr(i->image, &i->bpp, &i->length, &i->endian);
	return (i);
}

t_image	*create_empty_image(t_frame *f, int width, int height)
{
	t_image	*i;
	i = (t_image *)malloc(sizeof(t_image));
	if (i == NULL)
		return (NULL);
	i->width = width;
	i->height = height;
	i->image = mlx_new_image(f->mlx, i->width, i->height);
	i->path = mlx_get_data_addr(i->image, &i->bpp, &i->length, &i->endian);
	return (i);
}

static void	search_player_point(int **map, int height, int *x, int *y)
{
	*x = 0;
	while (*(map + *x) != NULL)
	{
		*y = 0;
		while (*y < height)
		{
			if (map[*x][*y] == 'P')
			{
				map[*x][*y] = 0;
				return ;
			}
			*y ++;
		}
		*x ++;
	}
	*x = -1;
	*y = -1;
}

t_player	*create_player(int **map, int height)
{
	t_player	*out;
	int			x;
	int			y;

	if (map == NULL || height <= 0)
		return (NULL);
	out = (t_player *)malloc(sizeof(t_player));
	if (out == NULL)
		return (NULL);
	search_player_point(map, height, &x, &y);
	if (x < 0 || y < 0)
	{
		free(out);
		return (NULL);
	}
	out->image = get_image(PLAYER);
	out->x = x;
	out->y = y;
	return (out);
}
