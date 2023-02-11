/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:09:04 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/12 02:23:53 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_func(int button, t_frame *param)
{
	mlx_destroy_display(param->mlx);
	mlx_destroy_window(param->mlx, param->win);
	ft_lstclear(&param->list, delete_object);
	free(param);
}

int	key_notify(int button, int x, int y, t_frame *param)
{
	printf("%d\n", button);
	if (button == ESCAPE)
		exit_func(button, param);
	else if (button == A || button == LEFT)
		param->list->content->x -= 10;
	else if (button == D || button == RIGHT)
		param->list->content->x += 10;
	else if (button == W || button == UP)
		param->list->content->y -= 10;
	else if (button == S || button == DOWN)
		param->list->content->y += 10;
	repaint(param);
}

int	main(void)
{
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	frame->mlx = mlx_init();
	frame->win = mlx_new_window(frame->mlx, 500, 500, "mlx 42");
	t_image	*image = create_image(frame, "./IMG_0159.xpm");
	printf("%p\n", image->image);
	frame->list = ft_lstnew(create_object(0, 0, image));
	printf("%p\n", frame->list->content);
	paint(frame);
	mlx_hook(frame->win, DESTROY_NOTIFY, NOEVENT_MASK, exit_func, frame);
	mlx_key_hook(frame->win, key_notify, frame);
	mlx_expose_hook(frame->win, repaint, frame);
	mlx_loop(frame->mlx);
	printf("finish\n");
}
