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
	ft_lstclear(param, delete_object);
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
		param->list->content->x -= WIDTH;
	else if (button == D || button == RIGHT)
		param->list->content->x += WIDTH;
	else if (button == W || button == UP)
		param->list->content->y -= HEIGHT;
	else if (button == S || button == DOWN)
		param->list->content->y += HEIGHT;
	repaint(param);
	return (0);
}

int	main(void)
{	
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	frame->width = 500;
	frame->height = 500;
	frame->mlx = mlx_init();
	images_create(frame);
	frame->list = ft_lstnew(create_object(0, 0, get_image(PLAYER)));
	frame->win = mlx_new_window(frame->mlx, frame->width, frame->height, "mlx 42");
	mlx_hook(frame->win, CLIENT_MESSAGE, STRUCTURE_NOTIFY_MASK, exit_func, frame);
	mlx_key_hook(frame->win, key_notify, frame);
	mlx_expose_hook(frame->win, repaint, frame);
	mlx_loop(frame->mlx);
}
