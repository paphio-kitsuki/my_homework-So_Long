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

static void	judge(t_frame *frame);

int	move(t_frame *frame, int x, int y)
{
	if (frame == NULL || frame->status != PLAYING)
		return (0);
	frame->player->x += x;
	frame->player->y += y;
	set_direction(frame, x, y);
	if (frame->player->x < 0)
		frame->player->x = 0;
	else if (frame->player->x >= (int)(frame->width))
		frame->player->x = (int)(frame->width) - 1;
	else if (frame->player->y < 0)
		frame->player->y = 0;
	else if (frame->player->y >= (int)(frame->height))
		frame->player->y = (int)(frame->height) - 1;
	else if (frame->list[frame->player->y][frame->player->x] == WALL)
	{
		frame->player->x -= x;
		frame->player->y -= y;
	}
	else
		return (1);
	return (0);
}

void	action(t_frame *frame)
{
	char	*tmp;

	frame->player->move_count ++;
	tmp = ft_itoa(frame->player->move_count);
	if (tmp != NULL)
	{
		if (ISBONUS == 0)
		{
			ft_putstr(MOVE_STR, STDOUT);
			ft_putstrln(tmp, STDOUT);
			free(tmp);
		}
		else
			set_count(tmp);
	}
	judge(frame);
	repaint(frame);
}

static void	judge(t_frame *frame)
{
	if ((frame->list)[frame->player->y][frame->player->x] == COLLECTION)
		(frame->list)[frame->player->y][frame->player->x] = COLLECTED;
	else if ((frame->list)[frame->player->y][frame->player->x] == ENEMY)
		frame->status = FAILURE;
	else if ((frame->list)[frame->player->y][frame->player->x] == GOAL)
	{
		if (search(frame->list, COLLECTION) == 0)
			frame->status = CLEAR;
	}
}

void	set_direction(t_frame *frame, int x, int y)
{
	int			tmp;
	t_player	*player;

	if (ISBONUS == 0 || frame == NULL)
		return ;
	player = frame->player;
	tmp = player->direction;
	if (x > 0)
		player->direction = 2 * 0 + player->direction % 2;
	else if (x < 0)
		player->direction = 2 * 1 + player->direction % 2;
	else if (y > 0)
		player->direction = 2 * 2 + player->direction % 2;
	else if (y < 0)
		player->direction = 2 * 3 + player->direction % 2;
	if (tmp != player->direction)
		repaint(frame);
}
