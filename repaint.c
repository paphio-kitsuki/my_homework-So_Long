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

int	paint(t_frame *frame)
{
	t_list		*lst;
	t_object	*obj;

	lst = frame->list;
	while (lst != NULL)
	{
		obj = lst->content;
		printf("before\n");
		mlx_put_image_to_window(frame->mlx, frame->win, obj->image->image, obj->x, obj->y);
		printf("before\n");
		lst = lst->next;
	}
	return (0);
}

int	repaint(t_frame *frame)
{
	t_list		*lst;

	lst = frame->list;
	while (lst != NULL)
	{
		mlx_destroy_image(frame->mlx, lst->content->image->image);
		lst = lst->next;
	}
	paint(frame);
	return (0);
}
