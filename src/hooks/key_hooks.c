/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:22 by jgo               #+#    #+#             */
/*   Updated: 2023/05/13 19:32:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "key_map.h"
#include "hooks.h"
#include "utils.h"
#include "draw.h"

void	key_rotate(int key, t_meta *meta)
{
	const int	angle = 10;

	if (key == KEY_Z)
		meta->map.angle[X] = rotate_angle(meta->map.angle[X], angle);
	if (key == KEY_X)
		meta->map.angle[X] = rotate_angle(meta->map.angle[X], -angle);
	if (key == KEY_A)
		meta->map.angle[Y] = rotate_angle(meta->map.angle[Y], angle);
	if (key == KEY_S)
		meta->map.angle[Y] = rotate_angle(meta->map.angle[Y], -angle);
	if (key == KEY_Q)
		meta->map.angle[Z] = rotate_angle(meta->map.angle[Z], angle);
	if (key == KEY_W)
		meta->map.angle[Z] = rotate_angle(meta->map.angle[Z], -angle);
}

void	key_option(int key, t_meta *meta)
{
	if (key == KEY_1)
		meta->key.dot = !meta->key.dot;
	if (key == KEY_2)
		meta->key.line = !meta->key.line;
	if (key == KEY_3)
		meta->key.axis = !meta->key.axis;
	if (key == KEY_P)
	{
		meta->map.angle[Z] = 0;
		meta->key.planet = !meta->key.planet;
	}
	if (key == KEY_E)
		meta->key.extra_line = !meta->key.extra_line;
	if (key == KEY_D)
		meta->key.extra_line2 = !meta->key.extra_line2;
	if (key == KEY_PLUS)
		meta->map.z_divisor /= 1.5;
	if (key == KEY_MINUS)
		meta->map.z_divisor *= 1.5;
}

void	key_view(int key, t_meta *meta)
{
	if (key == KEY_I && !meta->key.planet)
	{
		meta->map.angle[X] = 30;
		meta->map.angle[Y] = 330;
		meta->map.angle[Z] = 30;
	}
	if (key == KEY_V)
	{
		meta->key.planet = false;
		meta->map.angle[X] = 90;
		meta->map.angle[Y] = 0;
		meta->map.angle[Z] = 0;
	}
	if (key == KEY_R)
		meta->key.rotate = !meta->key.rotate;
}

void	key_scale(int key, t_meta *meta)
{
	if (key == KEY_J)
		meta->map.scale /= 1.5;
	if (key == KEY_K)
		meta->map.scale *= 1.5;
}

int	key_press(int key, t_meta *meta)
{
	if (key == KEY_ESC)
		success_terminate_process(meta);
	if (key == KEY_SHIFT)
		meta->key.shift = true;
	if (key == KEY_F && !meta->key.planet)
	{
		draw_process(meta, true);
		return (0);
	}
	key_rotate(key, meta);
	key_option(key, meta);
	key_view(key, meta);
	key_scale(key, meta);
	draw_process(meta, false);
	return (0);
}
