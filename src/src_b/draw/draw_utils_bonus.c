/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:01:34 by jgo               #+#    #+#             */
/*   Updated: 2023/04/10 14:11:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "declaration_bonus.h"
#include "color_bonus.h"
#include "utils_bonus.h"
#include "error_bonus.h"
#include "draw_bonus.h"

t_bool	invalid_dot(int x, int y)
{
	if (x < 0 || x > WIN_WIDTH)
		return (FT_TRUE);
	if (y < 0 || y > WIN_HEIGHT)
		return (FT_TRUE);
	return (FT_FALSE);
}

int	lerp(int p1, int p2, float ratio)
{
	return ((float)(1 - ratio)*p1 + ratio * p2);
}

float	get_ratio(int min, int mid, int max)
{
	if (min == max)
		return (1.0f);
	return ((float)(mid - min) / (max - min));
}

void	my_dot_put(t_meta *meta, int x, int y, int color)
{
	int	offset;
	int	alpha;

	if (invalid_dot(x, y))
		return ;
	offset = y * meta->img.line_length + x * 4;
	alpha = 1;
	set_color(&meta->img.addr[offset], \
		meta->img.endian, get_color(meta, color), alpha);
}

void	draw_dot_between(t_meta *meta, t_dot start, t_dot end)
{
	t_dot	delta;
	t_dot	index;
	int		len;
	float	color_arr[3];

	len = delta_init(&delta, start, end);
	index = start;
	color_arr[MIN] = start.axis[Z];
	color_arr[MID] = index.axis[Z];
	color_arr[MAX] = end.axis[Z];
	while (len)
	{
		if (invalid_dot(index.axis[X], index.axis[Y]))
			return ;
		index.color = gradient(start.color, end.color, color_arr);
		my_dot_put(meta, index.axis[X], index.axis[Y], index.color);
		index.axis[X] += delta.axis[X];
		index.axis[Y] += delta.axis[Y];
		color_arr[1] += delta.axis[Z];
		len--;
	}
}
