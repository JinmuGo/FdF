/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:01:34 by jgo               #+#    #+#             */
/*   Updated: 2023/01/13 16:39:52 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"
#include "color.h"
#include "utils.h"
#include "error.h"

t_bool	invalid_dot(int x, int y)
{
	if (x < 0 || x > WIN_WIDTH)
		return (TRUE);
	if (y < 0 || y > WIN_HEIGHT)
		return (TRUE);
	return (FALSE);
}

int	lerp(int p1, int p2, float ratio)
{
	return ((float)(1 - ratio) * p1 + ratio * p2);
}

float	get_ratio(int min, int mid, int max)
{
	if (min == max)
		return (1.0f);
	return ((float)(mid - min) / (max - min));
}

void	my_dot_put(t_meta *meta, int x, int y, int color)
{
	int offset;
	int alpha;

	if (invalid_dot(x, y))
		return ;
	offset = y * meta->img.line_length + x * 4;
	alpha = 1;
	set_color(&meta->img.addr[offset], meta->img.endian, get_color(meta, color), alpha);
}
