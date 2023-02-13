/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitsuki <kitsuki@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:08:23 by kitsuki           #+#    #+#             */
/*   Updated: 2023/02/11 16:08:23 by kitsuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define UINT			unsigned int
# define UCHAR			unsigned char

# define DESTROY_NOTIFY			17
# define CLIENT_MESSAGE			33

# define NOEVENT_MASK			0
# define STRUCTURE_NOTIFY_MASK	1L<<17

# define W						119
# define A						97
# define S						115
# define D						100

# define LEFT					65361
# define UP						65362
# define RIGHT					65363
# define DOWN					65364

# define ESCAPE					65307

# define WIDTH					50
# define HEIGHT					50

# define ROAD					0
# define PLAYER					1
# define WALL					2
# define GOAL					3
# define COLLECTION				4
# define LENGTH					5

typedef struct s_image
{
	void	*image;
	char	*url;
	int		bpp;
	int		length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_object
{
	int		x;
	int		y;
	t_image	*image;
}		t_object;

typedef struct s_list
{
	t_object		*content;
	struct s_list	*next;
}					t_list;

typedef struct s_frame
{
	void	*mlx;
	void	*win;
	t_list	*list;
}			t_frame;

int			repaint(t_frame *frame);
t_image		*create_image(t_frame *f, char *url);
t_object	*create_object(int x, int y, t_image *image);
void		delete_object(t_frame *frame, t_object *object);
void		delete_image(t_frame *frame, t_image *image);
void		images_destroy(t_frame *frame);
int			images_create(t_frame *frame);
t_image		*get_image(int index);
t_list		*ft_lstnew(t_object *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		lstdelone(t_frame *f, void (*del)(t_object *));
void		ft_lstclear(t_frame *f, void (*del)(t_object *));
void		ft_lstiter(t_list *lst, void (*f)(t_object *));

#endif