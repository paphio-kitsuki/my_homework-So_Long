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

t_image	*create_image(t_frame *f, char *url)
{
	t_image	*i;
	i = (t_image *)malloc(sizeof(t_image));
	if (i == NULL)
		return (NULL);
	i->image = mlx_xpm_file_to_image(f->mlx, url, &i->width, &i->height);
	i->url = mlx_get_data_addr(i->image, &i->bpp, &i->length, &i->endian);
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
	i->url = mlx_get_data_addr(i->image, &i->bpp, &i->length, &i->endian);
	return (i);
}

t_object	*create_object(int x, int y, t_image *image)
{
	t_object	*out;

	out = (t_object *)malloc(sizeof(t_object));
	if (out == NULL)
		return (NULL);
	out->image = image;
	out->x = x;
	out->y = y;
	return (out);
}
