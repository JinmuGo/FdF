/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:51:24 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 16:59:03 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "matrix.h"
#include "draw.h"

void	scale_map(t_dot *dot, int scale, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dot[i].axis[X] *= scale;
		dot[i].axis[Y] *= scale;
		dot[i].axis[Z] *= scale;
		i++;
	}
}

void	move_map(t_dot *dot, t_dot src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dot[i].axis[X] += src.axis[X];
		dot[i].axis[Y] += src.axis[Y];
		dot[i].axis[Z] += src.axis[Z];
		i++;
	}
}

void	rotate_map(t_dot *projection, float angle[3], int len)
{
	int		i;
	float	matrix3[3][3];
	float	rad3[3];

	matrix3_init(matrix3);
	radian_init(rad3, angle);
	matrix3[0][0] = cos(rad3[Z]) * cos(rad3[Y]);
	matrix3[0][1] = cos(rad3[Z]) * sin(rad3[Y]) * sin(rad3[X]) - \
		sin(rad3[Z]) * cos(rad3[X]);
	matrix3[0][2] = cos(rad3[Z]) * sin(rad3[Y]) * cos(rad3[X]) - \
		sin(rad3[Z]) * sin(rad3[X]);
	matrix3[1][0] = sin(rad3[Z]) * cos(rad3[Y]);
	matrix3[1][1] = sin(rad3[Z]) * sin(rad3[Y]) * sin(rad3[X]) + \
		cos(rad3[Z]) * cos(rad3[X]);
	matrix3[1][2] = sin(rad3[Z]) * sin(rad3[Y]) * cos(rad3[X]) - \
		cos(rad3[Z]) * sin(rad3[X]);
	matrix3[2][0] = -sin(rad3[Y]);
	matrix3[2][1] = cos(rad3[Y]) * sin(rad3[Z]);
	matrix3[2][2] = cos(rad3[Y]) * cos(rad3[Z]);
	i = 0;
	while (i < len)
	{
		projection[i] = mul3_mat(matrix3, projection[i]);
		i++;
	}
}

void	z_divide(t_dot *projection, float divisor, int len)
{
	int	i;

	if (divisor == 1)
		return ;
	i = 0;
	while (i < len)
	{
		projection[i].axis[Z] /= divisor;
		i++;
	}
}

void	edit_map(t_meta *meta, t_dot *projection, int len)
{
	if (len != AXIS_SIZE)
		z_divide(projection, meta->map.z_divisor, len);
	if (meta->key.planet && len != AXIS_SIZE)
		draw_planet(&meta->map, projection, 0);
	scale_map(projection, meta->map.scale, len);
	rotate_map(projection, meta->map.angle, len);
	move_map(projection, meta->map.src, len);
}
