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

	if (image == NULL || image->path == NULL)
		return ;
	tmp = image->path + (y * image->length + x * (image->bpp / 8));
	*(UINT *)tmp = color;
}

UINT	get_pixel(t_image *image, int x, int y)
{
	char	*tmp;

	if (image == NULL || image->path == NULL)
		return (0);
	tmp = image->path + (y * image->length + x * (image->bpp / 8));
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
			color = get_pixel(src, i, j);
			if (get_alpha(color) != TRANSPARENCY)
				put_pixel(dst, i + x * WIDTH, j + y * HEIGHT, color);
			j ++;
		}
		i ++;
	}
}

void	draw_player(t_image *image, t_player *p)
{
	draw_image(image, p->image, p->x, p->y);
}
