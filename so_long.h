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

# define DESTROY_NOTIFY	17

# define NOEVENT_MASK	0

# define W				119
# define A				97
# define S				115
# define D				100

# define LEFT			65361
# define UP				65362
# define RIGHT			65363
# define DOWN			65364

# define ESCAPE			65307

# define WIDTH			50
# define HEIGHT			50

typedef struct s_frame
{
	void	*mlx;
	void	*win;
}			t_frame;

typedef struct s_object
{
	int	x;
	int	y;
}		t_object;

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}			t_image;

#endif