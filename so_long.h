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
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define UINT			unsigned int
# define UCHAR			unsigned char

# define STDOUT			1
# define STDERR			2

# define DESTROY_NOTIFY	17
# define CLIENT_MESSAGE	33

# define NOEVENT_MASK	0

# define TITLE			"42_so_long"

# define W				119
# define A				97
# define S				115
# define D				100

# define LEFT			65361
# define UP				65362
# define RIGHT			65363
# define DOWN			65364

# define ESCAPE			65307

# define WIDTH			80
# define HEIGHT			80

# define TRANSPARENCY	0xFF

# define NONE			-1
# define BACKGROUND		0
# define ROAD			1
# define PLAYER			2
# define WALL			3
# define GOAL			4
# define COLLECTION		5
# define LENGTH			6

# define BUFFER_SIZE	10

# define ARGUMENT		0
# define FRAMECREATE	1
# define MLXCREATE		2
# define FILECASE		3
# define NOTPOSSIBLE	4
# define IMAGECREATE	5
# define PLAYERCREATE	6
# define WINCREATE		7
# define DELETE_ALL		8

typedef struct s_image
{
	void	*image;
	char	*path;
	int		bpp;
	int		length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_player
{
	int		x;
	int		y;
	t_image	*image;
	int		move_count;
}			t_player;

typedef struct s_frame
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			**list;
	t_player	*player;
}			t_frame;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

typedef struct s_memo
{
	char			*memo;
	int				fd;
	size_t			stack;
	struct s_memo	*next;
}					t_memo;

void		error(int index, t_frame *frame);
void		case_of_clear(int index, t_frame *frame);
int			**read_map(const char *path, int *width, int *height);
int			is_possible(int **map);
int			search(int **list, int target);
int			move(t_frame *frame, int x, int y);
void		action(t_frame *frame);
int			exit_func(t_frame *param);
int			repaint(t_frame *frame);
t_image		*create_image(t_frame *f, char *path);
t_image		*create_empty_image(t_frame *f, int width, int height);
t_player	*create_player(int **map);
void		delete_image(t_frame *frame, t_image *image);
void		clear_list(int	***lst);
void		images_destroy(t_frame *frame);
int			images_create(t_frame *frame);
t_image		*get_image(int index);
void		draw_image(t_image *dst, t_image *src, int x, int y);
void		draw_player(t_image *image, t_player *player);
void		put_pixel(t_image *image, int x, int y, UINT color);
UINT		get_pixel(t_image *image, int x, int y);
UCHAR		get_alpha(UINT argb);
UCHAR		get_red(UINT argb);
UCHAR		get_blue(UINT argb);
UCHAR		get_green(UINT argb);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
char		*ft_itoa(int n);
t_list		*ft_lstnew(char *str);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *newone);
void		ft_lstclear(t_list **lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstfix(t_list **lst);
char		*get_next_line(int fd);
char		*search_newline(char *s);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *str, unsigned int start, size_t len);
int			memo_join(t_memo *s1, char *s2);
void		ft_putstrln(char *s, int fd);
void		ft_putstr(char *s, int fd);

#endif