/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:28:51 by jgo               #+#    #+#             */
/*   Updated: 2022/12/28 19:29:18 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"

void	spherize(t_map *map, t_dot *points)
{
	int	i;
	int	rad[3];

	rad[X] = map->ang[X] * M_PI / 180;
	rad[Y] = map->ang[Y] * M_PI / 180;
	rad[Z] = map->ang[Z] * M_PI / 180;
	i = 0;
	while (i < map->len)
	{
		points[i].axis[X] = (map->radius + points[i].axis[Z]) * \
		cos(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].axis[Y] = (map->radius + points[i].axis[Z]) * \
		sin(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].axis[Z] = (map->radius + points[i].axis[Z]) * \
		cos(points[i].polar[LAT]);
		i++;
	}
}