/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:14:46 by jgo               #+#    #+#             */
/*   Updated: 2023/01/12 21:04:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "error.h"
#include "declaration.h"
#include "input.h"
#include "color.h"
#include "draw.h"
#include "event.h"
#include "hooks.h"
#include "utils.h"

void	print_dot(t_dot *dot, int total_len)
{
	for(int i = 0; i < total_len; i++)
	{
		printf(" X: %f", dot[i].axis[X]);
		printf(" Y: %f", dot[i].axis[Y]);
		printf(" Z: %f i : %d\n", dot[i].axis[Z], i);
		printf(" color: %x\n", dot[i].color);
	}
}

void	mem_leaks(void)
{
	system("leaks fdf");
}

int	main(int ac, char **av)
{
	const char	*path = av[1];
	const int	init_fd = open(path, O_RDONLY);
	t_meta		meta;

	// atexit(mem_leaks);
	input_error_handler(ac, init_fd);
	input_process(&meta.map, path ,init_fd);
	init_metadata(&meta);
	draw_process(&meta, TRUE);
	hooks(&meta);
	// print_dot(meta.map.dot, meta.map.total_len);
	mlx_loop(meta.mlx.mlx);
	free(meta.map.dot);
	return (EXIT_SUCCESS);
}