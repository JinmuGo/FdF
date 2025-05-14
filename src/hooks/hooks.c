/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:48:38 by jgo               #+#    #+#             */
/*   Updated: 2023/05/13 19:32:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "hooks.h"
#include "draw.h"
#include "utils.h"
#include "event.h"
#include "key_map.h"

int	rotate_planet(t_meta *meta)
{
	if (!meta->key.rotate)
		return (0);
	if (meta->key.shift)
		meta->map.angle[Y] = rotate_angle(meta->map.angle[Y], 1.5);
	else
		meta->map.angle[Y] = rotate_angle(meta->map.angle[Y], -1.5);
	draw_process(meta, false);
	return (0);
}

int	key_release(int key, t_meta *meta)
{
	if (key == KEY_SHIFT)
		meta->key.shift = false;
	return (0);
}

void	hooks(t_meta *meta)
{
	mlx_hook(meta->mlx.win, KEY_PRESS, 0, key_press, meta);
	mlx_hook(meta->mlx.win, KEY_RELEASE, 0, key_release, meta);
	mlx_hook(meta->mlx.win, MOUSE_PRESS, 0, mouse_press, meta);
	mlx_hook(meta->mlx.win, MOUSE_RELEASE, 0, mouse_release, meta);
	mlx_hook(meta->mlx.win, MOTION_NOTIFY, 0, mouse_move, meta);
	mlx_hook(meta->mlx.win, DESTROY_NOTIFY, 0, success_terminate_process, meta);
	mlx_loop_hook(meta->mlx.mlx, rotate_planet, meta);
}
