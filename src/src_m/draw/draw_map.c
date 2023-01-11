/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:55:45 by jgo               #+#    #+#             */
/*   Updated: 2023/01/11 17:01:59 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "utils.h"
#include "color.h"
#include "error.h"
#include "draw.h"

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
	dis = sqrt((delta->axis[X] * delta->axis[X]) + (delta->axis[Y] * delta->axis[Y]));
	delta->axis[X] /= dis;
	delta->axis[Y] /= dis;
	delta->axis[Z] /= dis;
	return (dis);
}

void	draw_dot_between(t_meta *meta, t_dot start, t_dot end)
{
	t_dot	delta;
	t_dot	index;
	int		len;
	float	color_arr[3];

	len = delta_init(&delta, start, end);
	index = start;
	color_arr[0] = start.axis[Z];
	color_arr[1] = index.axis[Z];
	color_arr[2] = end.axis[Z];
	while (len)
	{
		if(invalid_dot(index.axis[X], index.axis[Y]))
			return ;
		index.color = gradient(start.color, end.color, color_arr);
		my_dot_put(meta, index.axis[X], index.axis[Y], index.color);
		index.axis[X] += delta.axis[X];
		index.axis[Y] += delta.axis[Y];
		color_arr[1] += delta.axis[Z];
		len--;
	}
}

void	draw_line(t_meta *meta, t_dot *projection)
{
	int	i;

	i = 0;
	while (i < meta->map.total_len)
	{
		if (projection[i].painted)
		{
			if ((i + 1) % (int)meta->map.max.axis[X] != 0)
			{
				draw_dot_between(meta, projection[i], projection[i + 1]);
			}
			if ((i / (int)meta->map.max.axis[X]) != (meta->map.max.axis[Y] - 1))
				draw_dot_between(meta, projection[i], projection[i + (int)meta->map.max.axis[X]]);
		}
		i++;
	}
}

void	draw_axis(t_meta *meta)
{
	t_dot	*axis_projection;
	int	i;
	
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

void draw(t_meta *meta, t_dot *projection, t_bool init)
{
	if (init)
    	get_proper_scale(meta, projection);
	if (meta->key.dot)
		draw_dot(meta, projection);
	if (meta->key.line)
    	draw_line(meta, projection);
	if (meta->key.axis)
		draw_axis(meta);
}

