/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:45:21 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/11 17:45:21 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_image *image, int x, int y, UINT color)
{
	char	*tmp;

	if (image == NULL || image->url == NULL)
		return ;
	tmp = image->url + (y * image->length + x * (image->bpp / 8));
	*(UINT *)tmp = color;
}

UINT	get_pixel(t_image *image, int x, int y)
{
	char	*tmp;

	if (image == NULL || image->url == NULL)
		return ;
	tmp = image->url + (y * image->length + x * (image->bpp / 8));
	return (*(UINT *)tmp);
}

void	draw_image(t_image *dst, t_image *src, int x, int y)
{
	int		i;
	int		j;
	UINT	color;

	i = 0;
	while (i < src->width)
	{
		j = 0;
		while (j < src->height)
		{
			color = get_pixel(src->image, i, j);
			put_pixel(dst, i + x, j + y, color);
			j ++;
		}
		i ++;
	}
}

void	draw_object(t_image *image, t_object *obj)
{
	draw_image(image, obj->image, obj->x, obj->y);
}
