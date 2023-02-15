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
	static struct timespec			time;
	static unsigned long long int	past_count = 0;
	unsigned long long int			now_count;

	if (frame->status != PLAYING)
		return (0);
	clock_gettime(CLOCK_REALTIME, &time);
	now_count = time.tv_sec * 1000 * 1000 * 1000 + time.tv_nsec;
	if (now_count - past_count > 500 * 1000 * 1000)
	{
		if (frame->player->direction % 2 == 0)
			frame->player->direction += 1;
		else
			frame->player->direction -= 1;
		past_count = now_count;
		repaint(frame);
	}
	return (0);
}
