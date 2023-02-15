/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:37:29 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/15 21:37:29 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>

int	pass_time(t_frame *frame)
{
	static struct timespec	time;
	static int				flag = 0;
	struct timespec			now;

	if (frame->status != PLAYING)
		return (0);
	if (flag == 0)
	{
		clock_gettime(CLOCK_REALTIME, &time);
		flag = 1;
	}
	clock_gettime(CLOCK_REALTIME, &now);
	if (now.tv_nsec > time.tv_nsec + 500 * 1000 * 1000)
	{
		if (frame->player->direction % 2 == 0)
			frame->player->direction += 1;
		else
			frame->player->direction -= 1;
		time = now;
	}
	return (0);
}
