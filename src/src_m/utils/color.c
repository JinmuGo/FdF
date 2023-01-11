/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:14:03 by jgo               #+#    #+#             */
/*   Updated: 2023/01/11 16:17:34 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	lerp(int p1, int p2, float ratio)
{
	return ((int)(1 - ratio) * p1 + ratio * p2);
}

static float	get_ratio(int start, int mid, int end)
{
	if (start == end)
		return (1.0);
	return ((float)((mid - start) / (end - start)));
}

int	gradient(int start_color, int end_color, const float arr[3])
{
	float ratio;
	int rgb[3];
 
	if ((int)arr[0] == (int)arr[2])
		return (start_color);
	ratio = get_ratio(arr[0], arr[1], arr[2]);
	rgb[0] = lerp((start_color >> 16) & 0xFF, (end_color >> 16) & 0xFF, ratio);
	rgb[1] = lerp((start_color >> 8) & 0xFF, (end_color >> 8) & 0xFF, ratio);
	rgb[2] = lerp(start_color & 0xFF, end_color & 0xFF, ratio);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
