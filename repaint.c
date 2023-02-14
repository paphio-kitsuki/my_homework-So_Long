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
static void	paint_player(t_image *background, t_player *player);

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
	paint_player(background, f->player);
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

static void	paint_player(t_image *background, t_player *player)
{
	int		i;
	int		j;
	int		x;
	int		y;
	UINT	color;

	x = player->x * WIDTH;
	i = (player->direction % 2) * WIDTH;
	while (x / WIDTH <= player->x)
	{
		y = player->y * HEIGHT;
		j = (player->direction / 2) * HEIGHT;
		while (y / HEIGHT <= player->y)
		{
			color = get_pixel(player->image, i, j);
			if (get_alpha(color) != TRANSPARENCY)
				put_pixel(background, x, y, color);
			j ++;
			y ++;
		}
		i ++;
		x ++;
	}
}
