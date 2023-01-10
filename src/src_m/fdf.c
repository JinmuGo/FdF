/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:14:46 by jgo               #+#    #+#             */
/*   Updated: 2023/01/10 19:49:41 by jgo              ###   ########.fr       */
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

void	print_dot(t_dot *dot, int total_len)
{
	for(int i = 0; i < total_len; i++)
	{
		printf(" X: %f", dot[i].axis[X]);
		printf(" Y: %f", dot[i].axis[Y]);
		printf(" Z: %f i : %d\n", dot[i].axis[Z], i);
	}
}

void	init_axis(t_dot mid, t_dot *axis_arr)
{
	axis_arr[6] = mid;
	axis_arr[0].axis[X] = AXIS_OFFSET;
	axis_arr[1].axis[X] = -AXIS_OFFSET;
	axis_arr[0].color = AXIS_X_COLOR;
	axis_arr[1].color = AXIS_X_COLOR;
	axis_arr[2].axis[Y] = AXIS_OFFSET;
	axis_arr[3].axis[Y] = -AXIS_OFFSET;
	axis_arr[2].color = AXIS_Y_COLOR;
	axis_arr[3].color = AXIS_Y_COLOR;
	axis_arr[4].axis[Z] = AXIS_OFFSET;
	axis_arr[5].axis[Z] = -AXIS_OFFSET;
	axis_arr[4].color = AXIS_Z_COLOR;
	axis_arr[5].color = AXIS_Z_COLOR;
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
	meta->map.ratio = meta->map.max.axis[Z] / meta->map.max.axis[X];
	if (meta->map.ratio > 0.5)
		meta->map.z_divisor = meta->map.ratio * 20;
	else
		meta->map.z_divisor = 1;
	init_axis(meta->map.mid, meta->map.axis);
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
	// atexit(mem_leaks);
	if (ac != 2)
		err_terminate_process(ERR_ARGS);
	if (init_fd < 2)
		err_terminate_process(ERR_PATH_OPEN);
	input_process(&meta.map, av[1] ,init_fd);
	init_metadata(&meta);
	draw_process(&meta, TRUE);
	draw_process(&meta, FALSE);
	// print_dot(meta.map.dot, meta.map.total_len);
	hook_init(&meta);
	key_hooks(&meta);
	mouse_hooks(&meta);
	// mlx_loop_hook() 지구본이 빙글빙글 돌아가는 걸 만들자! 
	mlx_loop(meta.mlx.mlx);
	free(meta.map.dot);
	return (EXIT_SUCCESS);
}