/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:55:45 by jgo               #+#    #+#             */
/*   Updated: 2023/05/13 19:32:35 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration_bonus.h"
#include "utils_bonus.h"
#include "color_bonus.h"
#include "error_bonus.h"
#include "draw_bonus.h"

void	draw_dot(t_meta *meta, t_dot *dot)
{
	int	i;

	i = 0;
	while (i < meta->map.total_len)
	{
		my_dot_put(meta, dot[i].axis[X], dot[i].axis[Y], dot[i].color);
		i++;
	}
}

int	delta_init(t_dot *delta, t_dot start, t_dot end)
{
	int	dis;

	delta->axis[X] = end.axis[X] - start.axis[X];
	delta->axis[Y] = end.axis[Y] - start.axis[Y];
	delta->axis[Z] = end.axis[Z] - start.axis[Z];
	dis = sqrt((delta->axis[X] * delta->axis[X]) + \
		(delta->axis[Y] * delta->axis[Y]));
	delta->axis[X] /= dis;
	delta->axis[Y] /= dis;
	delta->axis[Z] /= dis;
	return (dis);
}

void	draw_line(t_meta *meta, t_dot *projection, int i)
{
	while (++i < meta->map.total_len)
	{
		if (projection[i].painted)
		{
			if ((i + 1) % (int)meta->map.max.axis[X])
				draw_dot_between(meta, projection[i], projection[i + 1]);
			if ((i / (int)meta->map.max.axis[X]) != (meta->map.max.axis[Y] - 1))
			{
				draw_dot_between(meta, projection[i], \
					projection[i + (int)meta->map.max.axis[X]]);
				if (meta->key.extra_line && \
					(i + 1) % (int)meta->map.max.axis[X])
					draw_dot_between(meta, projection[i], \
						projection[i + (int)meta->map.max.axis[X] + 1]);
				if (meta->key.extra_line2 && i % (int)meta->map.max.axis[X])
					draw_dot_between(meta, projection[i], \
						projection[i + (int)meta->map.max.axis[X] - 1]);
			}
			if (meta->key.planet && i % (int)meta->map.max.axis[X] == 0)
				draw_dot_between(meta, projection[i], \
					projection[i + (int)meta->map.max.axis[X] - 1]);
		}
	}
}

void	draw_axis(t_meta *meta)
{
	t_dot	*axis_projection;
	int		i;

	axis_projection = malloc(AXIS_SIZE * sizeof(t_dot));
	allocate_error_handler(axis_projection);
	copy_dot(meta->map.axis, axis_projection, AXIS_SIZE);
	edit_map(meta, axis_projection, AXIS_SIZE);
	i = 0;
	while (i < 6)
	{
		if (i < 2)
			axis_projection[6].color = AXIS_X_COLOR;
		else if (2 <= i && i < 4)
			axis_projection[6].color = AXIS_Y_COLOR;
		else
			axis_projection[6].color = AXIS_Z_COLOR;
		draw_dot_between(meta, axis_projection[6], axis_projection[i]);
		i++;
	}
	free(axis_projection);
}

void	draw(t_meta *meta, t_dot *projection, bool init)
{
	if (init)
		get_proper_scale(meta, projection);
	if (meta->key.dot)
		draw_dot(meta, projection);
	if (meta->key.line)
		draw_line(meta, projection, -1);
	if (meta->key.axis)
		draw_axis(meta);
}
