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
	*width -= 10;
	*height -= 50;
	if (frame->width <= *width / WIDTH)
		*width = frame->width * WIDTH;
	if (frame->height <= *height / HEIGHT)
		*height = frame->height * HEIGHT;
}
