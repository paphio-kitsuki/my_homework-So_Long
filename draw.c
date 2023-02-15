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

static UINT	calc_color(UINT color1, UINT color2);

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

void	add_color_all(t_image *image, UINT color)
{
	int		x;
	int		y;

	x = 0;
	while (x < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			put_pixel(image, x, y, calc_color(color, get_pixel(image, x, y)));
			y ++;
		}
		x ++;
	}
}

static UINT	calc_color(UINT color1, UINT color2)
{
	UINT	calc;
	UINT	tmp;

	tmp = get_alpha(color1) + get_alpha(color2);
	if (tmp > 255)
		tmp = 255;
	calc = tmp;
	calc <<= 8;
	tmp = get_red(color1) + get_red(color2);
	if (tmp > 255)
		tmp = 255;
	calc += tmp;
	calc <<= 8;
	tmp = get_green(color1) + get_green(color2);
	if (tmp > 255)
		tmp = 255;
	calc += tmp;
	calc <<= 8;
	tmp = get_blue(color1) + get_blue(color2);
	if (tmp > 255)
		tmp = 255;
	calc += tmp;
	return (calc);
}
