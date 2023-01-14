/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mod_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:28:51 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 17:49:12 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "declaration_bonus.h"
#include "utils_bonus.h"

/**
 * @brief 
 * 
 * @param value 
 * @param iend 
 * @param fstart 
 * @param fend 
 * 
 * map(value, istart, iend, fstart, fend)
        return (fstart +(fend - fstart) * ((value - istart) / (iend - istart))
 * @return float 
 */
float	mapping(int value, int iend, float fstart, float fend)
{
	return (fstart + (fend - fstart) * ((float)(value) / (iend)));
}

int	get_radius(t_map *map, t_dot dot)
{
	const int	min_z = map->min_z;
	const int	max_z = map->max.axis[Z];
	const float	r = get_ratio(min_z, dot.axis[Z], max_z);

	if (map->max.axis[X] > map->max.axis[Y])
		return (lerp(map->max.axis[Y], map->max.axis[X], r));
	else
		return (lerp(map->max.axis[X], map->max.axis[Y], r));
}

/**
 * @brief flat to sphere
 * @link https://www.themathdoctors.org/making-a-sphere-from-flat-material/
 * @link https://m.blog.naver.com/junhyuk7272/221675164093
 * @link https://42born2code.slack.com/archives/CN9RHKQHW/p1669804421641049
 * 
 * @param meta 
 * @param projection 
 */
void	draw_planet(t_map *map, t_dot *projection, int idx)
{
	float	angle[2];
	int		axis[2];
	float	radius;

	axis[X] = 0;
	while (axis[X] < map->max.axis[X])
	{
		axis[Y] = 0;
		angle[LON] = mapping(axis[X], map->max.axis[X], -M_PI, M_PI);
		while (axis[Y] < map->max.axis[Y])
		{
			idx = map->max.axis[X] * axis[Y] + axis[X];
			angle[LAT] = mapping(axis[Y], map->max.axis[Y], \
				-M_PI / 2, M_PI / 2);
			radius = get_radius(map, projection[idx]);
			projection[idx].axis[X] = (radius + projection[idx].axis[Z]) \
				* cos(angle[LAT]) * cos(angle[LON]);
			projection[idx].axis[Y] = (radius + projection[idx].axis[Z]) \
				* cos(angle[LAT]) * sin(angle[LON]);
			projection[idx].axis[Z] = (radius + projection[idx].axis[Z]) \
				* sin(angle[LAT]);
			axis[Y]++;
		}
		axis[X]++;
	}
}
