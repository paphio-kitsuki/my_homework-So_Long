/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repaint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 01:03:08 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/12 01:03:08 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_image	*images;

int	repaint(t_frame *frame)
{
	mlx_put_image_to_window(frame->mlx, frame->win, images->image, 0, 0);
	return (0);
}

void	add_image(t_image *image)
{
	images = image;
}