/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:09:04 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/16 19:24:47 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		key_notify(int button, t_frame *param);
static t_frame	*setup_frame(char *address);
static void		set_window(t_frame *frame);
static void		restart(t_frame *frame);

int	main(int argc, char *argv[])
{
	t_frame	*frame;

	if (argc != 2)
		error(ARGUMENT, NULL);
	frame = setup_frame(argv[1]);
	mlx_hook(frame->win, CLIENT_MESSAGE, 1L << 17, exit_func, frame);
	mlx_key_hook(frame->win, key_notify, frame);
	mlx_expose_hook(frame->win, repaint, frame);
	mlx_loop_hook(frame->mlx, pass_time, frame);
	mlx_loop(frame->mlx);
}

static t_frame	*setup_frame(char *address)
{
	t_frame	*frame;

	frame = (t_frame *)malloc(sizeof(t_frame));
	if (frame == NULL)
		error(FRAMECREATE, NULL);
	frame->mlx = mlx_init();
	if (frame->mlx == NULL)
		error(MLXCREATE, frame);
	frame->list = read_map(address, &frame->width, &frame->height);
	if (frame->list == NULL)
		error(FILECASE, frame);
	if (is_possible(frame->list) <= 0)
		error(NOTPOSSIBLE, frame);
	if (images_create(frame) < 0)
		error(IMAGECREATE, frame);
	frame->player = create_player(frame->images[PLAYER], frame->list);
	if (frame->player == NULL)
		error(PLAYERCREATE, frame);
	set_window(frame);
	frame->status = PLAYING;
	frame->filepath = address;
	if (ISBONUS > 0)
		set_count(ft_itoa(0));
	return (frame);
}

static int	key_notify(int button, t_frame *param)
{
	int	ismoved;

	ismoved = 0;
	if (button == ESCAPE)
		exit_func(param);
	else if (button == R && param->status != PLAYING && ISBONUS > 0)
		restart(param);
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

static void	set_window(t_frame *frame)
{
	int	width;
	int	height;

	get_framesize(frame, &width, &height);
	frame->win = mlx_new_window(frame->mlx, width, height, TITLE);
	if (frame->win == NULL)
		error(WINCREATE, frame);
}

static void	restart(t_frame *frame)
{
	int	x;
	int	y;

	x = frame->player->firstx;
	y = frame->player->firsty;
	free(frame->player);
	frame->list[y][x] = PLAYER;
	x = -1;
	while (++x < frame->width)
	{
		y = -1;
		while (++y < frame->height)
		{
			if (frame->list[y][x] == COLLECTED)
				frame->list[y][x] = COLLECTION;
		}
	}
	frame->player = create_player(frame->images[PLAYER], frame->list);
	if (frame->player == NULL)
	{
		mlx_destroy_window(frame->mlx, frame->win);
		error(PLAYERCREATE, frame);
	}
	set_count(ft_itoa(0));
	frame->status = PLAYING;
}
