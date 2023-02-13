/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:09:04 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/12 02:43:10 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	exit_func(t_frame *param)
{
	images_destroy(param);
	clear_list(param->list);
	free(param->player);
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param);
	exit(0);
	return (0);
}

int	key_notify(int button, t_frame *param)
{
	if (param->list == NULL)
		return (-1);
	if (button == ESCAPE)
		exit_func(param);
	else if (button == A || button == LEFT)
		move(param, param->player, -1, 0);
	else if (button == D || button == RIGHT)
		move(param, param->player, 1, 0);
	else if (button == W || button == UP)
		move(param, param->player, 0, -1);
	else if (button == S || button == DOWN)
		move(param, param->player, 0, 1);
	repaint(param);
	return (0);
}

int	main(int argc, char *argv[])
{	
	t_frame	*frame;

	if (argc != 2)
		return (0);
	frame = (t_frame *)malloc(sizeof(t_frame));
	frame->mlx = mlx_init();
	frame->list = read_map(argv[1], &frame->width, &frame->height);
	images_create(frame);
	frame->player = create_player(frame->list, frame->height);
	frame->win = mlx_new_window(frame->mlx, frame->width * WIDTH, frame->height * HEIGHT, "mlx 42");
	mlx_hook(frame->win, CLIENT_MESSAGE, 1L<<17, exit_func, frame);
	mlx_key_hook(frame->win, key_notify, frame);
	mlx_expose_hook(frame->win, repaint, frame);
	printf("ok\n");
	mlx_loop(frame->mlx);
}
