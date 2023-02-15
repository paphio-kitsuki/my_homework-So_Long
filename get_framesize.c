/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_framesize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:06:07 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/15 18:06:07 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_framewidth(t_frame *frame)
{
	int	width;

	mlx_get_screen_size(frame->mlx, &width, NULL);
	if (frame->width > width / WIDTH)
		width = width / WIDTH;
	else
		width = frame->width;
	width *= WIDTH;
	return (width);
}

int	get_frameheight(t_frame *frame)
{
	int	height;

	mlx_get_screen_size(frame->mlx, NULL, &height);
	if (frame->height > height / HEIGHT)
		height = height / HEIGHT;
	else
		height = frame->height;
	height *= HEIGHT;
	return (height);
}