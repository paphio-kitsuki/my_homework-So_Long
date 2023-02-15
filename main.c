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

static int		key_notify(int button, t_frame *param);
static t_frame	*setup_frame(char *address);
static void		set_window(t_frame *frame);

int	main(int argc, char *argv[])
{
	t_frame	*frame;

	if (argc != 2)
		error(ARGUMENT, NULL);
	frame = setup_frame(argv[1]);
	mlx_hook(frame->win, CLIENT_MESSAGE, 1L << 17, exit_func, frame);
	mlx_key_hook(frame->win, key_notify, frame);
	mlx_expose_hook(frame->win, repaint, frame);
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
	return (frame);
}

int	exit_func(t_frame *param)
{
	case_of_clear(DELETE_ALL, param);
	exit(0);
	return (0);
}

static int	key_notify(int button, t_frame *param)
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

static void	set_window(t_frame *frame)
{
	int		width;
	int		height;

	frame->title = ft_substr(TITLE, 0, ft_strlen(TITLE));
	if (frame->title == NULL)
		error(WINCREATE, frame);
	if (frame->width > LIMIT_W / WIDTH)
		width = LIMIT_W / WIDTH;
	else
		width = frame->width;	
	if (frame->height > LIMIT_H / HEIGHT)
		height = LIMIT_H / HEIGHT;
	else
		height = frame->height;
	width *= WIDTH;
	height *= HEIGHT;
	frame->win = mlx_new_window(frame->mlx, width, height, frame->title);
	if (frame->win == NULL)
	{
		free(frame->title);
		error(WINCREATE, frame);
	}
}