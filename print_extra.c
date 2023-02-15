/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:13:37 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/15 15:13:37 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	printstr_scale(t_frame *frame, char *str, int color, int size);
static void	print_failure(t_frame *frame);
static void	print_clear(t_frame *frame);
static void	adjust_window(t_frame *frame);

static int	g_x;
static int	g_y;

void	print_extra(t_frame *frame, char *str)
{
	if (frame->status == FAILURE)
		print_failure(frame);
	else
	{
		adjust_window(frame);
		if (frame->status == CLEAR)
			print_clear(frame);
	}
	if (str != NULL)
	{
		g_x = get_framewidth(frame) - 200;
		g_y = get_frameheight(frame) - 100;
		printstr_scale(frame, MOVE_STR, STREDGECOLOR, 5);
		printstr_scale(frame, str, STREDGECOLOR, 5);
		printstr_scale(frame, MOVE_STR, STRCOLOR, 2);
		printstr_scale(frame, str, STRCOLOR, 2);
	}
}

static void	printstr_scale(t_frame *frame, char *s, int color, int size)
{
	int	i;
	int	j;

	if (frame == NULL || s == NULL || size <= 0)
		return ;
	i = - (size - 1) / 2;
	if (size % 2 == 0)
		i --;
	while (i <= (size - 1) / 2)
	{
		j = - (size - 1) / 2;
		while (j <= (size - 1) / 2)
		{
			mlx_string_put(frame->mlx, frame->win, g_x + i, g_y + j, color, s);
			j ++;
		}
		i ++;
	}
}

static void	print_failure(t_frame *frame)
{
	char	*str;
	t_image	*background;

	str = "Oops, You Got The Eternal Life...";
	background = frame->images[BACKGROUND];
	add_color_all(background, FAILURE_COLOR);
	adjust_window(frame);
	g_x = get_framewidth(frame) / 2 - 100;
	g_y = get_frameheight(frame) / 2 - 10;
	printstr_scale(frame, str, STREDGECOLOR, 5);
	printstr_scale(frame, str, STRCOLOR, 2);
}

static void	print_clear(t_frame *frame)
{
	char	*str;

	str = "Complete! You Are A Super Astronaut!";
	mlx_get_screen_size(frame->mlx, &g_x, &g_y);
	g_x = get_framewidth(frame) / 2 - 100;
	g_y = get_frameheight(frame) / 2 - 10;
	printstr_scale(frame, str, STREDGECOLOR, 5);
	printstr_scale(frame, str, STRCOLOR, 2);
}

static void	adjust_window(t_frame *frame)
{
	int		x;
	int		y;
	t_image	*bgd;

	x = - frame->player->x * WIDTH + (get_framewidth(frame) - WIDTH) / 2;
	if (frame->width <= get_framewidth(frame) / WIDTH || x > 0)
		x = 0;
	else if (x < - frame->width * WIDTH + get_framewidth(frame))
		x = - frame->width * WIDTH + get_framewidth(frame);
	y = - frame->player->y * HEIGHT + (get_frameheight(frame) - HEIGHT) / 2;
	if (frame->height <= get_frameheight(frame) / HEIGHT || y > 0)
		y = 0;
	else if (y < - frame->height * HEIGHT + get_frameheight(frame))
		y = - frame->height * HEIGHT + get_frameheight(frame);
	bgd = frame->images[BACKGROUND];
	mlx_put_image_to_window(frame->mlx, frame->win, bgd->image, x, y);
}
