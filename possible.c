/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:23:33 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/14 04:23:33 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	start(int ***dst, int **src, int width);
static void	loop_search(int **dst, int dfs);
static void	set_arround(int **dst, int x, int y);
static int	search_and_check(int **dst, int **src);

int	is_possible(int **map)
{
	int	length;
	int	out;
	int	**tmp;

	length = 0;
	while (*(map + length) != NULL)
		length ++;
	tmp = (int **)malloc(sizeof (int *) * (length + 1));
	if (tmp == NULL)
		return (-1);
	length = 0;
	while (map[0][length] != NONE)
		length ++;
	start(&tmp, map, length);
	if (tmp == NULL)
		return (-1);
	out = search_and_check(tmp, map);
	clear_list(&tmp);
	return (out);
}

static void	start(int ***dst, int **src, int width)
{
	int	x;
	int	y;

	y = 0;
	while (*(src + y) != NULL)
	{
		*(*dst + y) = (int *)malloc(sizeof (int) * (width + 1));
		if (*(*dst + y) == NULL)
		{
			clear_list(dst);
			return ;
		}
		x = 0;
		while (src[y][x] != NONE)
		{
			if (src[y][x] == WALL)
				(*dst)[y][x] = -1;
			else
				(*dst)[y][x] = (src[y][x] == PLAYER) & 1;
			x ++;
		}
		(*dst)[y][x] = -2;
		y ++;
	}
	*(*dst + y) = NULL;
}

static int	search_and_check(int **dst, int **src)
{
	int	x;
	int	y;

	loop_search(dst, 1);
	y = 0;
	while (*(dst + y) != NULL)
	{
		x = 0;
		while (dst[y][x] != NONE)
		{
			if (src[y][x] == GOAL || src[y][x] == COLLECTION)
			{
				if (dst[y][x] == 0)
					return (0);
			}
			x ++;
		}
		y ++;
	}
	return (1);
}

static void	loop_search(int **dst, int bfs)
{
	int	x;
	int	y;
	int	flag;

	flag = 0;
	y = 0;
	while (*(dst + y) != NULL)
	{
		x = 0;
		while (dst[y][x] != NONE)
		{
			if (dst[y][x] == bfs)
			{
				set_arround(dst, x, y);
				flag = 1;
			}
			x ++;
		}
		y ++;
	}
	if (flag == 0)
		return ;
	loop_search(dst, bfs + 1);
}

static void	set_arround(int **dst, int x, int y)
{
	if (dst[y + 1][x] == 0)
		dst[y + 1][x] = dst[y][x] + 1;
	if (dst[y - 1][x] == 0)
		dst[y - 1][x] = dst[y][x] + 1;
	if (dst[y][x + 1] == 0)
		dst[y][x + 1] = dst[y][x] + 1;
	if (dst[y][x - 1] == 0)
		dst[y][x - 1] = dst[y][x] + 1;
}
