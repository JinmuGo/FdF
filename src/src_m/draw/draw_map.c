/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:55:45 by jgo               #+#    #+#             */
/*   Updated: 2023/01/04 16:00:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "utils.h"

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

void	draw_dot_between(t_meta *meta, t_dot start, t_dot end)
{
	t_dot	delta;
	t_dot	index;
	size_t	len;
	size_t	dis;
	
	if (invalid_dot(start.axis[X], start.axis[Y]) && invalid_dot(end.axis[X], end.axis[Y]))
		return ;
	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	dis = sqrt((delta.axis[X] * delta.axis[X]) + (delta.axis[Y] * delta.axis[Y]));
	len = dis;
	delta.axis[X] /= dis;
	delta.axis[Y] /= dis;
	index.axis[X] = start.axis[X];
	index.axis[Y] = start.axis[Y];
	while (len)
	{
		// pixel.color = gradient(start.color, end.color, len, len - pixels); grdient추가  예정 선형  보간법
		my_dot_put(meta, index.axis[X], index.axis[Y], 0xffffff);
		index.axis[X] += delta.axis[X];
		index.axis[Y] += delta.axis[Y];
		len--;
	}
}

void	draw_line(t_meta *meta, t_dot *projection)
{
	size_t	i;

	i = 0;
	print_dot(projection, meta->map.total_len);
	printf("max width: %f\n", meta->map.max.axis[X]);
	printf("max width: %f\n", meta->map.max.axis[Y]);
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

void draw(t_meta *meta, t_dot *projection)
{
    get_proper_scale(meta, projection);
    draw_line(meta, projection);
    draw_dot(meta, projection);
}

