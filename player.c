/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:11:00 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/13 18:11:00 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_frame *frame, t_object *obj, int x, int y)
{
	obj->x += x * WIDTH;
	obj->y += y * HEIGHT;
	if (obj->x < 0)
		obj->x = 0;
	else if (obj->x + WIDTH > frame->width)
		obj->x = frame->width - WIDTH;
	else if (obj->y < 0)
		obj->y = 0;
	else if (obj->y + HEIGHT > frame->height)
		obj->y = frame->height - HEIGHT;
}
