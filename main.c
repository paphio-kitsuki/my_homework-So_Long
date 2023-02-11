/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:09:04 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/11 16:23:39 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_func(int button, t_frame *param)
{
	mlx_destroy_display(param->mlx);
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
}

int	key_notify(int button, int x, int y, t_frame *param)
{
	printf("%d\n", button);
}

int	main()
{
	t_frame	*frame;

	frame = malloc(sizeof(t_frame));
	frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, 500, 500, "mlx 42");
	//mlx_mouse_hook(frame->win, exit_func, frame);
	mlx_hook(frame->win, DESTROY_NOTIFY, NOEVENT_MASK, exit_func, frame);
	mlx_key_hook(frame->win, key_notify, frame);
	mlx_loop(frame->mlx);
	free(frame);
}
