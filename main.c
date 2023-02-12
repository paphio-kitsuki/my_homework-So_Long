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

t_frame	*frame;

int	exit_func(t_frame *param)
{
	printf("www");
	mlx_destroy_display(param->mlx);
	mlx_destroy_window(param->mlx, param->win);
	ft_lstclear(&param->list, delete_object);
	free(param);
	return (0);
}

int	key_notify(int button, t_frame *param)
{
	//printf("%p\n", param->list->content);
	if (param->list == NULL)
		return (-1);
	if (button == ESCAPE)
		exit_func(param);
	else if (button == A || button == LEFT)
		param->list->content->x -= 10;
	else if (button == D || button == RIGHT)
		param->list->content->x += 10;
	else if (button == W || button == UP)
		param->list->content->y -= 10;
	else if (button == S || button == DOWN)
		param->list->content->y += 10;
	repaint(param);
	return (0);
}

int	main(void)
{
	frame = (t_frame *)malloc(sizeof(t_frame));
	frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, 500, 500, "mlx 42");
	t_image	*image = create_image(frame, "./IMG_0159.xpm");
	frame->list = ft_lstnew(create_object(0, 0, image));
	paint(frame);
	mlx_hook(frame->win, CLIENT_MESSAGE, STRUCTURE_NOTIFY_MASK, exit_func, frame);
	mlx_key_hook(frame->win, key_notify, frame);
	mlx_expose_hook(frame->win, repaint, frame);
	mlx_loop(frame->mlx);
	printf("finish\n");
}
