/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:48:21 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/14 05:48:21 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search(int **list, int target)
{
	int	x;
	int	y;

	y = 0;
	while (*(list + y) != NULL)
	{
		x = 0;
		while (list[y][x] != NONE)
		{
			if (list[y][x] == target)
				return (1);
			x ++;
		}
		y ++;
	}
	return (0);
}
