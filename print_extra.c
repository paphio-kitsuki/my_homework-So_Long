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
		get_framesize(frame, &g_x, &g_y);
		g_x -= 150;
		g_y -= 50;
		printstr_scale(frame, MOVE_STR, STREDGECOLOR, 4);
		printstr_scale(frame, MOVE_STR, STRCOLOR, 2);
		g_x += 80;
		printstr_scale(frame, str, STREDGECOLOR, 4);
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
	get_framesize(frame, &g_x, &g_y);
	g_x = g_x / 2 - 100;
	g_y /= 2;
	printstr_scale(frame, str, STREDGECOLOR, 4);
	printstr_scale(frame, str, STRCOLOR, 2);
}

static void	print_clear(t_frame *frame)
{
	char	*str;
	t_image	*background;

	str = "Complete! You Are A Super Astronaut!";
	background = frame->images[BACKGROUND];
	add_color_all(background, CLEAR_COLOR);
	adjust_window(frame);
	get_framesize(frame, &g_x, &g_y);
	g_x = g_x / 2 - 110;
	g_y /= 2;
	printstr_scale(frame, str, STREDGECOLOR, 4);
	printstr_scale(frame, str, STRCOLOR, 2);
}

static void	adjust_window(t_frame *frame)
{
	int		x;
	int		y;
	int		width;
	int		height;
	t_image	*bgd;

	get_framesize(frame, &width, &height);
	x = -frame->player->x * WIDTH + (width - WIDTH) / 2;
	if (frame->width <= width / WIDTH || x > 0)
		x = 0;
	else if (x < -frame->width * WIDTH + width)
		x = -frame->width * WIDTH + width;
	y = -frame->player->y * HEIGHT + (height - HEIGHT) / 2;
	if (frame->height <= height / HEIGHT || y > 0)
		y = 0;
	else if (y < -frame->height * HEIGHT + height)
		y = -frame->height * HEIGHT + height;
	bgd = frame->images[BACKGROUND];
	mlx_put_image_to_window(frame->mlx, frame->win, bgd->image, x, y);
}
