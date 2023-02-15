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

static void	printstr_with_scale(t_frame *f, char *str, int color, int size);
static void	print_failure(t_frame *f);
static void	print_clear(t_frame *f);

static int	g_x;
static int	g_y;

void	print_extra(t_frame *f, char *str)
{
	t_image	*background;

	background = f->images[BACKGROUND];
	if (f->status == FAILURE)
		print_failure(f);
	else
	{
		mlx_put_image_to_window(f->mlx, f->win, background->image, 0, 0);
		if (f->status == CLEAR)
			print_clear(f);
	}
	if (str != NULL)
	{
		mlx_get_screen_size(f->mlx, &g_x, &g_y);
		g_x -= 200;
		g_y -= 100;
		printstr_with_scale(f, MOVE_STR, STREDGECOLOR, 5);
		printstr_with_scale(f, str, STREDGECOLOR, 5);
		printstr_with_scale(f, MOVE_STR, STRCOLOR, 2);
		printstr_with_scale(f, str, STRCOLOR, 2);
	}
}

static void	printstr_with_scale(t_frame *f, char *str, int color, int size)
{
	int	i;
	int	j;

	if (f == NULL || str == NULL || size <= 0)
		return ;
	i = - (size - 1) / 2;
	if (size % 2 == 0)
		i --;
	while (i <= (size - 1) / 2)
	{
		j = - (size - 1) / 2;
		while (j <= (size - 1) / 2)
		{
			mlx_string_put(f->mlx, f->win, g_x + i, g_y + j, color, str);
			j ++;
		}
		i ++;
	}
}

static void	print_failure(t_frame *f)
{
	const char	*str = "Oops, You Got The Eternal Life...";
	t_image		*background;

	background = f->images[BACKGROUND];
	add_color_all(background, FAILURE_COLOR);
	mlx_put_image_to_window(f->mlx, f->win, background->image, 0, 0);
	mlx_get_screen_size(f->mlx, &g_x, &g_y);
	g_x = g_x / 2 - 100;
	g_y = g_y / 2 - 10;
	printstr_with_scale(f, MOVE_STR, STREDGECOLOR, 5);
	printstr_with_scale(f, str, STREDGECOLOR, 5);
	printstr_with_scale(f, MOVE_STR, STRCOLOR, 2);
	printstr_with_scale(f, str, STRCOLOR, 2);
}

static void	print_clear(t_frame *f)
{
	const char	*str = "Complete! You Are A Super Astronaut!";

	mlx_get_screen_size(f->mlx, &g_x, &g_y);
	g_x = g_x / 2 - 100;
	g_y = g_y / 2 - 10;
	printstr_with_scale(f, str, STREDGECOLOR, 5);
	printstr_with_scale(f, str, STRCOLOR, 2);
}
