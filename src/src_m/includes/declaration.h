/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:09:44 by jgo               #+#    #+#             */
/*   Updated: 2023/01/07 16:50:27 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATION_H
# define DECLARATION_H

# include "fdf.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MENU_WIDTH 350

# define MARGIN 50

# define X 0
# define Y 1
# define Z 2

typedef struct s_mlx t_mlx;
typedef struct s_img t_img;
typedef struct s_dot t_dot;
typedef struct s_map t_map;
typedef struct s_meta t_meta;
typedef struct s_color t_color;
typedef struct s_mouse t_mouse;
typedef struct s_key t_key;

struct s_mlx {
    void	*mlx;
    void	*win;
};

struct s_color {
	int	back_color;
	int	menu_color;
	int	text_color;
	int	peak_color;
	int	land_color;
	int	bottom_color;
};

struct s_img {
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct	s_dot {
	float	axis[3];
	int		color;
	t_bool	painted;
};

struct	s_mouse {
	t_bool	left_click;
	t_bool	right_click;
	t_dot	prev;
};

struct s_key {
	t_bool	dot;
	t_bool	line;
};

struct	s_map {
	t_dot	*dot;
	t_dot	max;
	t_dot	mid;
	t_dot	src;
	t_color	color;
	t_key	key;
	float	ratio;
	float	z_divisor;
	int		z_min;
	int	total_len;
	float	angle[3];
	float	scale;
};

struct s_meta {
    t_mlx   mlx;
	t_img	img;
	t_map	map;
	t_mouse mouse;
};

// debug

void	print_dot(t_dot *dot, int total_len);

#endif