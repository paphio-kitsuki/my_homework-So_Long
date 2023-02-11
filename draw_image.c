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

	if (image == NULL || image->addr == NULL)
		return ;
	tmp = image->addr + (y * image->length + x * (image->bpp / 8));
	*(UINT *)tmp = color;
}

void	draw_image()
{
}