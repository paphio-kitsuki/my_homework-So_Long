/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:26:52 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/12 19:26:52 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_image(t_frame *f, t_image *images[], int index)
{
	if (index == BACKGROUND)
		f->images[BACKGROUND] = create_empty_image(f, f->width, f->height);
	if (index == ROAD)
		f->images[ROAD] = create_image(f, "./images/road.xpm");
	else if (index == PLAYER)
		f->images[PLAYER] = create_image(f, "./images/player.xpm");
	else if (index == WALL)
		f->images[WALL] = create_image(f, "./images/wall.xpm");
	else if (index == GOAL)
		f->images[GOAL] = create_image(f, "./images/goal.xpm");
	else if (index == COLLECTION)
		f->images[COLLECTION] = create_image(f, "./images/collection.xpm");
	else if (index == ENEMY)
		f->images[ENEMY] = create_image(f, "./images/enemy.xpm");
}

int	images_create(t_frame *frame)
{
	size_t	count;

	frame->images = (t_image **)malloc(sizeof(t_image *) * (LENGTH + 1));
	if (frame->images == NULL)
		return (-1);
	count = 0;
	while (count < LENGTH)
	{
		frame->images[count + 1] = NULL;
		set_image(frame, frame->images, count);
		if (frame->images[count] == NULL)
		{
			images_destroy(frame);
			return (-1);
		}
		count ++;
	}
	return (0);
}

void	images_destroy(t_frame *frame)
{
	size_t	count;

	count = 0;
	while (frame->images[count] != NULL)
		delete_image(frame, frame->images[count++]);
	free(frame->images);
	frame->images = NULL;
}
