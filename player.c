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

void	move(t_frame *frame, t_player *player, int x, int y)
{
	player->x += x;
	player->y += y;
	if (player->x < 0)
		player->x = 0;
	else if (player->x >= frame->width)
		player->x = frame->width - 1;
	else if (player->y < 0)
		player->y = 0;
	else if (player->y >= frame->height)
		player->y = frame->height - 1;
	if (frame->list[player->y][player->x] == WALL)
	{
		player->x -= x;
		player->y -= y;
	}
}
