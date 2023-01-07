/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:33 by jgo               #+#    #+#             */
/*   Updated: 2023/01/07 18:58:53 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"
#include "draw.h"
#include "utils.h"

int mouse_press(int button, int x, int y, t_meta *meta)
{
    if (button == 1)
	{
		meta->mouse.left_click = TRUE;
		meta->mouse.left.axis[X] = x;
		meta->mouse.left.axis[Y] = y;
	}
	if (button == 2)
	{
		meta->mouse.right_click = TRUE;
		meta->mouse.right.axis[X] = x;
		meta->mouse.right.axis[Y] = y;
	}	
	if (button == 4)
	{
		if (meta->map.scale > 2)
			meta->map.scale /= 1.5;
	}
	if (button == 5)
		meta->map.scale *= 1.5;
    draw_process(meta, FALSE);
    return (0);
};

int mouse_release(int button, int x, int y, t_meta *meta)
{
	x++;
	y++;
    if (button == 1)
		meta->mouse.left_click = FALSE;
	if (button == 2)
		meta->mouse.right_click = FALSE;
    return (0);
}

int mouse_move(int x, int y, t_meta *meta)
{
	if (x > WIN_WIDTH || x < 0 || y > WIN_HEIGHT || y < 0)
		return (0);
	if (meta->mouse.left_click)
	{
		meta->map.angle[X] = rotate_angle(meta->map.angle[X], ((int)meta->mouse.left.axis[X] - x));
		meta->map.angle[Y] = rotate_angle(meta->map.angle[Y], ((int)meta->mouse.left.axis[Y] - y));
		meta->mouse.left.axis[X] = x;
		meta->mouse.left.axis[Y] = y;
		draw_process(meta, FALSE);
	}
    if (meta->mouse.right_click)
	{
		meta->map.src.axis[X] -= ((int)meta->mouse.right.axis[X] - x);
		meta->map.src.axis[Y] -= ((int)meta->mouse.right.axis[Y] - y);
		meta->map.src.axis[Z] = 0;
		meta->mouse.right.axis[X] = x;
		meta->mouse.right.axis[Y] = y;
		draw_process(meta, FALSE);
	}
    return (0);
}