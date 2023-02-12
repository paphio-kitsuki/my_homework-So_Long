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

void	delete_object(t_frame *frame, t_object *object)
{
	delete_image(frame, object->image);
	free(object);
}
