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

static int	clear_background(void);

int	repaint(t_frame *f)
{
	t_image	*background;
	int		i;
	int		j;

	clear_background();
	background = get_image(BACKGROUND);
	i = 0;
	while (i < f->width)
	{
		j = 0;
		while (j < f->height)
		{
			if ((f->list)[j][i] != ROAD)
				draw_image(background, get_image((f->list)[j][i]), i, j);
			j ++;
		}
		i ++;
	}
	draw_image(background, f->player->image, f->player->x, f->player->y);
	mlx_put_image_to_window(f->mlx, f->win, background->image, 0, 0);
	return (0);
}

static int	clear_background(void)
{
	t_image	*background;
	int		i;
	int		j;

	background = get_image(BACKGROUND);
	i = 0;
	while (i < background->width / WIDTH)
	{
		j = 0;
		while (j < background->height / HEIGHT)
		{
			draw_image(background, get_image(ROAD), i, j);
			j ++;
		}
	i ++;
	}
}
