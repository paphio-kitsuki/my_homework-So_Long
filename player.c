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

int	move(t_frame *frame, int x, int y)
{
	t_player	*player;

	player = frame->player;
	player->x += x;
	player->y += y;
	if (player->x < 0)
		player->x = 0;
	else if (player->x >= (int)(frame->width))
		player->x = (int)(frame->width) - 1;
	else if (player->y < 0)
		player->y = 0;
	else if (player->y >= (int)(frame->height))
		player->y = (int)(frame->height) - 1;
	else if (frame->list[player->y][player->x] == WALL)
	{
		player->x -= x;
		player->y -= y;
	}
	else
		return (1);
	return (0);
}

void	action(t_frame *frame)
{
	char	*tmp;

	frame->player->move_count ++;
	ft_putstr("Move Count : ", STDOUT);
	tmp = ft_itoa(frame->player->move_count);
	if (tmp != NULL)
	{
		if (ISBONUS == 0)
		{
			ft_putstrln(tmp, STDOUT);
			free(tmp);
		}
		else
			set_count(tmp);
	}
	if ((frame->list)[frame->player->y][frame->player->x] == COLLECTION)
		(frame->list)[frame->player->y][frame->player->x] = ROAD;
	else if ((frame->list)[frame->player->y][frame->player->x] == GOAL)
	{
		if (search(frame->list, COLLECTION) == 0)
			exit_func(frame);
	}
	repaint(frame);
}
