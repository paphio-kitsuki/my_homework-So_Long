/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:05:58 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/12 02:05:58 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_image(t_frame *frame, t_image *image)
{
	mlx_destroy_image(frame->mlx, image->image);
	free(image);
}

void	clear_list(int	***lst)
{
	int	**tmp;

	tmp = *lst;
	while (*tmp != NULL)
	{
		free(*tmp);
		tmp++;
	}
	free(*lst);
	*lst = NULL;
}

int	exit_func(t_frame *param)
{
	case_of_clear(DELETE_ALL, param);
	exit(0);
	return (0);
}
