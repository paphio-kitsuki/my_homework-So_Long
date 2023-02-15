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
	t_player	*player;

	if (frame == NULL || frame->status != PLAYING)
		return (0);
	player = frame->player;
	player->x += x;
	player->y += y;
	set_direction(player, x, y);
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
		(frame->list)[frame->player->y][frame->player->x] = ROAD;
	else if ((frame->list)[frame->player->y][frame->player->x] == ENEMY)
		frame->status = FAILURE;
	else if ((frame->list)[frame->player->y][frame->player->x] == GOAL)
	{
		if (search(frame->list, COLLECTION) == 0)
			frame->status = CLEAR;
	}
}

void	set_direction(t_player *player, int x, int y)
{
	if (ISBONUS == 0 || player == NULL)
		return ;
	if (x > 0)
		player->direction = 2 * 0 + player->direction % 2;
	else if (x < 0)
		player->direction = 2 * 1 + player->direction % 2;
	else if (y > 0)
		player->direction = 2 * 2 + player->direction % 2;
	else if (y < 0)
		player->direction = 2 * 3 + player->direction % 2;
}
