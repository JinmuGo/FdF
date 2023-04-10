/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:14:46 by jgo               #+#    #+#             */
/*   Updated: 2023/04/10 14:11:25 by jgo              ###   ########.fr       */
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

int	main(int ac, char **av)
{
	const char	*path = av[1];
	const int	init_fd = open(path, O_RDONLY);
	t_meta		meta;

	input_error_handler(ac, init_fd);
	input_process(&meta.map, path, init_fd);
	init_metadata(&meta);
	draw_process(&meta, FT_TRUE);
	hooks(&meta);
	mlx_loop(meta.mlx.mlx);
	free(meta.map.dot);
	free(meta.map.name);
	return (EXIT_SUCCESS);
}
