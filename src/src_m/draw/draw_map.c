/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:55:45 by jgo               #+#    #+#             */
/*   Updated: 2023/01/07 17:57:24 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "utils.h"
#include "color.h"

void	draw_dot(t_meta *meta, t_dot *dot)
{
	size_t	i;

	i = 0;
	while (i < meta->map.total_len)
	{
		my_dot_put(meta, dot[i].axis[X], dot[i].axis[Y], 0x76fa6a);
		i++;
	}
}

size_t	delta_init(t_dot delta, t_dot start, t_dot end)
{
	size_t	dis;

	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	delta.axis[Z] = end.axis[Z] - start.axis[Z];
	dis = sqrt((delta.axis[X] * delta.axis[X]) + (delta.axis[Y] * delta.axis[Y]));
	delta.axis[X] /= dis;
	delta.axis[Y] /= dis;
	delta.axis[Z] /= dis;
	return (dis);
}

void	draw_dot_between(t_meta *meta, t_dot start, t_dot end)
{
	t_dot	delta;
	t_dot	index;
	size_t	len;
	
	len = delta_init(delta, start, end);
	if (invalid_dot(start.axis[X], start.axis[Y]) && invalid_dot(end.axis[X], end.axis[Y]))
		return ;
	index = start;
	while (len)
	{
		index.color = gradient(start.color, end.color, get_color_array(start.axis[Z], index.axis[Z], end.axis[Z]));
		my_dot_put(meta, index.axis[X], index.axis[Y], index.color);
		index.axis[X] += delta.axis[X];
		index.axis[Y] += delta.axis[Y];
		index.axis[Z] += delta.axis[Z];
		len--;
	}
}

void	draw_line(t_meta *meta, t_dot *projection)
{
	size_t	i;

	i = 0;
	while (i < meta->map.total_len)
	{
		if (projection[i].painted)
		{
			if ((i + 1) % (size_t)meta->map.max.axis[X] != 0)
			{
				draw_dot_between(meta, projection[i], projection[i + 1]);
			}
			if ((i / (int)meta->map.max.axis[X]) != (meta->map.max.axis[Y] - 1))
				draw_dot_between(meta, projection[i], projection[i + (int)meta->map.max.axis[X]]);
		}
		i++;
	}
}

void draw(t_meta *meta, t_dot *projection, t_bool init)
{
	if (init)
    	get_proper_scale(meta, projection);
	if (meta->map.key.dot)
		draw_dot(meta, projection);
	if (meta->map.key.line)
    	draw_line(meta, projection);
}

