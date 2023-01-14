/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:33 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 16:40:01 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"
#include "draw.h"
#include "utils.h"

int	mouse_press(int button, int x, int y, t_meta *meta)
{
	x++;
	y++;
	if (button == 1 && meta->mouse.left_click == FALSE)
		meta->mouse.left_click = TRUE;
	if (button == 2 && meta->mouse.right_click == FALSE)
		meta->mouse.right_click = TRUE;
	if (button == 4)
	{
		if (meta->map.scale > 3)
		{
			meta->map.scale /= 1.5;
			draw_process(meta, FALSE);
		}
	}
	if (button == 5)
	{
		meta->map.scale *= 1.5;
		draw_process(meta, FALSE);
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_meta *meta)
{
	x++;
	y++;
	if (button == 1 && meta->mouse.left_click)
		meta->mouse.left_click = FALSE;
	if (button == 2 && meta->mouse.right_click)
		meta->mouse.right_click = FALSE;
	return (0);
}

int	mouse_move(int x, int y, t_meta *meta)
{
	if (x > WIN_WIDTH || x < 0 || y > WIN_HEIGHT || y < 0)
		return (0);
	if (meta->mouse.left_click)
	{
		meta->map.angle[X] = rotate_angle(meta->map.angle[X], \
			((int)meta->mouse.prev.axis[Y] - y));
		meta->map.angle[Y] = rotate_angle(meta->map.angle[Y], \
			-((int)meta->mouse.prev.axis[X] - x));
		draw_process(meta, FALSE);
	}
	if (meta->mouse.right_click)
	{
		meta->map.src.axis[X] -= ((int)meta->mouse.prev.axis[X] - x);
		meta->map.src.axis[Y] -= ((int)meta->mouse.prev.axis[Y] - y);
		meta->map.src.axis[Z] = 0;
		draw_process(meta, FALSE);
	}
	meta->mouse.prev.axis[X] = x;
	meta->mouse.prev.axis[Y] = y;
	return (0);
}
