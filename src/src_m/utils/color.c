/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:14:03 by jgo               #+#    #+#             */
/*   Updated: 2023/01/13 15:33:55 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static int	lerp(int p1, int p2, float ratio)
{
	return ((float)(1 - ratio) * p1 + ratio * p2);
}

static float	get_ratio(int min, int mid, int max)
{
	if (min == max)
		return (1.0f);
	return ((float)(mid - min) / (max - min));
}

int	gradient(int start_color, int end_color, const float arr[3])
{
	float ratio;
	int rgb[3];
 
	if ((int)arr[MIN] == (int)arr[MAX])
		return (start_color);
	ratio = get_ratio(arr[MIN], arr[MID], arr[MAX]);
	rgb[MIN] = lerp((start_color >> 16) & 0xFF, (end_color >> 16) & 0xFF, ratio);
	rgb[MID] = lerp((start_color >> 8) & 0xFF, (end_color >> 8) & 0xFF, ratio);
	rgb[MAX] = lerp(start_color & 0xFF, end_color & 0xFF, ratio);
	return ((rgb[MIN] << 16) | (rgb[MID] << 8) | rgb[MAX]);
}
