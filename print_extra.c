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

void	print_extra(t_frame *frame, char *str)
{
	if (str != NULL)
	{
		printstr_with_scale(frame, str, STREDGECOLOR, 7);
		printstr_with_scale(frame, str, STRCOLOR, 2);
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
			mlx_string_put(f->mlx, f->win, STRX + i, STRY + j, color, str);
			j ++;
		}
		i ++;
	}
}