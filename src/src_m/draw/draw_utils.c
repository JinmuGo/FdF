/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:01:34 by jgo               #+#    #+#             */
/*   Updated: 2023/01/13 15:52:32 by jgo              ###   ########.fr       */
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

int	get_color(t_meta *meta, int color)
{	
	if (meta->img.bits_per_pixel != 32)
		color = mlx_get_color_value(meta->mlx.mlx, color);
	return (color);
}

void	set_color(char *offset, int endian, int color, int alpha)
{
	if (endian)
	{
		offset[0] = alpha;
		offset[1] = (color >> 16) & 0xFF;
		offset[2] = (color >> 8) & 0xFF;
		offset[3] = (color) & 0xFF;
	}
	else
	{
		offset[0] = (color) & 0xFF;
		offset[1] = (color >> 8) & 0xFF;
		offset[2] = (color >> 16) & 0xFF;
		offset[3] = alpha;
	}
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
