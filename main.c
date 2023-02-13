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

int	exit_func(t_frame *param)
{
	images_destroy(param);
	clear_list(&(param->list));
	free(param->player);
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param);
	exit(0);
	return (0);
}

int	key_notify(int button, t_frame *param)
{
	int	ismoved;

	if (param->list == NULL)
		return (-1);
	ismoved = 0;
	if (button == ESCAPE)
		exit_func(param);
	else if (button == A || button == LEFT)
		ismoved = move(param, -1, 0);
	else if (button == D || button == RIGHT)
		ismoved = move(param, 1, 0);
	else if (button == W || button == UP)
		ismoved = move(param, 0, -1);
	else if (button == S || button == DOWN)
		ismoved = move(param, 0, 1);
	if (ismoved > 0)
		action(param);
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
	int x = is_possible(frame->list);
	frame->player = create_player(frame->list);
	frame->win = mlx_new_window(frame->mlx, frame->width * WIDTH, frame->height * HEIGHT, "mlx 42");
	mlx_hook(frame->win, CLIENT_MESSAGE, 1L<<17, exit_func, frame);
	mlx_key_hook(frame->win, key_notify, frame);
	mlx_expose_hook(frame->win, repaint, frame);
	mlx_loop(frame->mlx);
}
