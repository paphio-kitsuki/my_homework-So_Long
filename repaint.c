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
#include <stdio.h>

static int	clear_background(t_frame *frame);

int	repaint(t_frame *f)
{
	t_list	*lst;
	//t_image	*background;

	clear_background(f);
	//background = get_image(BACKGROUND);
	lst = f->list;
	while (lst != NULL)
	{
		draw_object(f, lst->content);
		lst = lst->next;
	}
	//mlx_put_image_to_window(f->mlx, f->win, background->image, 0, 0);
	return (0);
}

static int	clear_background(t_frame *frame)
{
	t_image	*road;
	int		i;
	int		j;

	road = get_image(ROAD);
	i = 0;
	while (i < frame->width / WIDTH)
	{
		j = 0;
		while (j < frame->height / HEIGHT)
		{
			draw_image(frame, road, i * WIDTH, j * HEIGHT);
			j ++;
		}
	i ++;
	}
}
