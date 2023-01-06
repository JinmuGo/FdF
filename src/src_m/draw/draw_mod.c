/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:28:51 by jgo               #+#    #+#             */
/*   Updated: 2023/01/06 15:41:22 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"

void	spherize(t_map *map, t_dot *points)
{
	int	i;
	int	rad[3];

	rad[X] = map->angle[X] * M_PI / 180;
	rad[Y] = map->angle[Y] * M_PI / 180;
	rad[Z] = map->angle[Z] * M_PI / 180;
	i = 0;
	while (i < map->total_len)
	{
		// points[i].axis[X] = (map->radius + points[i].axis[Z]) * \
		// cos(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		// points[i].axis[Y] = (map->radius + points[i].axis[Z]) * \
		// sin(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		// points[i].axis[Z] = (map->radius + points[i].axis[Z]) * \
		// cos(points[i].polar[LAT]);
		i++;
	}
}