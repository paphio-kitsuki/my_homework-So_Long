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

static t_image		**g_images;

static void	set_image(t_frame *f, t_image *images[], int index)
{
	if (index == BACKGROUND)
		images[BACKGROUND] = create_empty_image(f, f->width, f->height);
	if (index == ROAD)
		images[ROAD] = create_image(f, "./road.xpm");
	else if (index == PLAYER)
		images[PLAYER] = create_image(f, "./player.xpm");
	else if (index == WALL)
		images[WALL] = create_image(f, "./road.xpm");
	else if (index == GOAL)
		images[GOAL] = create_image(f, "./road.xpm");
	else if (index == COLLECTION)
		images[COLLECTION] = create_image(f, "./road.xpm");
}

int	images_create(t_frame *frame)
{
	size_t	count;

	g_images = (t_image **)malloc(sizeof(t_image *) * (LENGTH + 1));
	if (g_images == NULL)
		return (-1);
	count = 0;
	while (count <= LENGTH)
		g_images[count++] = NULL;
	count = 0;
	while (count < LENGTH)
	{
		set_image(frame, g_images, count);
		if (g_images[count] == NULL)
		{
			images_destroy(frame);
			return (-1);
		}
		count ++;
	}
	return (0);
}

t_image	*get_image(int index)
{
	return (g_images[index]);
}

void	images_destroy(t_frame *frame)
{
	size_t	count;

	count = 0;
	while (g_images[count] != NULL)
		delete_image(frame, g_images[count++]);
	free(g_images);
}
