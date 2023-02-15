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

void	get_framesize(t_frame *frame, int *width, int *height)
{
	mlx_get_screen_size(frame->mlx, width, height);
	if (frame->width > *width / WIDTH)
		*width = *width / WIDTH;
	else
		*width = frame->width;
	*width *= WIDTH;
	if (frame->height > *height / HEIGHT)
		*height = *height / HEIGHT;
	else
		*height = frame->height;
	*height *= HEIGHT;
}
