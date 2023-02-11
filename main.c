/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:09:04 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/12 01:27:20 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_func(int button, t_frame *param)
{
	mlx_destroy_display(param->mlx);
	mlx_destroy_window(param->mlx, param->win);
	free(param);
	exit(0);
}

int	key_notify(int button, int x, int y, t_frame *param)
{
	printf("%d\n", button);
	if (button == ESCAPE)
		exit_func(button, param);
}

int	main(void)
{
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, 500, 500, "mlx 42");
	t_image	*image = (t_image *)malloc(sizeof(t_image));
	image->image = mlx_xpm_file_to_image(frame->mlx, "./IMG_0159.xpm", &image->width, &image->height);
	image->addr = mlx_get_data_addr(image->image, &image->bpp, &image->length, &image->endian);
	add_image(image);
	mlx_hook(frame->win, DESTROY_NOTIFY, NOEVENT_MASK, exit_func, frame);
	mlx_key_hook(frame->win, key_notify, frame);
	mlx_expose_hook(frame->win, repaint, frame);
	mlx_loop(frame->mlx);
	printf("finish\n");
}
