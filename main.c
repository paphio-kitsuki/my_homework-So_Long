/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:09:04 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/12 01:00:24 by kitsuki          ###   ########.fr       */
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

	frame = malloc(sizeof(t_frame));
	frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, 500, 500, "mlx 42");
	int x, y;
	void	*image = mlx_xpm_file_to_image(frame->mlx, "./IMG_0159.xpm", &x, &y);
	mlx_put_image_to_window(frame->mlx, frame->win, image, 0, 0);
	mlx_hook(frame->win, DESTROY_NOTIFY, NOEVENT_MASK, exit_func, frame);
	mlx_key_hook(frame->win, key_notify, frame);
	mlx_loop(frame->mlx);
}
