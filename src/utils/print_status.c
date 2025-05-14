/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:22:56 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 17:17:22 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "color.h"
#include "utils.h"

void	print_angle(t_mlx mlx, int *margin, float angle[3])
{
	margin[B] += 60;
	print_str(mlx, margin[L], margin[B], "x angle : ");
	print_nbr(mlx, margin[L] + 100, margin[B], angle[Z]);
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "y angle : ");
	print_nbr(mlx, margin[L] + 100, margin[B], angle[Y]);
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "z angle : ");
	print_nbr(mlx, margin[L] + 100, margin[B], angle[Z]);
}

void	print_mod(t_mlx mlx, int *margin, t_key key)
{
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "dot : ");
	print_str(mlx, margin[L] + 60, margin[B], make_bool_str(key.dot));
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "line : ");
	print_str(mlx, margin[L] + 70, margin[B], make_bool_str(key.line));
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "extra_line_L : ");
	print_str(mlx, margin[L] + 150, margin[B], make_bool_str(key.extra_line));
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "extra_line_R : ");
	print_str(mlx, margin[L] + 150, margin[B], make_bool_str(key.extra_line2));
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "axis : ");
	print_str(mlx, margin[L] + 70, margin[B], make_bool_str(key.axis));
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "planet : ");
	print_str(mlx, margin[L] + 90, margin[B], make_bool_str(key.planet));
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "rotate : ");
	print_str(mlx, margin[L] + 90, margin[B], make_bool_str(key.rotate));
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "shift : ");
	print_str(mlx, margin[L] + 80, margin[B], make_bool_str(key.shift));
}

void	print_keymap(t_mlx mlx, int *margin)
{
	print_str(mlx, margin[L], margin[B], "KEYMAP");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "1 : dot ON/OFF");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "2 : line ON/OFF");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "3 : axis ON/OFF");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "E : extra_line_L ON/OFF");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "D : extra_line_R ON/OFF");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "P : planet mode");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "R : rotate ON/OFF");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "Z/X/A/S/Q/W : rotate");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "+/- : scale");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "J/K : scale");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "I/V : view");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "F : refresh");
	margin[B] += 30;
	print_str(mlx, margin[L], margin[B], "ESC : exit");
}

void	print_status(t_meta *meta)
{
	int	margin[4];

	margin[T] = 30;
	margin[B] = 30;
	margin[L] = 30;
	margin[R] = 30;
	print_str(meta->mlx, margin[L], margin[B], "MAP INFO");
	margin[B] += 30;
	print_str(meta->mlx, margin[L], margin[B], "map name : ");
	print_str(meta->mlx, margin[L] + 110, margin[B], meta->map.name);
	margin[B] += 50;
	print_str(meta->mlx, margin[L], margin[B], "MOD STATUS");
	print_mod(meta->mlx, margin, meta->key);
	margin[B] += 50;
	print_keymap(meta->mlx, margin);
}
