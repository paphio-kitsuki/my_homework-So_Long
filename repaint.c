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

int	repaint(t_frame *f)
{
	t_list	*lst;
	t_image	*background;

	clear_background();
	background = get_image(BACKGROUND);
	lst = f->list;
	while (lst != NULL)
	{
		draw_object(background, lst->content);
		lst = lst->next;
	}
	mlx_put_image_to_window(f->mlx, f->win, background, 0, 0);
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
			draw_image(background, get_image(ROAD), i * WIDTH, j * HEIGHT);
			j ++;
		}
	}
}
