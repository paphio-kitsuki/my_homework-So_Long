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

static void	clear_background(t_frame *frame);

int	repaint(t_frame *f)
{
	t_image	*background;
	int		i;
	int		j;

	clear_background(f);
	background = f->images[BACKGROUND];
	i = 0;
	while (i < (int)(f->width))
	{
		j = 0;
		while (j < (int)(f->height))
		{
			if ((f->list)[j][i] != ROAD)
				draw_image(background, f->images[(f->list)[j][i]], i, j);
			j ++;
		}
		i ++;
	}
	draw_image(background, f->player->image, f->player->x, f->player->y);
	print_extra(f, get_count());
	return (0);
}

static void	clear_background(t_frame *frame)
{
	t_image	*background;
	int		i;
	int		j;

	background = frame->images[BACKGROUND];
	i = 0;
	while (i < background->width / WIDTH)
	{
		j = 0;
		while (j < background->height / HEIGHT)
		{
			draw_image(background, frame->images[ROAD], i, j);
			j ++;
		}
	i ++;
	}
}
