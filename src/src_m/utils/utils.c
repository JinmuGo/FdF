/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:02:08 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 16:46:55 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"
#include "color.h"
#include "hooks.h"

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

float	rotate_angle(float angle, float value)
{
	angle += value;
	if (angle < 0)
		angle += 360;
	if (angle >= 360)
		angle -= 360;
	return (angle);
}

int	init_color(t_map *map, t_dot dot)
{
	const t_color	color = map->color;
	float			color_arr[3];

	color_arr[MIN] = map->min_z;
	color_arr[MID] = dot.axis[Z];
	color_arr[MAX] = map->max.axis[Z];
	if (color_arr[MID] == 0)
		return (color.land_color);
	if (color_arr[MID] == color_arr[MAX])
		return (color.peak_color);
	if (color_arr[MIN] == color_arr[MID] && color_arr[MIN] != 0)
		return (color.bottom_color);
	if (color_arr[MID] > 0)
		return (gradient(color.land_color, color.peak_color, color_arr));
	return (gradient(color.peak_color, color.land_color, color_arr));
}

static void	init_axis(t_dot mid, t_dot *axis_arr)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	j = 0;
	sign = 1;
	while (i < AXIS_SIZE - 1)
	{
		ft_bzero(axis_arr[i].axis, sizeof(float) * 3);
		if (i < 2)
			axis_arr[i].color = AXIS_X_COLOR;
		else if (2 <= i && i < 4)
			axis_arr[i].color = AXIS_Y_COLOR;
		else
			axis_arr[i].color = AXIS_Z_COLOR;
		axis_arr[i].axis[j] = AXIS_OFFSET * sign;
		if (i % 2)
			j++;
		sign *= -1;
		i++;
	}
	axis_arr[6] = mid;
}

void	init_metadata(t_meta *meta)
{
	meta->mlx.mlx = mlx_init();
	meta->mlx.win = mlx_new_window(meta->mlx.mlx, \
		WIN_WIDTH, WIN_HEIGHT, "jgo FdF");
	meta->img.img = mlx_new_image(meta->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	meta->img.addr = mlx_get_data_addr(meta->img.img, \
		&meta->img.bits_per_pixel, &meta->img.line_length, &meta->img.endian);
	meta->map.ratio = meta->map.max.axis[Z] / meta->map.max.axis[X];
	if (meta->map.ratio > 0.5)
		meta->map.z_divisor = meta->map.ratio * 20;
	else
		meta->map.z_divisor = 1;
	init_axis(meta->map.mid, meta->map.axis);
	hook_init(meta);
}
