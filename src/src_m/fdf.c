/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:14:46 by jgo               #+#    #+#             */
/*   Updated: 2023/01/05 06:31:10 by jgo              ###   ########.fr       */
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

void	print_dot(t_dot *dot, size_t total_len)
{
	for(size_t i = 0; i < total_len; i++)
	{
		printf(" X: %f", dot[i].axis[X]);
		printf(" Y: %f", dot[i].axis[Y]);
		printf(" Z: %f i : %zu\n", dot[i].axis[Z], i);
	}
}

void	init_metadata(t_meta *meta)
{
	// below input control
	// maybe key down etc)......
	meta->mlx.mlx = mlx_init();
	meta->mlx.win = mlx_new_window(meta->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "jgo FdF");
	meta->img.img = mlx_new_image(meta->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	meta->img.addr = mlx_get_data_addr(meta->img.img, \
		&meta->img.bits_per_pixel, &meta->img.line_length, &meta->img.endian);
}

void	mem_leaks(void)
{
	system("leaks fdf");
}

int	main(int ac, char **av)
{
	const int	init_fd = open(av[1], O_RDONLY);
	t_meta		meta;
	// init_error_handler(); ?
	atexit(mem_leaks);
	if (ac != 2)
		err_terminate_process(ERR_ARGS);
	if (init_fd < 2)
		err_terminate_process(ERR_PATH_OPEN);
	input_process(&meta.map, av[1] ,init_fd);
	init_metadata(&meta);
	draw_process(&meta);
	print_dot(meta.map.dot, meta.map.total_len);
	mlx_hook(meta.mlx.win, KEY_PRESS, 0, key_press, &meta);
	// mlx_loop_hook() 지구본이 빙글빙글 돌아가는 걸 만들자! 
	mlx_loop(meta.mlx.mlx);
	return (EXIT_SUCCESS);
}