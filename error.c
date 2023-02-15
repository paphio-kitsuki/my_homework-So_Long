/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:40:29 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/14 12:40:29 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int index, t_frame *frame)
{
	ft_putstrln("Error", STDERR);
	if (index == ARGUMENT)
		ft_putstrln("Too Many Or Few Arguments.", STDERR);
	else if (index == FRAMECREATE)
		ft_putstrln("Failed To Allocate A Frame.", STDERR);
	else if (index == MLXCREATE)
		ft_putstrln("Failed To Make A Mlx.", STDERR);
	else if (index == FILECASE)
		ft_putstrln("Path Or Mapcase Are Illegal.", STDERR);
	else if (index == NOTPOSSIBLE)
		ft_putstrln("There Are No Valid Routes.", STDERR);
	else if (index == IMAGECREATE)
		ft_putstrln("Failed To Make Images.", STDERR);
	else if (index == PLAYERCREATE)
		ft_putstrln("Failed To Allocate A Player.", STDERR);
	else if (index == WINCREATE)
		ft_putstrln("Failed To Make A Window.", STDERR);
	case_of_clear(index, frame);
	exit(0);
}

void	case_of_clear(int index, t_frame *frame)
{
	set_count(NULL);
	if (frame == NULL)
		return ;
	if (index >= DELETE_ALL)
		free(frame->title);
	if (index >= WINCREATE)
		free(frame->player);
	if (index >= PLAYERCREATE)
		images_destroy(frame);
	if (index >= NOTPOSSIBLE)
		clear_list(&(frame->list));
	if (index >= DELETE_ALL)
		mlx_destroy_window(frame->mlx, frame->win);
	if (index >= FILECASE)
		mlx_destroy_display(frame->mlx);
	if (index >= MLXCREATE)
		free(frame);
}
