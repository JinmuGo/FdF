/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:14:03 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 17:49:12 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration_bonus.h"
#include "utils_bonus.h"
#include "color_bonus.h"

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

int	gradient(int start_color, int end_color, const float arr[3])
{
	float	ratio;
	int		rgb[3];

	if ((int)arr[MIN] == (int)arr[MAX])
		return (start_color);
	ratio = get_ratio(arr[MIN], arr[MID], arr[MAX]);
	rgb[MIN] = lerp((start_color >> 16) & 0xFF, \
		(end_color >> 16) & 0xFF, ratio);
	rgb[MID] = lerp((start_color >> 8) & 0xFF, (end_color >> 8) & 0xFF, ratio);
	rgb[MAX] = lerp(start_color & 0xFF, end_color & 0xFF, ratio);
	return ((rgb[MIN] << 16) | (rgb[MID] << 8) | rgb[MAX]);
}
